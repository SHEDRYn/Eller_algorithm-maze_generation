#ifndef SRC_MAZE_VIEW_MAINWINDOW_H
#define SRC_MAZE_VIEW_MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
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

  size_t GetNumCols();
  size_t GetNumRows();
  void SetStartPoint(int _x, int _y);
  void SetEndPoint(int _x, int _y);

  bool importFile(const std::string &filePath);

 protected:
  void mousePressEvent(QMouseEvent *event);
  void paintEvent(QPaintEvent *event) override;
  // virtual void update();

 private slots:
  void on_importBtn_clicked();
  void on_pushButton_clicked();

 private:
  Ui::MainWindow *ui;
  Controller *controller_;
  // bool needsUpdate_ = false;
  bool repaintToUpdate_ = false;
  size_t countMouseClick_ = 0;
  Point startPoint_;
  Point endPoint_;
};
#endif  // SRC_MAZE_VIEW_MAINWINDOW_H
