#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_open_br, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_close_br, SIGNAL(clicked()), this,
          SLOT(into_string()));
  connect(ui->pushButton_degr, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(into_string()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(into_string()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::into_string() {
  QPushButton* button = static_cast<QPushButton*>(QObject::sender());
  QString new_label = ui->result_show->text() + button->text();
  if (is_func((button->text()).toStdString().c_str()[0])) {
    new_label += '(';
  }
  ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_clear_clicked() { ui->result_show->setText(""); }

void MainWindow::print_res(double x, char* polish) {
  long double result_num = 0.0;
  int calc_res = calc(polish, x, &result_num);
  if (calc_res == 1) {
    ui->result_show->setText(QString::number((double)result_num));
  } else if (calc_res == 2) {
    ui->result_show->setText("Err");
  } else {
    ui->result_show->setText("Error division by 0");
  }
}

void MainWindow::on_pushButton_eq_clicked() {
  char* polish =
      (char*)malloc(sizeof(char) * 2 * ui->result_show->text().size() + 1);
  int result = conversion(ui->result_show->text().toLocal8Bit().data(), polish);
  if (result == 1) {
    ui->result_show->setText("Error");
  } else {
    if (ui->result_show->text().contains('x')) {
      if (ui->lineEdit_for_x->text().size() == 0) {
        ui->result_show->setText("Fill the X field");
      } else {
        print_res(ui->lineEdit_for_x->text().toDouble(), polish);
      }
    } else {
      print_res(1, polish);
    }
  }
  free(polish);
}

void MainWindow::on_pushButton_graph_clicked() {
  char* polish =
      (char*)malloc(sizeof(char) * 2 * ui->result_show->text().size() + 1);
  // char* polish {new char(2 * ui->result_show->text().size())};
  int result = conversion(ui->result_show->text().toLocal8Bit().data(), polish);
  if (result == 1) {
    ui->result_show->setText("Error");
  } else {
    if (ui->result_show->text().contains('x')) {
      // open second window with graph
      Graph graph;
      graph.gl_polish = polish;
      graph.setModal(true);
      graph.exec();
    } else {
      ui->result_show->setText("Expression should contain x");
    }
  }
  free(polish);
  // delete polish;
}
