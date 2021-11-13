#include "objet.h"
#include "point.h"
#include <iostream>

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

/**Deplace l'objet de x, y
@param x : le deplacement en abscisse (reel)
@param y : le deplacement en ordonnee (reel)
*/
void objet::shift(double x, double y)
{
    d_p.shift(x,y);
}

/**Deplace l'objet par translation de p(x,y)
@param x : le deplacement en abscisse (reel)
@param y : le deplacement en ordonnee (reel)
*/
void objet::shift(const point& p)
{
    d_p.shift(p.x(),p.y());
}

/**Imprime l'objet o(x,y)
@param ost : le flot de sortie
*/
void objet::print(std::ostream& ost) const
{
    d_p.print(ost);
}

/**Surcharge de l'operateur << pour permettre d'afficher un objet (cout<<o)
@param ost : le flot de sortie
@param o : l'objet
*/
void operator<<(const std::ostream& ost, const objet& o)
{
    o.print(ost);
}
