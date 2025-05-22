#include "user_gui/tangerine.h"
#include "ui_tangerine.h"

#include <QPixmap>
#include <QFileInfo> 
#include <QDir>
#include <QDebug>
#include <QMouseEvent>
#include <QMessageBox>
#include <iostream>
#include <QThread>
#include <QTimer>
#include <QDialog>
#include <QRegularExpressionValidator>
#include "user_gui/image_button.h"
#include "user_gui/circular_progressbar.h"
#include "user_gui/battery_widget.h"
#include "user_gui/recording_dialog.h"

/****************************************************** 
  Using
*******************************************************/
using PoseStamped = geometry_msgs::msg::PoseStamped;
using OccupancyGrid = nav_msgs::msg::OccupancyGrid;
using HandleCommand = tangerbot_msgs::srv::HandleCommand;
using CallState = tangerbot_msgs::msg::CallState;
using RobotState = tangerbot_msgs::msg::RobotState;
using SignUp = tangerbot_msgs::srv::SignUp;
using DecodedVoice = tangerbot_msgs::msg::DecodedVoice;
using HandleRawVoice = tangerbot_msgs::srv::HandleRawVoice;

using namespace std::placeholders;
using namespace std::chrono_literals;

Tangerine::Tangerine(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Tangerine),
  map_received_(false)
{
    using namespace std::placeholders;
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);
    ui->robot_widget->setCurrentIndex(1);
    called_robot = true;

    /**********************************************
     * * Initialize ROS2 Node
    ***********************************************/
    if (!rclcpp::ok()) {
        rclcpp::init(0, nullptr);
    }
    node_ = rclcpp::Node::make_shared("tangerine_gui_node");

    /**********************************************
     * * Initialize ROS2 Variables
    ***********************************************/

    handle_command_client = node_->create_client<HandleCommand>("handle_command");
    call_state_sub = node_->create_subscription<CallState>(
      "/call_state", 10, std::bind(&Tangerine::call_state_callback, this, _1)
    );
    robot_state_sub = node_->create_subscription<RobotState>(
      "robot_state", 10, std::bind(&Tangerine::robot_state_callback, this, _1));
    signup_client = node_->create_client<SignUp>("sign_up");
    handle_raw_voice_client = node_->create_client<HandleRawVoice>("handle_raw_voice");


    goal_pub_ = node_->create_publisher<PoseStamped>("/goal_pose", 10);
    decoded_voice_pub = node_->create_publisher<DecodedVoice>("decoded_voice", 10);

    /**********************************************
     * * Load the main image for the intro page
    ***********************************************/
    QString path = QDir::current().absolutePath();
    QString imagePath = path + "/src/gui/user_gui/ui/mainPic.png";
    //qDebug() << "Image Path: " << imagePath;
    QPixmap pixmap(imagePath); 
    
    ui->label_introPic->setPixmap(pixmap);
    ui->label_introPic->setScaledContents(true);
    ui->label_introPic->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    // Loading GIF for call request
    loading = new QMovie(path + "/src/gui/user_gui/image/Loading_icon.gif");
    ui->label_loading->setMovie(loading);
    ui->label_loading->setScaledContents(true);
    
    // Section selector
    ImageButton *img_btn = new ImageButton(this, ui->robot_page_frame);
    QVBoxLayout *layout = new QVBoxLayout(ui->robot_page_frame);
    layout->addWidget(img_btn);
    ui->robot_page_frame->setLayout(layout);
    connect(img_btn, &ImageButton::call_confirmed, this, &Tangerine::handle_selection);
    
    // Workload progressbar
    circular_progressbar = new CircularProgressBar(ui->progressbar_frame);
    QVBoxLayout *progressbar_widget = new QVBoxLayout(ui->progressbar_frame);
    progressbar_widget->addWidget(circular_progressbar);
    circular_progressbar->set_margin(20);
    circular_progressbar->set_percentage(50);

    // Robot battery circular progressbar
    battery_circular_progressbar = new CircularProgressBar(ui->battery_circular_progressbar_frame);
    QVBoxLayout *battery_progressbar_widget2 = new QVBoxLayout(ui->battery_circular_progressbar_frame);
    battery_progressbar_widget2->addWidget(battery_circular_progressbar);
    battery_circular_progressbar->set_color(QColor(255, 255, 255), QColor(0x00, 0xFF, 0x7F));
    battery_circular_progressbar->set_margin(20);
    battery_circular_progressbar->set_percentage(85);

    // Robot batter widget
    battery_widget = new BatteryWidget(ui->battery_widget_frame);
    QVBoxLayout *battery_progressbar_widget1 = new QVBoxLayout(ui->battery_widget_frame);
    battery_progressbar_widget1->addWidget(battery_widget);
    battery_widget->set_percentage(85);

    /**********************************************
     * * Navigate to Page
    ***********************************************/

    // In Main tab
    connect(ui->btn_signin, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(2);});
    connect(ui->btn_signup, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->btn_complete, &QPushButton::clicked, this, [=]() {
      request_signup();
    });
    connect(ui->btn_signinMain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

    connect(ui->btn_mmain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});
    connect(ui->btn_rmain, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentIndex(3);
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    connect(ui->btn_smain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

    // In Robot tab
    connect(ui->btn_mrobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});
    connect(ui->btn_rrobot, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentIndex(4);
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    connect(ui->btn_srobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});

    connect(ui->btn_vociecall, &QPushButton::clicked, this, [=]() {ui->robot_widget->setCurrentIndex(3);});

    connect(ui->btn_call, &QPushButton::clicked, this, [=]() {
      if (called_robot) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Cancel", "Are you sure Cancel calling robot?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
          // Cancel process
        } else {
          // None
        }
      }
        else 
        ui->robot_widget->setCurrentIndex(2);
    });

    connect(ui->btn_return, &QPushButton::clicked, this, [=]() {
      if (!robot_id.empty()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Cancel", "Are you sure return robot?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
          auto request = std::make_shared<HandleCommand::Request>();
          request->user_id = user_id;
          request->robot_id = robot_id;
          request->type = HandleCommand::Request::RETURN;
          RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service waiting");
          while (!handle_command_client->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
              RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
              return;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
          }
          auto future_result = handle_command_client->async_send_request(request);
          auto response = future_result.get();
          RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "%d", response);
          
          RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Handle command service success!");
          current_robottab_index = 0;
          ui->btn_call->setText("Call");
          ui->btn_call->setStyleSheet(
            QString("QPushButton {"
                    "background-color: rgba(42, 175, 223, 255);"
                    "border:10px;"
                    "color:black;"
                    "}"

                    "QPushButton:hover {"
                    "background-color: rgba(42, 175, 223, 200);"
                    "}")

          );
          called_robot = false;
          robot_id.clear();
          current_robottab_index = 0;
          ui->robot_widget->setCurrentIndex(0);
          
          
          
        } else {
          // None
        }
    }
    });

    connect(ui->btn_follow, &QPushButton::clicked, this, std::bind(&Tangerine::request_follwing, this));

    connect(ui->btn_record, &QPushButton::clicked, this, std::bind(&Tangerine::start_recording, this));

    // In Setting tab
    connect(ui->btn_msettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});
    connect(ui->btn_rsettings, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentIndex(5);
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    connect(ui->btn_ssettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});


    /**********************************************
     * * Signals
    ***********************************************/
    

    // Spin node
    QThread* rosThread = QThread::create([=]() {
    rclcpp::spin(node_);
    });
    rosThread->start();
}


// Destroyer
Tangerine::~Tangerine()
{
  delete ui;
  rclcpp::shutdown();
}

bool Tangerine::get_called_robot() {
  return called_robot;
}

/****************************************************** 
  Slots
*******************************************************/
void Tangerine::handle_selection(QString section) {
  called_robot = true;
  
  auto request = std::make_shared<HandleCommand::Request>();
  request->user_id = user_id;
  request->type = HandleCommand::Request::MOVETOSECTION;
  request->data = section.toStdString();
  int try_count = 0;
  
  while (!handle_command_client->wait_for_service(1s)) {
      if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return;
      }
      try_count++;
      if (try_count >= 5) {
        QMessageBox::warning(this, "Failed", "Can't request service!");
        return;
      }
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto future_result = handle_command_client->async_send_request(request);

  auto response = future_result.get();
  
  if (response->success)
  {
    RCLCPP_INFO(node_->get_logger(), "success");
    ui->robot_widget->setCurrentIndex(4);
    loading->start();
    ui->btn_call->setText("Cancel");
    ui->btn_call->setStyleSheet(
      QString("QPushButton {"
              "background-color: rgba(168, 168, 168, 255);"
              "color: black;"
              "}"
              "QPushButton:hover {"
              "background-color: rgba(168, 168, 168, 200);"
              "}")

    );
    return;
  } else {
    RCLCPP_ERROR(node_->get_logger(), "Failed to call service handle_command");
    QMessageBox::warning(this, "Failed", "Can't request service!");
    return;
  }
}

void Tangerine::process_audio_data(QByteArray audio_data) {
  auto request = std::make_shared<HandleRawVoice::Request>();
  request->user_id = user_id;
  request->data.data = std::vector<uint8_t>(audio_data.begin(), audio_data.end());
  auto future_result = handle_raw_voice_client->async_send_request(request);
  auto response = future_result.get();

  if (!response->text.empty()) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Check", "Are you sure this command?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
      auto msg = DecodedVoice();
      msg.user_id = user_id;
      msg.text = response->text;
      decoded_voice_pub->publish(msg);
    } 
  }
}

/****************************************************** 
  Callback
*******************************************************/
void Tangerine::call_state_callback(const CallState::SharedPtr msg) {
  RCLCPP_INFO(node_->get_logger(), "call state");
  if (!called_robot) return;
  int eta = msg->time_remaining;
  bool success = msg->success;
  bool done = msg->done;
  loading->stop();
  if (success) {
    if (done) {
      total_eta = -1;
      QTimer::singleShot(0, this, [=]() {
          ui->robot_widget->setCurrentIndex(1);
          robot_id = msg->robot_id;
          RCLCPP_INFO(node_->get_logger(), "%s is selected", robot_id.c_str());
      });
    } else {
      QTimer::singleShot(0, this, [=]() {
          ui->robot_widget->setCurrentIndex(5);
      });
      if (total_eta == -1 && eta > 0) {
        QTimer::singleShot(0, this, [=]() {
          total_eta = eta;
          ui->remaining_time->setMaximum(total_eta);
          RCLCPP_INFO(node_->get_logger(), "total eta: %d", total_eta);
          QString htmlText = QString(
            "<html><head/><body>"
            "<p align=\"center\">🩷</p>"
            "<p align=\"center\">We found the robot for you!</p>"
            "<p align=\"center\">Robot will arrive in <b>%1</b> seconds :)</p>"
            "</body></html>"
          ).arg(total_eta);
          ui->label_23->setText(htmlText);
        });
      } else {
        QTimer::singleShot(0, this, [=]() {
          if ((total_eta - ui->remaining_time->value()) - eta == 1) {
            ui->remaining_time->setValue(total_eta - eta);
            QString htmlText = QString(
              "<html><head/><body>"
              "<p align=\"center\">🩷</p>"
              "<p align=\"center\">We found the robot for you!</p>"
              "<p align=\"center\">Robot will arrive in <b>%1</b> seconds :)</p>"
              "</body></html>"
            ).arg(eta);
            ui->label_23->setText(htmlText);
          } 
          
          RCLCPP_INFO(node_->get_logger(), "total eta: %d", total_eta);
        });
      }
    }
  } else {
    QTimer::singleShot(0, this, [=]() {
      current_robottab_index = 0;
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    
  }
  
}

void Tangerine::robot_state_callback(const RobotState::SharedPtr msg) {
  auto robot_id = msg->robot_id;
  auto battery = msg->battery;
  if (robot_id == this->robot_id) {
    QTimer::singleShot(0, this, [=]() {
      battery_circular_progressbar->set_percentage(int(battery));
      battery_widget->set_percentage(int(battery));
    });
  }
}

/****************************************************** 
  Functions
*******************************************************/
std::pair<bool, std::string> Tangerine::check_signup_validation() {
  std::pair<bool, std::string> result;
  result.first = false;
  if (ui->input_name->text().isEmpty()) {
    result.second = "Fill Name";
    return result;
  }
  if (ui->input_birthday->text().isEmpty()) {
    result.second = "Fill Birthday";
    return result;
  } else {
    QRegularExpression rx("^19\\d{2}|20\\d{2}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01])$");
    QRegularExpressionMatch match = rx.match(ui->input_birthday->text());
    
    if (!match.hasMatch()) {
      result.second = "Birthday must be in YYYY-MM-DD format";
      return result;
    }
  }
  if (ui->input_number->text().isEmpty()) {
    result.second = "Fill Cell Number";
    return result;
  }
  if (ui->input_userid->text().isEmpty()) {
    result.second = "Fill User ID";
    return result;
  }
  if (ui->input_email->text().isEmpty()) {
    result.second = "Fill Email";
    return result;
  }
  if (ui->input_password->text().isEmpty()) {
    result.second = "Fill Password";
    return result;
  }
  result.first = true;
  return result;
}

//void Tangerine::clean_signup_info();

void Tangerine::request_signup() {
  auto check_result = check_signup_validation();
  if (!check_result.first) {
    QMessageBox::warning(this, "Invalid", QString::fromStdString(check_result.second));
    return;
  }
  auto request = std::make_shared<SignUp::Request>();
  request->name = ui->input_name->text().toStdString();
  request->birthday = ui->input_birthday->text().toStdString();
  request->cell_number = ui->input_number->text().toStdString();
  request->user_id = ui->input_userid->text().toStdString();
  request->email = ui->input_email->text().toStdString();
  request->password = ui->input_password->text().toStdString();
  signup_client->async_send_request(request, std::bind(&Tangerine::signup_response_callback, this, _1));
  RCLCPP_INFO(node_->get_logger(), "success");
}

void Tangerine::signup_response_callback(rclcpp::Client<SignUp>::SharedFuture future)
{
  auto response = future.get();
  QTimer::singleShot(0, this, [=]() {
    if (response->error_code == SignUp::Response::NONE) {
      QMessageBox::information(this, "Info", "Success Signup!");
    } else {
      QMessageBox::information(this, "Info", "Already Exist User ID");
    }
  
    ui->stackedWidget->setCurrentIndex(0);
  });
}

void Tangerine::request_follwing() {
  called_robot = true;
  if (!called_robot) return;

  QTimer::singleShot(0, this, [=]() {
    auto request = std::make_shared<HandleCommand::Request>();
    request->user_id = user_id;
    request->robot_id = robot_id;
    if (follow_mode == false) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Request Following");
      request->type = HandleCommand::Request::FOLLOWING;
      ui->btn_follow->setText("Stop");
    } else {
      request->type = HandleCommand::Request::STOP;
      ui->btn_follow->setText("Follow");
    }

    while (!handle_command_client->wait_for_service(1s)) {
      if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return;
      }
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    }

    auto future_result = handle_command_client->async_send_request(request);
    auto response = future_result.get();

    follow_mode = !follow_mode;
  });
}

void Tangerine::start_recording() {
  record_dialog = new RecordingDialog(this);
  // Process audio data
  connect(record_dialog, &RecordingDialog::process_audio_data, this, &Tangerine::process_audio_data);
  record_dialog->exec();
  record_dialog->deleteLater();
}