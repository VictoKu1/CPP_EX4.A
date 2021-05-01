//* Just sketches nothing smart here.
#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <string>
using namespace std;
namespace pandemic {
class Player {
  Board board;
  set<City> cards;
  City currentLoc;

public:
  Player(Board &board,City currentLoc):board(board),currentLoc(currentLoc){};
  Player& drive(City city);
  virtual Player& fly_direct(City city); //* For special dispatcher implementation .
  Player& fly_charter(City city);
  Player& fly_shuttle(City city);
  virtual Player& build(); //*For special OperationExpert implementation .
  virtual Player& discover_cure(Color color); //*For special Scientist/Researcher and GeneSplicer implementation .
  virtual Player& treat(City city); //*For special Medic/Virologist and FieldDoctor implementation .
  virtual string role(); //*For everyone special implemetation .
  Player& take_card(City city);
};
} // namespace pandemic