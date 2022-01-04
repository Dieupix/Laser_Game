#include"mirror.h"
#include "laser.h"
#include "object.h"


// ---------- Constructeur-------------------------------


mirror::mirror(const point& position ,sens Smirror) : object{position} , d_sens{basGauche_hautDroit},
                                  d_mirrortouched {false}
{

}
// ---------- Fin Constructeur-------------------------------





// ----------------------getSens -------------------------------

sens  mirror::getSens() const
{
    return d_sens ;
}

// ----------------------Fin getSens -------------------------------

// ---------------------- changeDirectionLaser -------------------------------

void mirror::changeDirectionLaser(laser& l ) const
{
    /*  RIGHT,
      UP,
      LEFT,
      DOWN*/
    if (estTouchee(l))
    {

       switch(d_sens)
       {
           case basGauche_hautDroit:
               {
                    if(l.getDirection() == directions::UP || l.getDirection() == directions::DOWN)
                        l.turnRight();
                    else
                        l.turnLeft();
                    break;
               }
            case hautGauche_basDroit:
                {
                    if(l.getDirection() == directions::LEFT || l.getDirection() == directions::RIGHT)
                        l.turnLeft();
                    else
                        l.turnRight();
                    break;
                }
        }
    }
}
// ---------------------- Fin changeDirectionLaser -------------------------------

unique_ptr<object> mirror::clone() const
{
    return make_unique<mirror>(*this);
}

void mirror::collide(laser& l)
{
    if(getPosition() == l.getPosition())
    {
        changeDirectionLaser(l);
    }
}

// ---------------------- estTouchee -------------------------------

bool mirror::estTouchee(laser& L ) const
{
    bool touchee = (L.getPosition() == getPosition() ) ;
    if (touchee)
    {
        changeDirectionLaser(L) ;

    }

    return(touchee ) ;
}
// ---------------------- Fin estTouchee ------------------------------

void mirror::print(std::ostream& ost) const
{
    ost << toString();
}

string mirror::toString() const
{
    string t = "Miroir[position" + getPosition().toString() + ", sens(";
    switch(getSens())
    {
        case sens::basGauche_hautDroit :{
            t += "basGauche_hautDroit";
            break;
        }
        case sens::hautGauche_basDroit :{
            t += "hautGauche_basDroit";
            break ;
        }
    }
    t += "), affected(" + string(d_mirrortouched ? "true" : "false") + ")]";

    return t;
}


