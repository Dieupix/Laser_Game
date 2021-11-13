#ifndef OBJET_H
#define OBJET_H

#include "point.h"

class objet
{
   private :
       point d_p;
   public :
       objet(point p);
       objet();
       virtual ~objet() = default;
       void setPoint(const point& p);
       point getPoint() const;
       void shift(double x, double y);
       void shift(const point& p);
       virtual void print(std::ostream& ost) const;
};

void operator<<(const std::ostream& ost; const objet& o);

#endif // OBJET_H
