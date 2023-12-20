#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Controller *c)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(c) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::importFile(const std::string &filePath) {
  needsUpdate_ = controller_->loadMap(filePath);
  return needsUpdate_;
}

void MainWindow::paintEvent(QPaintEvent *event) {
  //  qDebug() << "Paint Event";
  //  qDebug() << needsUpdate_;

  QPainter painter(this);
  if (needsUpdate_) {
    int numRows = controller_->GetData().size();
    int numCols = controller_->GetData()[0].size();

    int cellWidth = ui->map->width() / numCols;    // width:500 px
    int cellHeight = ui->map->height() / numRows;  // height:500 px

    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < numCols; ++j) {
        int x = j * cellWidth + 10;
        int y = i * cellHeight + 10;

        if (controller_->GetData()[i][j] == 1) {
          painter.fillRect(x, y, cellWidth, cellHeight, Qt::black);
        } else {
          painter.fillRect(x, y, cellWidth, cellHeight, Qt::white);
        }
      }
    }
  }
}

void MainWindow::update() {
  if (needsUpdate_) {
    QWidget::update();
    needsUpdate_ = false;
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
