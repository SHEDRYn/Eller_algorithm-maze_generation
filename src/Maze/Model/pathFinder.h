#ifndef SRC_MAZE_MODEL_PATHFINDER_H
#define SRC_MAZE_MODEL_PATHFINDER_H

#include <queue>

#include "dataTypes.h"

using std::queue;

class PathFinder {
 public:
  PathFinder() = default;

  Point start;
  Point end;

  vector<Point> findPath(const RowsAndColumns walls, const Point start,
                         const Point end);

 private:
  vector<Point> path_;
};

#endif  // SRC_MAZE_MODEL_PATHFINDER_H
