#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Controller *c)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(c) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

// void MainWindow::update() {
//   if (needsUpdate_) {
//     QWidget::update();
//     needsUpdate_ = false;
//   }
// }

bool MainWindow::importFile(const std::string &filePath) {
  repaintToUpdate_ = controller_->loadMap(filePath);
  return repaintToUpdate_;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    int x = event->position().x();
    int y = event->position().y();

    if (x > 10 && x <= 500 && y > 10 && y <= 500) {
      int cellWidth = ui->map->width() / GetNumRows();    // width:500 px
      int cellHeight = ui->map->height() / GetNumCols();  // height:500 px

      int resX = x / cellWidth + 1;
      int resY = y / cellHeight + 1;

      qDebug() << x << y;
      qDebug() << "res: " << resX << resY;

      if (countMouseClick_ == 2) {
        // getter.CleanPath();
        update();
        countMouseClick_ = 0;
      }

      if (countMouseClick_ == 0) {
        SetStartPoint(resX, resY);
        countMouseClick_++;
      } else if (countMouseClick_ == 1) {
        SetEndPoint(resX, resY);
        countMouseClick_++;

        // find_path();
      }
    }
  } else {
    event->ignore();
    //   getter.CleanPath();
    countMouseClick_ = 0;
  }
}

void MainWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  if (repaintToUpdate_) {
    painter.fillRect(rect(), Qt::black);
    painter.setPen(QPen(Qt::white, 2));

    int cellWidth = ui->map->width() / GetNumRows();    // width:500 px
    int cellHeight = ui->map->height() / GetNumCols();  // height:500 px

    painter.drawRect(10, 10, 500, 500);
    for (size_t i = 0; i < GetNumCols(); ++i) {
      for (size_t j = 0; j < GetNumRows(); ++j) {
        int x = j * cellWidth + 10;
        int y = i * cellHeight + 10;
        if (controller_->GetData().rows[i][j]) {
          painter.drawLine(x, y + cellHeight, x + cellWidth, y + cellHeight);
        }

        if (controller_->GetData().columns[i][j]) {
          painter.drawLine(x + cellWidth, y, x + cellWidth, y + cellHeight);
        }
      }
    }

    painter.setPen(QPen(Qt::green, 2));

    // if (getter.get_path_size() > 1) {
    //   std::vector<s21::PathFind::Point> current_path = getter.get_path();

    //   for (unsigned int i = 0; i < current_path.size() - 1; ++i) {
    //     int startX = current_path[i].x_ * cellWidth + cellWidth / 2;
    //     int startY = current_path[i].y_ * cellHeight + cellHeight / 2;
    //     int endX = current_path[i + 1].x_ * cellWidth + cellWidth / 2;
    //     int endY = current_path[i + 1].y_ * cellHeight + cellHeight / 2;
    //     painter.drawLine(startX, startY, endX, endY);
    //   }
    // }

    //    if (Controller)

    // for (unsigned int i = 0; i < 10 - 1; ++i) {
    //   int startX = i * cellWidth + cellWidth / 2;
    //   int startY = (i + 2) * cellHeight + cellHeight / 2;
    //   int endX = (i + 1) * cellWidth + cellWidth / 2;
    //   int endY = ((i + 2) + 1) * cellHeight + cellHeight / 2;
    //   painter.drawLine(startX, startY, endX, endY);
    // }
  }
}

void MainWindow::on_importBtn_clicked() {
  QString rootPath = QDir::rootPath();
  QString QString_filename = QFileDialog::getOpenFileName(
      this, tr("Open .txt file:"), rootPath, tr("*.txt"));

  if (!importFile(QString_filename.toStdString())) {
    QMessageBox::warning(this, "ERROR", "Не удалось получить данные");
    return;
  }
  repaint();
}

// void MainWindow::on_importBtn_clicked() {
//   if (importFile("/Users/karim/school21/A1_Maze/src/Maze/testFile.txt")) {
//     ui->importBtn->setText("PORT");
//     repaint();
//   }
// }

void MainWindow::on_pushButton_clicked() {
  bool fl = importFile("/Users/karim/school21/A1_Maze/src/Maze/testFile.txt");
  qDebug() << fl;
  if (!fl) {
    QMessageBox::warning(this, "ERROR", "Не удалось получить данные");
    return;
  }
  repaint();
}

size_t MainWindow::GetNumCols() {
  return controller_->GetData().columns.size();
}
size_t MainWindow::GetNumRows() {
  return controller_->GetData().columns[0].size();
}

void MainWindow::SetStartPoint(int _x, int _y) {
  startPoint_.x = _x;
  startPoint_.y = _y;
}
void MainWindow::SetEndPoint(int _x, int _y) {
  endPoint_.x = _x;
  endPoint_.y = _y;
}
