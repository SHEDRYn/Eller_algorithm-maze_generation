#include <iostream>

#include "../src/Maze/Controller/controller.h"

void print(Controller c) {
  std::cout << "=============" << std::endl;
  for (auto i : c.GetPath()) {
    std::cout << "x:" << i.x << " y:" << i.y << std::endl;
  }
  std::cout << "-------------" << std::endl;
}

int main() {
  Controller c;
  c.loadMap("/Users/karim/school21/A1_Maze/src/Maze/testFile.txt");
  c.loadPath(c.GetData(), Point(1, 0), Point(2, 0));
  print(c);
  c.cleanPath();
  c.loadPath(c.GetData(), Point(0, 0), Point(1, 0));
  print(c);
  c.cleanPath();
  c.loadPath(c.GetData(), Point(0, 0), Point(3, 0));
  print(c);
  c.cleanPath();
  c.loadPath(c.GetData(), Point(0, 0), Point(3, 3));
  print(c);
  print(c);
  c.cleanPath();
  c.loadPath(c.GetData(), Point(3, 0), Point(2, 0));
  print(c);
  c.cleanPath();
  c.loadPath(c.GetData(), Point(3, 1), Point(3, 0));
  print(c);
}