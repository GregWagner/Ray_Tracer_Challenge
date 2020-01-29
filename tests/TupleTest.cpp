#include <catch2/catch.hpp>
#include "../src/Tuple.h"

SCENARIO("A tuple with w = 1.0 is a point", "[tuple]") {
  GIVEN("A is a tuple with w = 1.0 ") {
    auto a = Tuple(4.3, -4.2, 3.1, 1.0);
    THEN("a is a point") {
      REQUIRE(a.getX() == 4.3);
      REQUIRE(a.getY() == -4.2);
      REQUIRE(a.getZ() == 3.1);
      REQUIRE(a.getW() == 1.0);
      REQUIRE(a.isPoint());
      REQUIRE(!a.isVector());
    }
  }
}

SCENARIO("A tuple with w = 0.0 is a vector", "[tuple]") {
  GIVEN("A is a tuple with w = 0.0 ") {
    auto a = Tuple(4.3, -4.2, 3.1, 0.0);
    THEN("a is a vector") {
      REQUIRE(a.getX() == 4.3);
      REQUIRE(a.getY() == -4.2);
      REQUIRE(a.getZ() == 3.1);
      REQUIRE(a.getW() == 0.0);
      REQUIRE(!a.isPoint());
      REQUIRE(a.isVector());
    }
  }
}
