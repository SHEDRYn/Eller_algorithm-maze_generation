#include "parser.h"

RowsAndColumns Parser::loadMazeFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw("Failed to open file: " + filename);
  }

  int numRows, numCols;
  file >> numRows >> numCols;

  if (numRows > 50 || numRows < 1) {
    throw("Error count of rows: " + std::to_string(numRows));
  } else if (numCols > 50 || numCols < 1) {
    throw("Error count of columns: " + std::to_string(numCols));
  }

  RowsAndColumns maze;
  vector<vector<int>> maze_columns(numRows, vector<int>(numCols));
  vector<vector<int>> maze_rows(numRows, vector<int>(numCols));

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      file >> maze_columns[i][j];
      if (!(maze_columns[i][j] == 0 || maze_columns[i][j] == 1))
        throw("Error val in columns table: " +
              std::to_string(maze_columns[i][j]));
    }
  }

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      file >> maze_rows[i][j];
      if (!(maze_rows[i][j] == 0 || maze_rows[i][j] == 1))
        throw("Error val in rows table: " + std::to_string(maze_rows[i][j]));
    }
  }

  maze.columns = maze_columns;
  maze.rows = maze_rows;

  file.close();

  return maze;
}
