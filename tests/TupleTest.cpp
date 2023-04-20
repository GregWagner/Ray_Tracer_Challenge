#include "../src/Tuple.h"
#include <catch2/catch.hpp>

namespace RT {

// See page 4
SCENARIO("A tuple with w = 1.0 is a point", "[tuple]") {
    GIVEN("a is a tuple with w = 1.0 ") {
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

// See page 4
SCENARIO("A tuple with w = 0.0 is a vector", "[tuple]") {
    GIVEN("a is a tuple with w = 0.0 ") {
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

// See page 4
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

// See page 4
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

// See page 6
SCENARIO("Adding two tuples", "[tuple]") {
    GIVEN("a1 and a2 are tuples") {
        auto a1 = Tuple(3, -2, 5, 1);
        auto a2 = Tuple(-2, 3, 1, 0);
        auto a3 = a1 + a2;
        THEN("a1 + a2 = tuple(1, 1, 6, 1)") {
            REQUIRE(a3.getX() == 1);
            REQUIRE(a3.getY() == 1);
            REQUIRE(a3.getZ() == 6);
            REQUIRE(a3.getW() == 1.0);
            REQUIRE(a3.isPoint());
            REQUIRE(!a3.isVector());
        }
    }
}

SCENARIO("Adding two vectors is a vector", "[tuple]") {
    GIVEN("v1 and v2 are vectors") {
        auto v1 = Vector(3, 2, 1);
        auto v2 = Vector(5, 6, 7);
        auto v3 = v1 + v2;
        THEN("v1 + v2 = Vector(8, 8, 8)") {
            REQUIRE(v3.getX() == 8);
            REQUIRE(v3.getY() == 8);
            REQUIRE(v3.getZ() == 8);
            REQUIRE(v3.getW() == 0.0);
            REQUIRE(!v3.isPoint());
            REQUIRE(v3.isVector());
        }
    }
}

SCENARIO("Adding a point and vector is a point", "[tuple]") {
    GIVEN("p is a point and v is a vector") {
        auto p = Point(3, 2, 1);
        auto v = Vector(5, 6, 7);
        auto a = p + v;
        THEN("p - v = Point(8, 8, 8)") {
            REQUIRE(a.getX() == 8);
            REQUIRE(a.getY() == 8);
            REQUIRE(a.getZ() == 8);
            REQUIRE(a.getW() == 1.0);
            REQUIRE(a.isPoint());
            REQUIRE(!a.isVector());
        }
    }
}

// See page 6
SCENARIO("Subtracting two points is a vector", "[tuple]") {
    GIVEN("p1 and p2 are points") {
        auto p1 = Point(3, 2, 1);
        auto p2 = Point(5, 6, 7);
        auto p3 = p1 - p2;
        THEN("p1 - p2 = Vector(-2, -4, -6)") {
            REQUIRE(p3.getX() == -2);
            REQUIRE(p3.getY() == -4);
            REQUIRE(p3.getZ() == -6);
            REQUIRE(p3.getW() == 0.0);
            REQUIRE(!p3.isPoint());
            REQUIRE(p3.isVector());
        }
    }
}

// See page 6
SCENARIO("Subtracting a vector from a point is a point", "[tuple]") {
    GIVEN("v is a vector and p is a point") {
        auto p = Point(3, 2, 1);
        auto v = Vector(5, 6, 7);
        auto a = p - v;
        THEN("p - v = Point(-2, -4, -6)") {
            REQUIRE(a.getX() == -2);
            REQUIRE(a.getY() == -4);
            REQUIRE(a.getZ() == -6);
            REQUIRE(a.getW() == 1.0);
            REQUIRE(a.isPoint());
            REQUIRE(!a.isVector());
        }
    }
}

// See page 7
SCENARIO("Subtracting two vector is a point", "[tuple]") {
    GIVEN("v1 and v2 are vectors") {
        auto v1 = Vector(3, 2, 1);
        auto v2 = Vector(5, 6, 7);
        auto v = v1 - v2;
        THEN("v1 - v2 = Vector(-2, -4, -6)") {
            REQUIRE(v.getX() == -2);
            REQUIRE(v.getY() == -4);
            REQUIRE(v.getZ() == -6);
            REQUIRE(v.getW() == 0.0);
            REQUIRE(!v.isPoint());
            REQUIRE(v.isVector());
        }
    }
}

// See page 7 (see negating a vector below)
SCENARIO("Subtracing a vector from the zero vector negates the vector", "[tuple]") {
    GIVEN("zero is the zero vecctor and v is a vector") {
        auto zero = Vector(0, 0, 0);
        auto v = Vector(1, -2, 3);
        auto a = zero - v;
        THEN("zero - v = Vector(-1, 2, -3)") {
            REQUIRE(a.getX() == -1);
            REQUIRE(a.getY() == 2);
            REQUIRE(a.getZ() == -3);
            REQUIRE(a.getW() == 0.0);
            REQUIRE(!a.isPoint());
            REQUIRE(a.isVector());
        }
    }
}

// See page 7
SCENARIO("Negating a tuple", "[tuple]") {
    GIVEN("a is a tuple") {
        auto a = Tuple(1, -2, 3, -4);
        auto negated_a = -a;
        THEN("-a = Tuple(-1, 2, -3, 4)") {
            REQUIRE(negated_a.getX() == -1);
            REQUIRE(negated_a.getY() == 2);
            REQUIRE(negated_a.getZ() == -3);
            REQUIRE(negated_a.getW() == 4);
        }
    }
}

// See page 8
SCENARIO("Multiplying a tuple by a scalar", "[tuple]") {
    GIVEN("t is a tuple") {
        auto t = Tuple(1, -2, 3, -4);
        auto a = t * 3.5;
        THEN("p - v = Tuple(3.5, -7, 10.5, -14)") {
            REQUIRE(a.getX() == 3.5);
            REQUIRE(a.getY() == -7);
            REQUIRE(a.getZ() == 10.5);
            REQUIRE(a.getW() == -14);
        }
    }
}

// See page 8
SCENARIO("Multiplying a tuple by a fraction", "[tuple]") {
    GIVEN("t is a tuple") {
        auto t = Tuple(1, -2, 3, -4);
        auto a = t * 0.5;
        THEN("p - v = Tuple(0.5, -1, 1.5, -2)") {
            REQUIRE(a.getX() == 0.5);
            REQUIRE(a.getY() == -1);
            REQUIRE(a.getZ() == 1.5);
            REQUIRE(a.getW() == -2);
        }
    }
}

// See page 8
SCENARIO("Dividing a tuple by a scalar", "[tuple]") {
    GIVEN("t is a tuple") {
        auto t = Tuple(1, -2, 3, -4);
        auto a = t / 2;
        THEN("p - v = Tuple(0.5, -1, 1.5, -2)") {
            REQUIRE(a.getX() == 0.5);
            REQUIRE(a.getY() == -1);
            REQUIRE(a.getZ() == 1.5);
            REQUIRE(a.getW() == -2);
        }
    }
}

// See page 8
SCENARIO("Computing the magnitude of vector(1, 0, 0)", "[tuple]") {
    GIVEN("v is a vector(1, 0, 0)") {
        auto v = Vector(1, 0, 0);
        THEN("magnitude (v) = 1") {
            REQUIRE(v.magnitude() == Approx(1));
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 0, 1)", "[tuple]") {
    GIVEN("v is a vector(0, 0, 1)") {
        auto v = Vector(0, 0, 1);
        THEN("magnitude (v) = 1") {
            REQUIRE(v.magnitude() == Approx(1));
        }
    }
}

SCENARIO("Computing the magnitude of vector(1, 2, 3)", "[tuple]") {
    GIVEN("v is a vector(1, 2, 3)") {
        auto v = Vector(1, 2, 3);
        THEN("magnitude (v) = square root(14)") {
            REQUIRE(v.magnitude() == Approx(sqrt(14)));
        }
    }
}

SCENARIO("Normalizing vector(4, 0, 0) gives (1, 0, 0)", "[tuple]") {
    GIVEN("v is a vector(4, 0, 0)") {
        auto v = Vector(4, 0, 0);
        v = v.normalize();
        THEN("normalize (v) = (1, 0, 0)") {
            REQUIRE(v.getX() == Approx(1));
            REQUIRE(v.getY() == Approx(0));
            REQUIRE(v.getZ() == Approx(0));
            REQUIRE(v.getW() == 0);
            REQUIRE(!v.isPoint());
            REQUIRE(v.isVector());
        }
    }
}

SCENARIO("Normalizing vector(1, 2, 3)", "[tuple]") {
    GIVEN("v is a vector(1, 2, 3)") {
        auto v = Vector(1, 2, 3);
        v = v.normalize();
        THEN("normalize(v) = (1, 0, 0)") {
            REQUIRE(v.getX() == Approx(1 / sqrt(14)));
            REQUIRE(v.getY() == Approx(2 / sqrt(14)));
            REQUIRE(v.getZ() == Approx(3 / sqrt(14)));
            REQUIRE(v.getW() == 0);
            REQUIRE(!v.isPoint());
            REQUIRE(v.isVector());
        }
    }
}

SCENARIO("The magnitude of a normalized vector", "[tuple]") {
    GIVEN("v is a vector(1, 2, 3)") {
        auto v = Vector(1, 2, 3);
        v = v.normalize();
        THEN("magnitude(norm) = 1)") {
            REQUIRE(v.magnitude() == 1);
        }
    }
}

SCENARIO("The dot product of two tuples", "[tuple]") {
    GIVEN("a and b are vectors") {
        auto a = Vector(1, 2, 3);
        auto b = Vector(2, 3, 4);
        auto answer = a.dot(b);
        THEN("a.dot(b) = 20") {
            REQUIRE(answer == 20);
        }
    }
}

SCENARIO("The cross product of two tuples", "[tuple]") {
    GIVEN("a and b are vectors") {
        auto a = Vector(1, 2, 3);
        auto b = Vector(2, 3, 4);
        auto answer = a.cross(b);
        auto answer1 = b.cross(a);
        THEN("a.dot(b) = 20") {
            REQUIRE(answer.getX() == -1);
            REQUIRE(answer.getY() == 2);
            REQUIRE(answer.getZ() == -1);
            REQUIRE(answer.getW() == 0.0);
            REQUIRE(!answer.isPoint());
            REQUIRE(answer.isVector());

            REQUIRE(answer1.getX() == 1);
            REQUIRE(answer1.getY() == -2);
            REQUIRE(answer1.getZ() == 1);
            REQUIRE(answer1.getW() == 0.0);
            REQUIRE(!answer1.isPoint());
            REQUIRE(answer1.isVector());
        }
    }
}
}