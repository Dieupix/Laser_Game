#ifndef OBJECT_H
#define OBJECT_H

#include "point.h"

class object
{
   private :
       point d_p;
   protected:
       object(point p);
       object();
   public :
       virtual ~object() = default;
       void setPosition(const point& p);
       point getPosition() const;
       void shift(double x, double y);
       void shift(const point& p);
       void move(const point& p);
       void move(double x, double y);
       virtual void print(std::ostream& ost) const = 0;
       bool operator==(const object& o) const;
       bool operator!=(const object& o) const;
};

std::ostream& operator<<(std::ostream& ost, const object& o);

#endif // OBJET_H
