#include "Board.hpp"
using namespace std;
using namespace pandemic;
int &Board::operator[](City city) { return loc[city].numOfCubes; }
ostream &operator<<(ostream &os, Board &board) {
  return (os << "TODO." << endl);
}
bool Board::is_clean() {
  for (auto &place : loc) {
    if (place.second.numOfCubes > 0) {
      return false;
    }
  }
  return true;
}
bool Board::isConnected(City from, City to) {
  return loc[from].connections.count(to);
}
bool Board::labExists(City city) { return loc[city].laboratoryEx; }
void Board::makeLab(City city){
    loc[city].laboratoryEx=true;
}