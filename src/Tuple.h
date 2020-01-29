#ifndef TUPLE_H
#define TUPLE_H

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

#endif
