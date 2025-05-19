#include "user_gui/battery_widget.h"

#include <QPainter>

BatteryWidget::BatteryWidget(QWidget *parent)
: QWidget(parent), percentage(0)
{
    // None
}

void BatteryWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int w = width();
    int h = height();

    int body_width = w * 0.45;
    int body_height = h * 0.6;
    int body_x = (w - body_width) / 2;
    int body_y = (h - body_height) / 2;

    QRect body_rect(body_x, body_y, body_width, body_height);
    painter.setPen(QPen(Qt::black, 3));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(body_rect);

    int cap_width = body_width * 0.4;
    int cap_height = body_height * 0.1;
    int cap_x = body_x + body_width / 2 - cap_width / 2;
    int cap_y = body_y - cap_height;

    QRect cap_rect(cap_x, cap_y, cap_width, cap_height);
    painter.drawRect(cap_rect);

    int fill_margin = 5;
    int full_width = body_width - 2 * fill_margin;
    int full_height = body_height - 2 * fill_margin;
    int x = body_x + fill_margin;
    int y = body_y + fill_margin + full_height * (1 - percentage / 100.0);
    QRect fill_rect(x, y, full_width, full_height * (percentage / 100.0));
    painter.setBrush(QColor(0x00, 0xFF, 0x7F));
    painter.setPen(Qt::NoPen);
    painter.drawRect(fill_rect);

    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(15);
    painter.setFont(font);
    int min_size = qMin(body_width, body_height);
    QRect rect(body_x, body_y + body_height * 0.3, min_size, min_size);
    painter.drawText(rect, Qt::AlignCenter, QString::number(percentage) + "%");
}

void BatteryWidget::set_percentage(int value) {
    percentage = value;
    update();
}