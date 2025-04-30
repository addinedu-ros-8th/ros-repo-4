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
  
  /**
   * * Load the main image
   */
  QString path = QDir::current().absolutePath();
  QString imagePath = path + "/src/gui/user_gui/ui/mainPic.png";
  //qDebug() << "Image Path: " << imagePath;
  QPixmap pixmap(imagePath); 
  ui->label_introPic->setPixmap(pixmap);
  ui->label_introPic->setScaledContents(true);

  /**
   * *Buttons Connections
   */
  
  connect(ui->btn_signin, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(1);});
  connect(ui->btn_signup, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(2);});
  connect(ui->btn_complete, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(0);});
  connect(ui->btn_signinMain, &QPushButton::clicked, this, [=]() {ui->stackedWidget->setCurrentIndex(3);});

}



Tangerine::~Tangerine()
{
  delete ui;
}