#include "controller.h"
#include <ostream>

bool Controller::loadMap(const std::string& filename) {
  try {
    data_ = parser_.loadMazeFromFile(filename);
  } catch (std::string& error) {
    std::cout << error << std::endl;
    return false;
  }
  return true;
}

void Controller::loadPath(const RowsAndColumns walls, const Point start, const Point end) {
  path_ = pathFinder_.findPath(walls, start, end);
}

RowsAndColumns Controller::GetData() {
  return data_;
}

vector<Point>  Controller::GetPath() {
  return path_;
}
