#include "user_gui/tangerine.h"
#include "ui_tangerine.h"

Tangerine::Tangerine(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Tangerine)
{
  ui->setupUi(this);
}

Tangerine::~Tangerine()
{
  delete ui;
}