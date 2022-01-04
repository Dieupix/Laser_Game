#ifndef OBJECT_H
#define OBJECT_H

#include "enumTypes.h"
#include "point.h"

#include <memory>

using std::make_unique;
using std::unique_ptr;

class laser;

class object
{
    friend object createObjectForTest(const point&);

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

       virtual void collide(laser& l);
       virtual unique_ptr<object> clone() const;
       virtual void print(std::ostream& ost) const;
       virtual string toString() const;

       bool operator==(const object& o) const;
       bool operator!=(const object& o) const;
};

std::ostream& operator<<(std::ostream& ost, const object& o);
object createObjectForTest(const point&);

#endif // OBJET_H
