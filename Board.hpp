#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
namespace pandemic {
class Location {
public:
  set<City> connections;
  bool laboratoryEx;
  Color color;
  int numOfCubes;
  Location() {}
  Location(set<City> &connections, Color color)
      : connections(connections), color(color) {
    laboratoryEx = false;
    numOfCubes = 0;
  }
};

class Board {
  static map<City, Location> loc;

public:
  Board() {} //*TODO: Mannualy add all the connections .
  int &operator[](City c);
  friend ostream &operator<<(ostream &os, Board &board);
  bool is_clean();
  bool isConnected(City from, City to);
  bool labExists(City city);
  void makeLab(City city);
};
} // namespace pandemic