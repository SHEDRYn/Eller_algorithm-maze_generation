#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Controller *c)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(c) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }
