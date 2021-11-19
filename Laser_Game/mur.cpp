#include "mur.h"

#include "objet.h"
#include "point.h"
#include "laser.h"

/**Constructeur de la classe mur initialise a faux pour sa donnee estTouche
@param p : un point (x,y)
@return un mur m{false} avec une position*/
mur::mur(const point& p) : d_affected{false}, objet{p}
{}

/**Getter du mur lui-meme
@return le mur
*/
mur mur::getMur() const
{
    return *this;
}

/**Bouge le mur
@param p : la nouvelle position du mur
*/
void mur::moveMur(const point& p)
{
   move(p);
}

/**Bouge le mur
@param x : la nouvelle coordonnee en abscisse
@param y : la nouvelle coordonnee en ordonnee
*/
void mur::moveMur(double x, double y)
{
    move(x,y);
}

/**Dis si le mur a ete touche par un laser
@param l : le laser
@return VRAI si il a ete touche, FAUX sinon*/
bool mur::isAffected(const laser& l) const
{
    if(getPosition() == l.getPosition())
        return true;
    else return false;
}

/**Change la donnee du mur estTouche
*/
void mur::changeAffected()
{
    d_affected = !d_affected;
}

/**Imprime le mur
@param ost : le flot de sortie
*/
void mur::print(std::ostream& ost) const
{
    getPosition().print(ost);
}
