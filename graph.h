#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>
extern "C" {
#include "s21_smart_calc.h"
}

namespace Ui {
class Graph;
}

class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(QWidget* parent = nullptr);
  void draw(char* polish);
  char* gl_polish;
  ~Graph();

 private slots:
  void on_pushButton_OK_clicked();

 private:
  Ui::Graph* ui;
  double xBegin, xEnd, h, X;
  QVector<double> x, y;
};

#endif  // GRAPH_H
