#ifndef MODEL_POINT_H
#define MODEL_POINT_H

struct Point {
  int x = 0;
  int y = 0;
  Point() = default;
  Point(int _x, int _y) : x(_x), y(_y) {}
};

#endif // MODEL_POINT_H