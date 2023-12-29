#include <QApplication>

#include "Controller/controller.h"
#include "View/mainwindow.h"
#include "Model/model.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Model m;
  Controller c(&m);
  MainWindow w(nullptr, &c);
  w.show();
  return a.exec();
}
