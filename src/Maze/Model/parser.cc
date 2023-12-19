#include "parser.h"

std::vector<std::vector<int>> Parser::loadMazeFromFile(
    const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw("Failed to open file: " + filename);
  }

  int numRows, numCols;
  file >> numRows >> numCols;

  std::vector<std::vector<int>> maze(numRows, std::vector<int>(numCols));

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      file >> maze[i][j];
    }
  }

  file.close();

  return maze;
}
