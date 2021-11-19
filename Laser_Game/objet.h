#ifndef OBJET_H
#define OBJET_H

#include "point.h"

class objet
{
   private :
       point d_p;
   protected:
       objet(point p);
       objet();
   public :
       virtual ~objet() = default;
       void setPosition(const point& p);
       point getPosition() const;
       void shift(double x, double y);
       void shift(const point& p);
       void move(const point& p);
       void move(double x, double y);
       virtual void print(std::ostream& ost) const;
};

std::ostream& operator<<(std::ostream& ost, const objet& o);

#endif // OBJET_H
