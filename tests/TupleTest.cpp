#include <catch2/catch.hpp>
#include "../src/Tuple.h"

SCENARIO("A tuple with w = 1.0 is a point", "[tuple]") {
  GIVEN("A is a tuple with w = 1.0 ") {
    auto a = Tuple(4.3, -4.2, 3.1, 1.0);
    THEN("a is a point") {
      REQUIRE(a.x == 4.3);
      REQUIRE(a.y == -4.2);
      REQUIRE(a.z == 3.1);
      REQUIRE(a.w == 1.0);
    }
  }
}
