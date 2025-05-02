#include "include/user_gui/tangerine.h"
#include "ui_tangerine.h"

#include <QPixmap>
#include <QFileInfo> 
#include <QDir>
#include <QDebug>

Tangerine::Tangerine(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Tangerine)
{
  ui->setupUi(this);

  
  /**********************************************
   * * Load the main image for the intro page
   **********************************************/
  QString path = QDir::current().absolutePath();
  QString imagePath = path + "/src/gui/user_gui/ui/mainPic.png";
  //qDebug() << "Image Path: " << imagePath;
  QPixmap pixmap(imagePath); 
  ui->label_introPic->setPixmap(pixmap);
  ui->label_introPic->setScaledContents(true);

  /**********************************************
   * * Move the Page with clicking the buttons
   **********************************************/
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
  


  /**********************************************
   * TODO: Connect Database
   **********************************************/

  /**********************************************
   * TODO: Save the user data from signup page to database
   **********************************************/

  /**********************************************
   * TODO: Check the match data (signin page input) with database
   **********************************************/

   /**********************************************
   * TODO: Update Map (Main page, unclickable, just for monitoring)
   **********************************************/

   /**********************************************
   * TODO: Update Map (Robot page, clickable, send goal data)
   **********************************************/

}



Tangerine::~Tangerine()
{
  delete ui;
}