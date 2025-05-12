#include <QApplication>
#include "user_gui/tangerine.h"
#include "ui_tangerine.h"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);
    Tangerine window;
    window.show();
    app.exec();
    rclcpp::shutdown();
    return 0;
}