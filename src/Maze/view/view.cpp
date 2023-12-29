#include "view.h"
#include "ui_view.h"

view::view(Controller *c, QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::view)
    , c_(c)
{
    ui_->setupUi(this);
}

view::~view()
{
    delete ui_;
}


void view::on_OpenFIle_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                               "Выберите файл",
                                               QDir::homePath() + "/Documents",
                                               "All Files (*)");
    
    ui_->file_name->setText(path);

    c_->FileProcessing(path.toStdString());
    // if ()

}

