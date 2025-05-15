#ifndef IMAGE_BUTTON_H
#define IMAGE_BUTTON_H

#include <QMainWindow>
#include <QPainter>
#include <chrono>
#include <QString>
#include "user_gui/tangerine.h"

struct DrawParams {
    int x;
    int y;
    int radius;
};

const DrawParams SEC_1 = {30, 30, 15};
const DrawParams SEC_2 = {245, 30, 15};
const DrawParams SEC_3 = {245, 90, 15};
const DrawParams SEC_4 = {250, 250, 15};
const DrawParams SEC_5 = {250, 345, 15};
const DrawParams SEC_6 = {140, 345, 15};
const DrawParams SEC_7 = {30, 345, 15};

class ImageButton : public QWidget {
    Q_OBJECT
public:
    ImageButton(Tangerine *mainWin, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void draw_section(QPainter &painter, DrawParams params);
    
signals:
    void call_confirmed(QString section);

private slots:
    void select_section(QString section);

private:
    Tangerine *mainWin;
    QPixmap image;
    QPainter painter;
    bool section_1 = false;
    bool section_2 = false;
    bool section_3 = false;
    bool section_4 = false;
    bool section_5 = false;
    bool section_6 = false;
    bool section_7 = false;
};

#endif