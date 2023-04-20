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

    bool isPoint() const {
        return w == 1.0;
    }

    bool isVector() const {
        return w == 0.0;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    double getW() const {
        return w;
    }

    Tuple operator+(const Tuple& other) const {
        return { x + other.getX(), y + other.getY(), z + other.getZ(),
            w + other.getW() };
    }

    Tuple operator-(const Tuple& other) const {
        return { x - other.getX(), y - other.getY(), z - other.getZ(),
            w - other.getW() };
    }

    Tuple operator-() const {
        return { -x, -y, -z, -w };
    }

    Tuple operator*(double scaler) const {
        return { x * scaler, y * scaler, z * scaler, w * scaler };
    }

    Tuple operator/(double scaler) const {
        return { x / scaler, y / scaler, z / scaler, w / scaler };
    }

    double magnitude() const {
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

    Vector normalize() const {
        double length { magnitude() };
        return { getX() / length, getY() / length, getZ() / length };
    }

    double dot(const Vector& other) const {
        return getX() * other.getX() + getY() * other.getY() + getZ() * other.getZ() + getW() * other.getW();
    }

    Vector cross(const Vector& other) const {
        return { getY() * other.getZ() - getZ() * other.getY(),
            getZ() * other.getX() - getX() * other.getZ(),
            getX() * other.getY() - getY() * other.getX() };
    }
};
}
#endif
