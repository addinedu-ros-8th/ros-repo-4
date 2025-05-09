#include "include/user_gui/tangerine.h"
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
     * * Load the main image for the intro page
    ***********************************************/
    QString path = QDir::current().absolutePath();
    QString imagePath = path + "/src/gui/user_gui/ui/mainPic.png";
    //qDebug() << "Image Path: " << imagePath;
    QPixmap pixmap(imagePath); 
    ui->label_introPic->setPixmap(pixmap);
    ui->label_introPic->setScaledContents(true);

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
    setupMapSubscriber();

}



Tangerine::~Tangerine()
{
  delete ui;
  rclcpp::shutdown();
}


/**********************************************
 * * Setup Map Subscriber
 **********************************************/
void Tangerine::setupMapSubscriber(){
  map_subscriber_ = node_->create_subscription<nav_msgs::msg::OccupancyGrid>("/map", 10,
    [this](const nav_msgs::msg::OccupancyGrid::SharedPtr msg) {
      map_received_ = true;
      processMap(msg);
      updateMonitoringMap();
    });
}

void Tangerine::processMap(const nav_msgs::msg::OccupancyGrid::SharedPtr msg){

    // Convert OccupancyGrid to QImage
    int width = msg->info.width;
    int height = msg->info.height;
    map_image_ = QImage(width, height, QImage::Format_RGB32);
    map_metadata_ = msg->info;


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = x + (height - y - 1) * width; // Flip y-axis for Qt
            int8_t value = msg->data[index];
            QRgb color;
            if (value == -1) {
                color = qRgb(128, 128, 128); // Unknown (gray)
            } else if (value == 0) {
                color = qRgb(255, 255, 255); // Free (white)
            } else {
                color = qRgb(0, 0, 0); // Occupied (black)
            }
            map_image_.setPixel(x, y, color);
        }
    }
}

void Tangerine::mousePressEvent(QMouseEvent *event) {
    // Map from global window coords to map QLabel coords
    QPoint labelTopLeft = ui->monitoringMap->mapToGlobal(QPoint(0, 0));
    QPoint clickGlobal = event->globalPos();
    QPoint clickOnLabel = clickGlobal - labelTopLeft;

    if (ui->monitoringMap->rect().contains(clickOnLabel)) {
        sendGoalFromClick(clickOnLabel);
    }
}


void Tangerine::sendGoalFromClick(const QPoint &click_pos) {

    if (!map_received_) return;
  
    // Convert pixel to map coordinates
    double resolution = map_metadata_.resolution;
    double origin_x = map_metadata_.origin.position.x;
    double origin_y = map_metadata_.origin.position.y;
  
    int img_x = click_pos.x();
    int img_y = click_pos.y();
  
    double map_x = origin_x + img_x * resolution;
    double map_y = origin_y + (map_image_.height() - img_y) * resolution;
  
    geometry_msgs::msg::PoseStamped goal;
    goal.header.frame_id = "map";
    goal.header.stamp = node_->get_clock()->now();
    goal.pose.position.x = map_x;
    goal.pose.position.y = map_y;
    goal.pose.position.z = 0.0;
    goal.pose.orientation.w = 1.0; // no rotation
  
    goal_pub_->publish(goal);
}
  

void Tangerine::updateMonitoringMap(){
  if (map_received_) {
    QPixmap pixmap = QPixmap::fromImage(map_image_);
    ui->monitoringMap->setPixmap(pixmap);
    ui->monitoringMap->setScaledContents(true);
  }


void Tangerine::sendVoiceData(){
    
}
}