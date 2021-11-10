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
       void setPoint(const point& p);
       point getPoint() const;
};

#endif // OBJET_H
