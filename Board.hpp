#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
using namespace std;
namespace pandemic {
class Location {
public:
  set<City> connections;
  bool laboratoryEx;
  Color color;
  int numOfCubes;
  Location(set<City> &connections, Color color)
      : connections(connections), color(color) {
    laboratoryEx = false;
    numOfCubes = 0;
  }
};
class Board {
  static map<City, Location> loc;
public:
  Board(){};
  int &operator[](const City c);
  friend ostream &operator<<(ostream &os, Board &board);
  bool isClean();
};
} // namespace pandemic