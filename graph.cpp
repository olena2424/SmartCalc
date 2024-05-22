#include "graph.h"

#include "ui_graph.h"

Graph::Graph(QWidget* parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
  ui->widget->hide();
  connect(ui->pushButton_OK, SIGNAL(clicked()), this,
          SLOT(on_pushButton_OK_clicked()));
}

Graph::~Graph() { delete ui; }

void Graph::draw(char* polish) {
  long double result_num = 0.0;
  double Xmin = ui->lineEdit_Xmin->text().toDouble();
  double Xmax = ui->lineEdit_Xmax->text().toDouble();
  double Ymin = ui->lineEdit_Ymin->text().toDouble();
  double Ymax = ui->lineEdit_Ymax->text().toDouble();
  if (Xmin <= -1000000) {
    xBegin = -1000000;
  } else {
    xBegin = Xmin;
  }
  if (Xmax >= 1000000) {
    xEnd = 1000000;
  } else {
    xEnd = Xmax;
  }
  if (ui->lineEdit_Xmin->text().size() != 0 &&
      ui->lineEdit_Xmax->text().size() != 0 &&
      ui->lineEdit_Ymin->text().size() != 0 &&
      ui->lineEdit_Ymax->text().size() != 0 && Xmin < Xmax && Ymin < Ymax) {
    h = 0.1;
    ui->widget->xAxis->setRange(Xmin, Xmax);
    ui->widget->yAxis->setRange(Ymin, Ymax);
    for (X = xBegin; X <= xEnd; X += h) {
      calc(polish, X, &result_num);
      x.push_back(X);
      if (result_num > Ymax || result_num < Ymin) {
        y.push_back(qQNaN());
      } else {
        y.push_back(result_num);
      }
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->show();
  }
}

void Graph::on_pushButton_OK_clicked() { draw(gl_polish); }
