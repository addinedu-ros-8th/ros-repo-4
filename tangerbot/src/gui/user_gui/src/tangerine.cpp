#include "include/user_gui/tangerine.h"
#include "include/user_gui/image_button.h"
#include "ui_tangerine.h"

#include <QPixmap>
#include <QFileInfo> 
#include <QDir>
#include <QDebug>
#include <QMouseEvent>

Tangerine::Tangerine(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Tangerine),
  map_received_(false)
{
    ui->setupUi(this);

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

    ImageButton *img_btn = new ImageButton(this, ui->frame_40);
    QVBoxLayout *layout = new QVBoxLayout(ui->frame_40);
    layout->addWidget(img_btn);
    ui->frame_40->setLayout(layout);
    connect(img_btn, &ImageButton::call_confirmed, this, &Tangerine::handle_selection);

    /**********************************************
     * * Navigate to Page
    ***********************************************/
    connect(ui->btn_signin, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(2);});
    connect(ui->btn_signup, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->btn_complete, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->btn_signinMain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

    connect(ui->btn_mmain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});
    connect(ui->btn_rmain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});
    connect(ui->btn_smain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

    connect(ui->btn_mrobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});
    connect(ui->btn_rrobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});
    connect(ui->btn_srobot, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(4);});

    connect(ui->btn_msettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});
    connect(ui->btn_rsettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});
    connect(ui->btn_ssettings, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(5);});


    connect(ui->btn_call, &QPushButton::clicked, this, [=]() {ui->stackedWidget_2->setCurrentIndex(1);});
    connect(ui->btn_vociecall, &QPushButton::clicked, this, [=]() {ui->stackedWidget_2->setCurrentIndex(3);});

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

  while (!handle_command_client->wait_for_service(1s)) {
      if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return;
      }
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = handle_command_client->async_send_request(request);

  if (rclcpp::spin_until_future_complete(node_, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(node_->get_logger(), "success");
  } else {
    RCLCPP_ERROR(node_->get_logger(), "Failed to call service handle_command");
  }
}