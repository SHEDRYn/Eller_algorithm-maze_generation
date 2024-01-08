#include <iostream>
#include <random>
#include <vector>

class EllerMazeGenerator {
 public:
  EllerMazeGenerator(int width, int height) : width_(width), height_(height) {
    // Инициализируем сетку лабиринта
    grid_.resize(width * height, Cell{});
  }

  void GenerateMaze() {
    // Проходимся по каждой строке лабиринта
    for (int row = 0; row < height_; ++row) {
      // Объединяем ячейки в текущей строке
      UnionCellsInCurrentRow(row);

      // Создаем стены между соседними ячейками
      CreateWallsBetweenNeighboringCells(row);
    }
  }

  void PrintMaze() const {
    // Выводим верхнюю границу лабиринта
    PrintTopBorder();

    // Выводим каждую строку лабиринта
    for (int row = 0; row < height_; ++row) {
      PrintRow(row);

      // Выводим правую границу лабиринта
      PrintRightBorder(row);
    }
  }

 private:
  struct Cell {
    bool right_wall = true;
    bool bottom_wall = true;
    int set_id = -1;
  };

  int width_;
  int height_;
  std::vector<Cell> grid_;
  std::vector<int> set_sizes_;

  std::random_device rd_;
  std::mt19937 gen_{rd_()};

  // Функция для получения случайного числа
  int GetRandomNumber(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen_);
  }

  // Функция для объединения ячеек в текущей строке
  void UnionCellsInCurrentRow(int row) {
    for (int col = 0; col < width_; ++col) {
      int cell_index = row * width_ + col;

      // Если ячейка еще не принадлежит ни одному множеству,
      // то создаем новое множество
      if (grid_[cell_index].set_id == -1) {
        grid_[cell_index].set_id = set_sizes_.size();
        set_sizes_.push_back(1);
      }

      // Если не последний столбец и следующая ячейка принадлежит другому
      // множеству, то объединяем текущую ячейку и следующую ячейку
      if (col < width_ - 1 &&
          grid_[cell_index + 1].set_id != grid_[cell_index].set_id) {
        grid_[cell_index + 1].set_id = grid_[cell_index].set_id;
        set_sizes_[grid_[cell_index].set_id]++;
        grid_[cell_index].right_wall = false;
      }
    }
  }

  // Функция для создания стен между соседними ячейками
  void CreateWallsBetweenNeighboringCells(int row) {
    for (int col = 0; col < width_; ++col) {
      int cell_index = row * width_ + col;

      // Если текущая ячейка находится в последнем ряду,
      // то создаем нижнюю стену
      if (row == height_ - 1) {
        grid_[cell_index].bottom_wall = true;
      } else {
        // Если текущая ячейка и следующая ячейка принадлежат разным множествам,
        // то создаем нижнюю стену и случайным образом решаем, создавать правую
        // стену или нет
        if (grid_[cell_index].set_id != grid_[cell_index + width_].set_id) {
          grid_[cell_index].bottom_wall = true;

          if (GetRandomNumber(0, 1) == 1) {
            grid_[cell_index].right_wall = true;
          } else {
            grid_[cell_index + width_].set_id = grid_[cell_index].set_id;
            set_sizes_[grid_[cell_index].set_id] +=
                set_sizes_[grid_[cell_index + width_].set_id];
            set_sizes_[grid_[cell_index + width_].set_id] = 0;
            grid_[cell_index].right_wall = false;
          }
        } else {
          // Если текущая ячейка и следующая ячейка принадлежат одному
          // множеству, то удаляем правую стену
          grid_[cell_index].right_wall = false;
        }
      }
    }
  }

  // Функция для вывода верхней границы лабиринта
  void PrintTopBorder() const {
    std::cout << "+";
    for (int col = 0; col < width_; ++col) {
      std::cout << "--+";
    }
    std::cout << "\n";
  }

  // Функция для вывода строки лабиринта
  void PrintRow(int row) const {
    std::cout << "1";
    for (int col = 0; col < width_; ++col) {
      int cell_index = row * width_ + col;

      // Выводим пробел, если нет ни правой, ни нижней стены
      if (!grid_[cell_index].right_wall && !grid_[cell_index].bottom_wall) {
        std::cout << "  ";
      }
      // Выводим символ "-" вместо правой стены
      else if (!grid_[cell_index].right_wall && grid_[cell_index].bottom_wall) {
        std::cout << " 0";
      }
      // Выводим символ "|" вместо нижней стены
      else if (grid_[cell_index].right_wall && !grid_[cell_index].bottom_wall) {
        std::cout << " 1";
      }
      // Выводим символы "-" и "|" вместо правой и нижней стен соответственно
      else {
        std::cout << " 1";
      }
    }
    std::cout << "\n";
  }

  // Функция для вывода правой границы лабиринта
  void PrintRightBorder(int row) const {
    std::cout << "+";
    for (int col = 0; col < width_; ++col) {
      int cell_index = row * width_ + col;
      std::cout << (grid_[cell_index].bottom_wall ? "--" : "  ") << "+";
    }
    std::cout << "\n";
  }
};

int main() {
  int width, height;
  std::cout << "Введите ширину лабиринта: ";
  std::cin >> width;
  std::cout << "Введите высоту лабиринта: ";
  std::cin >> height;

  EllerMazeGenerator maze_generator(width, height);
  maze_generator.GenerateMaze();
  maze_generator.PrintMaze();

  return 0;
}