#ifndef SRC_MAZE_VIEW_MAINWINDOW_H
#define SRC_MAZE_VIEW_MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>

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

  bool importFile(const std::string &filePath);

 protected:
  void paintEvent(QPaintEvent *event) override;
  virtual void update();

 private slots:
  void on_importBtn_clicked();

 private:
  Ui::MainWindow *ui;
  Controller *controller_;
  bool needsUpdate_ = false;
};
#endif  // SRC_MAZE_VIEW_MAINWINDOW_H
