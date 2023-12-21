#ifndef SRC_MAZE_MODEL_DATATYPES_H
#define SRC_MAZE_MODEL_DATATYPES_H

#include <vector>

using std::vector;

struct RowsAndColumns {
  vector<vector<int>> rows;
  vector<vector<int>> columns;
};

struct Point {
  int x = 0;
  int y = 0;
  Point() = default;
  Point(int _x, int _y) : x(_x), y(_y) {}
};

#endif  // SRC_MAZE_MODEL_DATATYPES_H