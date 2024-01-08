#include "pathFinder.h"

#include <iostream>

void PathFinder::findPath(const RowsAndColumns& walls, const Point& start,
                          const Point& end) {
  vector<vector<bool>> visited(walls.columns.size(),
                               vector<bool>(walls.columns[0].size(), false));
  vector<vector<int>> wave(walls.columns.size(),
                           vector<int>(walls.columns[0].size(), -1));
  wave[start.y][start.x] = 0;
  std::deque<Point> q;
  q.push_back(start);
  while (!q.empty()) {
    Point current = q.front();
    q.pop_front();
    size_t y = current.y;
    size_t x = current.x;
    if (y == end.y && x == end.x) {
      path_.push_back(end);
      while (!(x == start.x && y == start.y)) {
        int dx = 0;
        int dy = 0;
        if (x > 0 && wave[y][x - 1] == wave[y][x] - 1 &&
            walls.columns[y][x - 1] == 0) {
          dx = -1;
        } else if (x < walls.columns.size() - 1 &&
                   wave[y][x + 1] == wave[y][x] - 1 &&
                   walls.columns[y][x] == 0) {
          dx = 1;
        } else if (y > 0 && wave[y - 1][x] == wave[y][x] - 1 &&
                   walls.rows[y - 1][x] == 0) {
          dy = -1;
        } else if (y < walls.columns[0].size() - 1 &&
                   wave[y + 1][x] == wave[y][x] - 1 && walls.rows[y][x] == 0) {
          dy = 1;
        }
        x += dx;
        y += dy;
        path_.insert(path_.begin(), Point(x, y));
      }
      return;
    }
    if (visited[y][x]) {
      continue;
    }
    visited[y][x] = true;
    static int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (const auto& dir : directions) {
      int dx = dir[0];
      int dy = dir[1];
      int nx = x + dx;
      int ny = y + dy;
      if (nx < 0 || nx >= walls.columns.size() || ny < 0 ||
          ny >= walls.columns[0].size()) {
        continue;
      }
      if (dy == 1 && walls.rows[y][x] == 1) {
        continue;
      }
      if (dx == 1 && walls.columns[y][x] == 1) {
        continue;
      }
      if (dy == -1 && walls.rows[y - 1][x] == 1) {
        continue;
      }
      if (dx == -1 && walls.columns[y][x - 1] == 1) {
        continue;
      }
      if (!visited[ny][nx]) {
        wave[ny][nx] = wave[y][x] + 1;
        q.push_back(Point(nx, ny));
      }
    }
  }
}

void PathFinder::cleanPath() { path_.clear(); }

vector<Point> PathFinder::GetPath() { return path_; }
