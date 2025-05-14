#include "user_gui/tangerine.h"
#include "ui_tangerine.h"

#include <QPixmap>
#include <QFileInfo> 
#include <QDir>
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
#include "user_gui/image_button.h"
#include "user_gui/circular_progressbar.h"
#include "user_gui/battery_widget.h"

Tangerine::Tangerine(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Tangerine),
  map_received_(false)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);
    ui->robot_widget->setCurrentIndex(1);

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

    handle_command_client = node_->create_client<tangerbot_msgs::srv::HandleCommand>("handle_command");

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

    loading = new QMovie(":/image/Loading_icon.gif");
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
    battery_circular_progressbar->set_percentage(100);

    // Robot batter widget
    battery_widget = new BatteryWidget(ui->battery_widget_frame);
    QVBoxLayout *battery_progressbar_widget1 = new QVBoxLayout(ui->battery_widget_frame);
    battery_progressbar_widget1->addWidget(battery_widget);
    battery_widget->set_percentage(60);

    /**********************************************
     * * Navigate to Page
    ***********************************************/
    connect(ui->btn_signin, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(2);});
    connect(ui->btn_signup, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->btn_complete, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->btn_signinMain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

    connect(ui->btn_mmain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});
    connect(ui->btn_rmain, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentIndex(3);
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    connect(ui->btn_smain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

    connect(ui->btn_mrobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});
    connect(ui->btn_rrobot, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentIndex(4);
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    connect(ui->btn_srobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});

    connect(ui->btn_msettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});
    connect(ui->btn_rsettings, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentIndex(5);
      ui->robot_widget->setCurrentIndex(current_robottab_index);
    });
    connect(ui->btn_ssettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});


    connect(ui->btn_call, &QPushButton::clicked, this, [=]() {ui->robot_widget->setCurrentIndex(2);});
    connect(ui->btn_vociecall, &QPushButton::clicked, this, [=]() {ui->robot_widget->setCurrentIndex(3);});

    /**********************************************
     * * Call Functions
    ***********************************************/
    goal_pub_ = node_->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

}



Tangerine::~Tangerine()
{
  delete ui;
  rclcpp::shutdown();
}

bool Tangerine::get_called_robot() {
  return called_robot;
}

void Tangerine::handle_selection(QString section) {
  using namespace std::chrono_literals;

  called_robot = true;
  
  auto request = std::make_shared<tangerbot_msgs::srv::HandleCommand::Request>();
  request->user_id = user_id;
  request->type = tangerbot_msgs::srv::HandleCommand::Request::MOVETOSECTION;
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

  auto result = handle_command_client->async_send_request(request);
  
  if (rclcpp::spin_until_future_complete(node_, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
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
  } else {
    RCLCPP_ERROR(node_->get_logger(), "Failed to call service handle_command");
    QMessageBox::warning(this, "Failed", "Can't request service!");
    return;
  }
}