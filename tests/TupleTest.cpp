#include <catch2/catch.hpp>
#include "../src/Tuple.h"

namespace RT {

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

SCENARIO("Point() creates tuples with w = 1.0", "[tuple]") {
  GIVEN("p is a point") {
    auto p = Point(4, -4, 3);
    THEN("p is a tuple with w = 1.0") {
      REQUIRE(p.getX() == 4);
      REQUIRE(p.getY() == -4);
      REQUIRE(p.getZ() == 3);
      REQUIRE(p.getW() == 1.0);
      REQUIRE(p.isPoint());
      REQUIRE(!p.isVector());
    }
  }
}

SCENARIO("Vector() creates tuples with w = 0.0", "[tuple]") {
  GIVEN("p is a vector") {
    auto p = Vector(4, -4, 3);
    THEN("p is a tuple with w = 0.0") {
      REQUIRE(p.getX() == 4);
      REQUIRE(p.getY() == -4);
      REQUIRE(p.getZ() == 3);
      REQUIRE(p.getW() == 0.0);
      REQUIRE(!p.isPoint());
      REQUIRE(p.isVector());
    }
  }
}
}
