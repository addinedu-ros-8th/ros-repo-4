#include <QApplication>
#include "user_gui/tangerine.h"
#include "ui_tangerine.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Tangerine window;
  window.show();
  return app.exec();
}