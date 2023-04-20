#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>

namespace RT {

class Tuple {
public:
    Tuple(double x = 0, double y = 0, double z = 0, double w = 0)
        : x { x }
        , y { y }
        , z { z }
        , w { w } {
    }

    [[nodiscard]] auto isPoint() const -> bool {
        return w == 1.0;
    }

    [[nodiscard]] auto isVector() const -> bool {
        return w == 0.0;
    }

    [[nodiscard]] auto getX() const -> double {
        return x;
    }

    [[nodiscard]] auto getY() const -> double {
        return y;
    }

    [[nodiscard]] auto getZ() const -> double {
        return z;
    }

    [[nodiscard]] auto getW() const -> double {
        return w;
    }

    auto operator+(const Tuple& other) const -> Tuple {
        return { x + other.getX(), y + other.getY(), z + other.getZ(),
            w + other.getW() };
    }

    auto operator-(const Tuple& other) const -> Tuple {
        return { x - other.getX(), y - other.getY(), z - other.getZ(),
            w - other.getW() };
    }

    auto operator-() const -> Tuple {
        return { -x, -y, -z, -w };
    }

    auto operator*(double scaler) const -> Tuple {
        return { x * scaler, y * scaler, z * scaler, w * scaler };
    }

    auto operator/(double scaler) const -> Tuple {
        return { x / scaler, y / scaler, z / scaler, w / scaler };
    }

    [[nodiscard]] auto magnitude() const -> double {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

private:
    double x {};
    double y {};
    double z {};
    double w {};
};

class Point : public Tuple {
public:
    Point(double x, double y, double z)
        : Tuple(x, y, z, 1.0) {
    }
};

class Vector : public Tuple {
public:
    Vector(double x, double y, double z)
        : Tuple(x, y, z, 0.0) {
    }

    [[nodiscard]] auto normalize() const -> Vector {
        double length { magnitude() };
        return { getX() / length, getY() / length, getZ() / length };
    }

    [[nodiscard]] auto dot(const Vector& other) const -> double {
        return getX() * other.getX() + getY() * other.getY() + getZ() * other.getZ() + getW() * other.getW();
    }

    [[nodiscard]] auto cross(const Vector& other) const -> Vector {
        return { getY() * other.getZ() - getZ() * other.getY(),
            getZ() * other.getX() - getX() * other.getZ(),
            getX() * other.getY() - getY() * other.getX() };
    }
};
}
#endif
