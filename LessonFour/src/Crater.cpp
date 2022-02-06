#include "Crater.h"

bool Crater::isInside(double xn) const {
    const double size_2 = width / 2.0;
    if (int(xn) > int(x - size_2) && xn <= int(x + size_2)) {
        return true;
    }

    return false;
}