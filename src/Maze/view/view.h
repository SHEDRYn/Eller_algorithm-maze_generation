#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QFileDialog>

#include "../controller/controller.h"

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

private slots:
    void on_OpenFIle_clicked();

private:
    Ui::view *ui_;
    Controller* c_;
};
#endif // VIEW_H
