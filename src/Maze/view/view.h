#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMouseEvent>
#include <QPainter>

#include "../controller/controller.h"
#include "../Model/point/point.h"

// #include <fstream>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class view; }
QT_END_NAMESPACE

class view : public QMainWindow
{
    Q_OBJECT

public:
    view(Controller *c, QWidget *parent = nullptr);
    ~view();

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_OpenFIle_clicked();

private:
    void SetStartPoint(int x, int y);
    void SetEndPoint(int x, int y);
    Ui::view *ui_;
    Controller* c_;
    bool repaintToUpdate_ = false;
    Point startPoint_;
    Point endPoint_;
    int countMouseClick_;
    
};
#endif // VIEW_H
