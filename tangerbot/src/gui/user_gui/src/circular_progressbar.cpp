#include "user_gui/circular_progressbar.h"
#include <QPainter>
#include <QRectF>
#include <QPen>
#include <QFont>
#include <QPaintEvent>
#include <iostream>

CircularProgressBar::CircularProgressBar(QWidget *parent)
: QWidget(parent), percentage(0)
{
    // None
}

void CircularProgressBar::set_percentage(int value) {
    percentage = value;
    update();
}

void CircularProgressBar::set_color(QColor background_color, QColor progressbar_color) {
    this->background_color = background_color;
    this->progressbar_color = progressbar_color;
}

void CircularProgressBar::set_margin(int margin) {
    this->margin = margin;
}


void CircularProgressBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int side = qMin(width(), height()) - 2 * margin;
    QRect rect((width() - side) / 2, (height() - side) / 2, side, side);
    // Circular background color
    painter.setPen(Qt::NoPen);
    painter.setBrush(background_color);
    painter.drawEllipse(rect);

    // Progress bar color
    painter.setBrush(Qt::NoBrush);
    QPen pen(progressbar_color, 10);
    painter.setPen(pen);
    int startAngle = 90 * 16;
    int spanAngle = -percentage * 360 * 16 / 100;
    painter.drawArc(rect, startAngle, spanAngle);

    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(20);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, QString::number(percentage) + "%");
}