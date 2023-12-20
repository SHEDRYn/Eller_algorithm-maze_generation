#include "controller.h"
#include <ostream>

bool Controller::loadMap(const std::string& filename) {
  try {
    data_ = pars.loadMazeFromFile(filename);
  } catch (const char* error) {
    std::cerr << error << std::endl;
    return false;
  }
  return true;
}

Parser::RowsAndColumns Controller::GetData() {
  return data_;
}
