//* Just sketches nothing smart here.
#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <map>
#include <set>
#include <string>
using namespace std;
namespace pandemic {
class Virologist : public Player {
public:
  Virologist(Board &board, City city) : Player(board, city) {}
  Player &treat(City city) override;
  string role() override;
};
} // namespace pandemic