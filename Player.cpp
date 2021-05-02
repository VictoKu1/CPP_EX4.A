#include "Player.hpp"
#include <stdexcept>
using namespace std;
using namespace pandemic;
bool Player::hasCard(City city) {
  if (cards.count(city)) {
    return true;
  }
  return false;
}
Player &Player::drive(City city) {
  if (!hasCard(city)) {
    throw invalid_argument{"TODO!!!!!!!!!!!"};
  }
  if (board.isConnected(currentLoc, city)) {
    cards.erase(city);
    currentLoc = city;
    return *this;
  }
  throw invalid_argument{"TODO!!!!!!!!!!!"};
}
Player &Player::fly_direct(City city) {
  if (!hasCard(city)) {
    throw invalid_argument{"TODO!!!!!!!!!!!"};
  }
  currentLoc = city;
  cards.erase(city);
  return *this;
}
Player &Player::fly_charter(City city) {
  if (!hasCard(city)) {
    throw invalid_argument{"TODO!!!!!!!!!!!"};
  }
  if (hasCard(currentLoc)) {
    currentLoc = city;
    cards.erase(currentLoc);
    return *this;
  }
  throw invalid_argument{"TODO!!!!!!!!!!!"};
}
Player &Player::fly_shuttle(City city) {
  if (board.labExists(currentLoc)) {
    if (board.labExists(city)) {
      cards.erase(currentLoc);
      return *this;
    }
    throw invalid_argument{"TODO!!!!!!!!!!!"};
  }
  throw invalid_argument{"TODO!!!!!!!!!!!"};
}
Player &Player::build() {
  if (board.labExists(currentLoc)) {
    return *this;
  }
  board.makeLab(currentLoc);
  return *this;
}
Player &Player::discover_cure(Color color) {
  //*TODO.
  return *this;
}
Player &Player::treat(City city) {
  //*TODO.
  return *this;
}
Player &Player::take_card(City city) {
  //*TODO.
  return *this;
}