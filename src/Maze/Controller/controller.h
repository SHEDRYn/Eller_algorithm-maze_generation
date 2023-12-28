#ifndef SRC_MAZE_CONTROLLER_CONTROLLER_H
#define SRC_MAZE_CONTROLLER_CONTROLLER_H

#include "../Model/parser.h"
#include "../Model/pathFinder.h"

class Controller {
 public:
  Controller() = default;

  bool loadMap(const std::string& filename);
  void loadPath(const RowsAndColumns walls, const Point start, const Point end);
  void cleanPath() { path_.clear(); }
  RowsAndColumns GetData();
  vector<Point> GetPath();

 private:
  Parser parser_;
  PathFinder pathFinder_;

  vector<Point> path_;
  RowsAndColumns data_;
};

#endif  // SRC_MAZE_CONTROLLER_CONTROLLER_H