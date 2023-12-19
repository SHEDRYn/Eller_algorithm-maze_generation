#include <QApplication>

#include "Controller/controller.h"
#include "View/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  Controller c;
  MainWindow w(nullptr, &c);
  w.show();
  return a.exec();
}
