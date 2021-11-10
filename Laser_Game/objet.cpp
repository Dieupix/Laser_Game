#include "objet.h"
#include "point.h"

/** Constructeur d'objet
@param p : un point x,y
@return un objet o{p}
*/
objet::objet(point p) : d_p{p}
{}

/** Constructeur par defaut d'objet
@return un objet o{0,0}
*/
 objet::objet() : d_p{0,0}
{}

/** Setter de point d'un objet
@param p : le nouveau point de l'objet
*/
void objet::setPoint(const point& p)
{
    d_p = p;
}

/**Getter de point d'un objet
@return le point de l'objet courant
*/
point objet::getPoint() const
{
    return d_p;
}
