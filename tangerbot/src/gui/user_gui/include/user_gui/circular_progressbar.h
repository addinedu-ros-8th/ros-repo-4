#include <QWidget>

class CircularProgressBar : public QWidget {
    Q_OBJECT

public:
    explicit CircularProgressBar(QWidget *parent = nullptr);
    void set_color(QColor background_color, QColor progressbar_color);
    void set_margin(int margin);
    void set_percentage(int value);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int percentage;
    QColor background_color = QColor(0xFF, 0xB2, 0x2C);
    QColor progressbar_color = QColor(0xFA, 0x81, 0x2F);
    int margin = 0;
};
