#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "graph.h"
extern "C" {
#include "s21_smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  void print_res(double x, char* polish);
  ~MainWindow();

 private:
  Ui::MainWindow* ui;
  Graph* graph;

 private slots:
  void into_string();
  void on_pushButton_clear_clicked();
  void on_pushButton_eq_clicked();
  void on_pushButton_graph_clicked();
};
#endif  // MAINWINDOW_H
