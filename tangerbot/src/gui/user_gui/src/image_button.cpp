#include "include/user_gui/image_button.h"

#include <QDir>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include <QTransform>
#include <QMessageBox>

ImageButton::ImageButton(Tangerine *mainWin, QWidget *parent) : QWidget(parent) {
    using namespace std;
    this->mainWin = mainWin;
    QString path = QDir::current().absolutePath();
    QString map_path = path + "/src/gui/user_gui/ui/tangermap.png";
    image = QPixmap(map_path);
    setMouseTracking(true);
}

void ImageButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(this->rect(), image);  // 이미지 그리기
    painter.setBrush(QColor(255, 0, 0, 150));
    draw_section(painter, SEC_1);
    draw_section(painter, SEC_2);
    draw_section(painter, SEC_3);
    draw_section(painter, SEC_4);
    draw_section(painter, SEC_5);
    draw_section(painter, SEC_6);
    draw_section(painter, SEC_7);

    QRect rect;
    rect.setRect(SEC_1.x, SEC_1.y, SEC_1.radius * 2, SEC_1.radius * 2);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    painter.drawText(rect, Qt::AlignCenter, "1");
    rect.moveTo(SEC_2.x, SEC_2.y);
    painter.drawText(rect, Qt::AlignCenter, "2");
    rect.moveTo(SEC_3.x, SEC_3.y);
    painter.drawText(rect, Qt::AlignCenter, "3");
    rect.moveTo(SEC_4.x, SEC_4.y);
    painter.drawText(rect, Qt::AlignCenter, "4");
    rect.moveTo(SEC_5.x, SEC_5.y);
    painter.drawText(rect, Qt::AlignCenter, "5");
    rect.moveTo(SEC_6.x, SEC_6.y);
    painter.drawText(rect, Qt::AlignCenter, "6");
    rect.moveTo(SEC_7.x, SEC_7.y);
    painter.drawText(rect, Qt::AlignCenter, "7");
    painter.setBrush(QColor(0, 255, 0, 150));
    if (section_1) {
        draw_section(painter, SEC_1);
    } else if (section_2) {
        draw_section(painter, SEC_2);
    } else if (section_3) {
        draw_section(painter, SEC_3);
    } else if (section_4) {
        draw_section(painter, SEC_4);
    } else if (section_5) {
        draw_section(painter, SEC_5);
    } else if (section_6) {
        draw_section(painter, SEC_6);
    } else if (section_7) {
        draw_section(painter, SEC_7);
    } else {}
}

void ImageButton::mouseMoveEvent(QMouseEvent *event) {
    section_1 = false;
    section_2 = false;
    section_3 = false;
    section_4 = false;
    section_5 = false;
    section_6 = false;
    section_7 = false;
    if (QRect(SEC_1.x, SEC_1.y, SEC_1.radius * 2, SEC_1.radius * 2).contains(event->pos())) {
        section_1 = true;
    } else if (QRect(SEC_2.x, SEC_2.y, SEC_2.radius * 2, SEC_2.radius * 2).contains(event->pos())) {
        section_2 = true;
    } else if (QRect(SEC_3.x, SEC_3.y, SEC_3.radius * 2, SEC_3.radius * 2).contains(event->pos())) {
        section_3 = true;
    } else if (QRect(SEC_4.x, SEC_4.y, SEC_4.radius * 2, SEC_4.radius * 2).contains(event->pos())) {
        section_4 = true;
    } else if (QRect(SEC_5.x, SEC_5.y, SEC_5.radius * 2, SEC_5.radius * 2).contains(event->pos())) {
        section_5 = true;
    } else if (QRect(SEC_6.x, SEC_6.y, SEC_6.radius * 2, SEC_6.radius * 2).contains(event->pos())) {
        section_6 = true;
    } else if (QRect(SEC_7.x, SEC_7.y, SEC_7.radius * 2, SEC_7.radius * 2).contains(event->pos())) {
        section_7 = true;
    }
    else {}
    update();
}

void ImageButton::mousePressEvent(QMouseEvent *event) {
    QMessageBox::StandardButton reply;
    QString section = nullptr;
    if (QRect(SEC_1.x, SEC_1.y, SEC_1.radius * 2, SEC_1.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 1!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 1?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section1";
    }
    if (QRect(SEC_2.x, SEC_2.y, SEC_2.radius * 2, SEC_2.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 2!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 2?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section2";
    }
    if (QRect(SEC_3.x, SEC_3.y, SEC_3.radius * 2, SEC_3.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 3!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 3?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section3";
    }
    if (QRect(SEC_4.x, SEC_4.y, SEC_4.radius * 2, SEC_4.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 4!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 4?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section4";
    }
    if (QRect(SEC_5.x, SEC_5.y, SEC_5.radius * 2, SEC_5.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 5!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 5?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section5";
    }
    if (QRect(SEC_6.x, SEC_6.y, SEC_6.radius * 2, SEC_6.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 6!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 6?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section6";
    }
    if (QRect(SEC_7.x, SEC_7.y, SEC_7.radius * 2, SEC_7.radius * 2).contains(event->pos())) {
        qDebug() << "Clicked Section 7!";
        reply = QMessageBox::question(mainWin, "Call", "Are you sure Section 7?",
                              QMessageBox::Yes | QMessageBox::No);
        section = "section7";
    }

    if (reply == QMessageBox::Yes) {
        if (mainWin->get_called_robot()) {
            QMessageBox::warning(mainWin, "Failed", "Already called!");
            return;
        }
        qDebug() << "Call robot at " << section << "!";
        select_section(section);
    }
}

void ImageButton::draw_section(QPainter &painter, DrawParams params) {
    painter.drawEllipse(params.x, params.y, params.radius * 2, params.radius * 2);
}

void ImageButton::select_section(QString section) {
    emit call_confirmed(section);
}