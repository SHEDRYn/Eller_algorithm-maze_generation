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
  pathFinder_.findPath(walls, start, end);
}

void Controller::cleanPath() { pathFinder_.cleanPath(); }

RowsAndColumns Controller::GetData() {
  return data_;
}

vector<Point> Controller::GetPath() {
  return pathFinder_.GetPath();
}
