#ifndef SRC_MAZE_MODEL_PATHFINDER_H
#define SRC_MAZE_MODEL_PATHFINDER_H

#include "parser.h"

class PathFinder {
 public:
  PathFinder() = default;
  ~PathFinder();

  struct Point {
    int x_ = 0;
    int y_ = 0;
    Point() = default;
    Point(int x, int y) : x_(x), y_(y){};
  };
  Point start;
  Point end;

  void findPath(Parser::RowsAndColumns, const Point start, const Point end);

 private:
  /* data */
};

#endif  // SRC_MAZE_MODEL_PATHFINDER_H
