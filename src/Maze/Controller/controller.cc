#include "controller.h"
#include <ostream>

bool Controller::loadMap(const std::string& filename) {
  try {
    data_ = pars.loadMazeFromFile(filename);
  } catch (std::string& error) {
    std::cout << error << std::endl;
    return false;
  }
  return true;
}

RowsAndColumns Controller::GetData() {
  return data_;
}
