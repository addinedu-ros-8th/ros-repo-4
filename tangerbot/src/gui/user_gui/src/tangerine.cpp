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
  // QString imagePath = QDir::current().absolutePath("/src/gui/user_gui/ui/mainPic.png");
  // //QString imagePath = QDir::fromNativeSeparators(QCoreApplication::applicationDirPath() + "/../ui/mainPic.png");

  // qDebug() << "Current Directory: " << QDir::current();


  // Debugging the current directory
  QString path = QDir::current().absolutePath();
  QString imagePath = path + "/src/gui/user_gui/ui/mainPic.png";
  
  qDebug() << "Image Path: " << imagePath;
  // Load the image into the label
  QPixmap pixmap(imagePath); 
  ui->label_introPic->setPixmap(pixmap);
  ui->label_introPic->setScaledContents(true);
}



Tangerine::~Tangerine()
{
  delete ui;
}