#include "controller.h"

bool Controller::loadMap(const std::string& filename) {
  try {
    data_ = pars.loadMazeFromFile(filename);
  } catch (const char* error) {
    std::cerr << error << std::endl;
    return false;
  }
  return true;
}