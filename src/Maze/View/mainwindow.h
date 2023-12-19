#ifndef SRC_MAZE_VIEW_MAINWINDOW_H
#define SRC_MAZE_VIEW_MAINWINDOW_H

#include <QMainWindow>

#include "../Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr, Controller *c = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Controller *controller_;
};
#endif  // SRC_MAZE_VIEW_MAINWINDOW_H
