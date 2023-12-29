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

// void view::paintEvent(QPaintEvent *event) {
//   QPainter painter(this);
//   if (repaintToUpdate_) {
//     painter.fillRect(rect(), Qt::black);
//     painter.setPen(QPen(Qt::white, 2));

//     int cellWidth = ui_->maze_board->width() / c_->GetMaze()->rows_;    // width:500 px
//     int cellHeight = ui_->maze_board->height() / c_->GetMaze()->cols_;  // height:500 px

//     painter.drawRect(10, 10, 500, 500);
//     for (int i = 0; i < c_->GetMaze()->rows_; ++i) {
//       for (int j = 0; j < c_->GetMaze()->cols_; ++j) {
//         int x = j * cellWidth + 10;
//         int y = i * cellHeight + 10;
//         if (c_->GetMaze()->wall_down_[i][j]) {
//           painter.drawLine(x, y + cellHeight, x + cellWidth, y + cellHeight);
//         }

//         if (c_->GetMaze()->wall_right_[i][j]) {
//           painter.drawLine(x + cellWidth, y, x + cellWidth, y + cellHeight);
//         }
//       }
//     }

//     painter.setPen(QPen(Qt::green, 2));

//   }
// }


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

// int GetNumRows() {
//   return c_->GetMaze().rows_;
// }

// int GetNumCols() {
//   return c_->GetMaze().cols_;
// }

