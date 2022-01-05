//Declaring libraries
#include"mirror.h"
#include "laser.h"

//---------- Constructors------------------------------
mirror::mirror(const point& position, sens Smirror) :   object{position} ,
                                                        d_sens{Smirror},
                                                        d_mirrortouched {false}
{}
//---------- End of constructors-----------------------
//---------- Getters-----------------------------------
sens mirror::getSens() const
{
    return d_sens ;
}
//---------- End of getters ----------------------------
//---------- Methods -----------------------------------
void mirror::changeDirectionLaser(laser& l)
{
    //There are 4 possibilities : RIGHT, LEFT, UP or DOWN
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
    string str_mirror = "Miroir[position" + getPosition().toString() + ", sens(" ;
    //There are 2 possibilities : basGauche_hautDroit or hautGauche_basDroit
    switch(getSens())
    {
        case sens::basGauche_hautDroit :
            {
                str_mirror += "basGauche_hautDroit";
                break;
            }
        case sens::hautGauche_basDroit :
            {
                str_mirror += "hautGauche_basDroit";
                break ;
            }
    }

    str_mirror += "), affected(" + string(d_mirrortouched ? "true" : "false") + ")]";
    return str_mirror;
}
//---------- End of methods ----------------------------

