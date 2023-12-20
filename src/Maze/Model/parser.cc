#include "parser.h"

Parser::RowsAndColumns Parser::loadMazeFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw("Failed to open file: " + filename);
  }

  int numRows, numCols;
  file >> numRows >> numCols;

  Parser::RowsAndColumns maze;
  vector<vector<int>> maze_columns(numRows, vector<int>(numCols));
  vector<vector<int>> maze_rows(numRows, vector<int>(numCols));

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      file >> maze_columns[i][j];
    }
  }
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      file >> maze_rows[i][j];
    }
  }

  maze.columns = maze_columns;
  maze.rows = maze_rows;

  file.close();

  return maze;
}
