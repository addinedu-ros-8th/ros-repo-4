#ifndef BATTERY_WIDGET_H
#define BATTERY_WIDGET_H

#include <QWidget>

class BatteryWidget : public QWidget {
    Q_OBJECT

public:
    explicit BatteryWidget(QWidget *parent = nullptr);
    void set_percentage(int value);

protected:
    void paintEvent(QPaintEvent *event);
private:
    int percentage;
};

#endif