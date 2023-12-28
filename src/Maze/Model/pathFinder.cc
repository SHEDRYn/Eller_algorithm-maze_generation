#include "pathFinder.h"

#include <iostream>

vector<Point> PathFinder::findPath(const RowsAndColumns walls,
                                   const Point start, const Point end) {
  std::queue<Point> q;
  q.push(start);
  vector<vector<bool>> visited(walls.columns.size(),
                               vector<bool>(walls.columns[0].size(), false));
  vector<vector<int>> wave(walls.columns.size(),
                           vector<int>(walls.columns[0].size(), 0));
  while (!q.empty()) {
    Point current = q.front();
    q.pop();

    size_t x = current.x;
    size_t y = current.y;

    if (x == end.x && y == end.y) {
      path_.push_back(end);
      while (!(x == start.x && y == start.y)) {
        int dx = 0;
        int dy = 0;
        if (x > 0 && wave[x - 1][y] == wave[x][y] - 1 &&
            walls.rows[x - 1][y] == 0) {
          dx = -1;
        } else if (x < walls.columns.size() - 1 &&
                   wave[x + 1][y] == wave[x][y] - 1 && walls.rows[x][y] == 0) {
          dx = 1;
        } else if (y > 0 && wave[x][y - 1] == wave[x][y] - 1 &&
                   walls.columns[x][y - 1] == 0) {
          dy = -1;
        } else if (y < walls.columns[0].size() - 1 &&
                   wave[x][y + 1] == wave[x][y] - 1 &&
                   walls.columns[x][y] == 0) {
          dy = 1;
        }
        x += dx;
        y += dy;
        path_.insert(path_.begin(), Point(x, y));
        // std::cout << x << y << std::endl;
      }

      for (auto&& i : path_) {
        std::cout << i.x << i.y << std::endl;
      }
      return path_;
    }
    if (visited[x][y]) {
      continue;
    }
    visited[x][y] = true;
    vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (const auto& dir : directions) {
      int dx = dir.first;
      int dy = dir.second;
      int nx = x + dx;
      int ny = y + dy;
      if (nx < 0 || nx >= walls.columns.size() || ny < 0 ||
          ny >= walls.columns[0].size()) {
        continue;
      }
      if (dy == 1 && walls.columns[x][y] == 1) {
        continue;
      }
      if (dx == 1 && walls.rows[x][y] == 1) {
        continue;
      }
      if (dy == -1 && walls.columns[x][y - 1] == 1) {
        continue;
      }
      if (dx == -1 && walls.rows[x - 1][y] == 1) {
        continue;
      }
      if (!visited[nx][ny]) {
        wave[nx][ny] = wave[x][y] + 1;
        q.push(Point(nx, ny));
      }
    }
  }
  return vector<Point>();
}
