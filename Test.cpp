#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "OperationsExpert.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace pandemic;
TEST_CASE("Right connectivity test for Algiers.") {
  Board board;
  OperationsExpert builder{board, City::Algiers};
  CHECK_NOTHROW(builder.drive(Madrid));
  CHECK_NOTHROW(builder.drive(Algiers));
  CHECK_NOTHROW(builder.drive(Paris));
  CHECK_NOTHROW(builder.drive(Algiers));
  CHECK_NOTHROW(builder.drive(Istanbul));
  CHECK_NOTHROW(builder.drive(Algiers));
  CHECK_NOTHROW(builder.drive(Cairo));
  CHECK_NOTHROW(builder.drive(Algiers));
}
TEST_CASE("Right connectivity test for Atlanta.") {
  Board board;
  OperationsExpert builder{board, City::Atlanta};
  CHECK_NOTHROW(builder.drive(Chicago));
  CHECK_NOTHROW(builder.drive(Atlanta));
  CHECK_NOTHROW(builder.drive(Miami));
  CHECK_NOTHROW(builder.drive(Atlanta));
  CHECK_NOTHROW(builder.drive(Washington));
  CHECK_NOTHROW(builder.drive(Atlanta));
}
TEST_CASE("Right connectivity test for Baghdad.") {
  Board board;
  OperationsExpert builder{board, City::Atlanta};
  CHECK_NOTHROW(builder.drive(Tehran));
  CHECK_NOTHROW(builder.drive(Baghdad));
  CHECK_NOTHROW(builder.drive(Istanbul));
  CHECK_NOTHROW(builder.drive(Baghdad));
  CHECK_NOTHROW(builder.drive(Cairo));
  CHECK_NOTHROW(builder.drive(Baghdad));
  CHECK_NOTHROW(builder.drive(Riyadh));
  CHECK_NOTHROW(builder.drive(Baghdad));
  CHECK_NOTHROW(builder.drive(Karachi));
  CHECK_NOTHROW(builder.drive(Baghdad));
}
TEST_CASE("Right connectivity test for Bangkok.") {
  Board board;
  OperationsExpert builder{board, City::Atlanta};
  CHECK_NOTHROW(builder.drive(Kolkata));
  CHECK_NOTHROW(builder.drive(Bangkok));
  CHECK_NOTHROW(builder.drive(Chennai));
  CHECK_NOTHROW(builder.drive(Bangkok));
  CHECK_NOTHROW(builder.drive(Jakarta));
  CHECK_NOTHROW(builder.drive(Bangkok));
  CHECK_NOTHROW(builder.drive(HoChiMinhCity));
  CHECK_NOTHROW(builder.drive(Bangkok));
  CHECK_NOTHROW(builder.drive(HongKong));
  CHECK_NOTHROW(builder.drive(Bangkok));
}
TEST_CASE("Right connectivity test for Beijing.") {
  Board board;
  OperationsExpert builder{board, City::Beijing};
  CHECK_NOTHROW(builder.drive(Shanghai));
  CHECK_NOTHROW(builder.drive(Beijing));
  CHECK_NOTHROW(builder.drive(Seoul));
  CHECK_NOTHROW(builder.drive(Beijing));
}