#ifndef TUPLE_H
#define TUPLE_H

namespace RT {

class Tuple {
  public:
    Tuple(double x, double y, double z, double w) 
      : x(x), y(y), z(z), w(w) {
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


  private:
    double x;
    double y;
    double z;
    double w;

};

class Point : public Tuple {
  public:
    Point(double x, double y, double z) 
      : Tuple(x, y, z, 1.0) { }
};

class Vector : public Tuple {
  public:
    Vector(double x, double y, double z) 
      : Tuple(x, y, z, 0.0) { }
};

}
#endif
