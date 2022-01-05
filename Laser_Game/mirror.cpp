#include"mirror.h"
#include "laser.h"
#include "object.h"


// ---------- Constructeur-------------------------------


mirror::mirror(const point& position ,sens Smirror) : object{position} , d_sens{Smirror},
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

void mirror::changeDirectionLaser(laser& l )
{
    /*
        RIGHT,
        UP,
        LEFT,
        DOWN
    */

    switch(d_sens)
    {
    case basGauche_hautDroit:
        {
            if(l.getDirection() == UP || l.getDirection() == DOWN)
                l.turnRight();
            else
                l.turnLeft();

            break;
        }
    case hautGauche_basDroit:
        {
            if(l.getDirection() == RIGHT || l.getDirection() == LEFT)
                l.turnRight();
            else
                l.turnLeft();

            break;
        }
    default:
        {
            std::cerr << "ERROR: Sens is not defined" << std::endl;
            break;
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
        d_mirrortouched = true;
        changeDirectionLaser(l);
    }
}

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


