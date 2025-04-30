#ifndef TANGERINE_H
#define TANGERINE_H

#include <QMainWindow>

namespace Ui {
    class Tangerine;
}

class Tangerine : public QMainWindow
{
  Q_OBJECT

public:
  explicit Tangerine(QWidget *parent = nullptr);
  ~Tangerine();

private:
  Ui::Tangerine *ui;
};

#endif