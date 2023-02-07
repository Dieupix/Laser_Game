//Declaring libraries
#include "viewerOnTerminal.h"

//---------- Constructors------------------------------
viewerOnTerminal::viewerOnTerminal(char car_blank, unsigned space) :  blank{car_blank},
                                                                      spacing{space}
{}
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void viewerOnTerminal::setBlank(char new_blank)
{
    this->blank = new_blank;
}

void viewerOnTerminal::setSpacing(unsigned new_space)
{
    this->spacing = new_space;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
char viewerOnTerminal::getBlank() const
{
    return this->blank;
}

unsigned viewerOnTerminal::getSpacing() const
{
    return this->spacing;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
void viewerOnTerminal::print(const unique_ptr<object>& obj) const
{
    //There are many possibilities (1 per object)
    //If this object is a laser
    if(dynamic_cast<laser*>(obj.get()))
    {
        auto print_laser = dynamic_cast<laser*>(obj.get());
        printLaser(*print_laser);
    }
    //If this object is a mirror
    else if(dynamic_cast<mirror*>(obj.get()))
    {
        auto print_mirror = dynamic_cast<mirror*>(obj.get());
        printMirror(*print_mirror);
    }
    //If this object is a shooter
    else if(dynamic_cast<shooter*>(obj.get()))
    {
        auto print_shooter = dynamic_cast<shooter*>(obj.get());
        printShooter(*print_shooter);
    }
    //If this object is a target
    else if(dynamic_cast<target*>(obj.get()))
    {
        auto print_target = dynamic_cast<target*>(obj.get());
        printTarget(*print_target);
    }
    //If this object is a wall
    else if(dynamic_cast<wall*>(obj.get()))
    {
        auto print_wall = dynamic_cast<wall*>(obj.get());
        printWall(*print_wall);
    }
    //If this object is an unknown type
    else
        cerr << "Unknown type" << endl;
}

void viewerOnTerminal::printGround(const ground& g) const
{
    for(unsigned i = 0; i < g.getNbCellsHeight(); ++i)
    {
        for(unsigned j = 0; j < g.getNbCellsWidth(); ++j)
        {
            if(g.getObjects()[i][j])
                print(g.getObjects()[i][j]);
            else
                cout << blank;
            for(unsigned i = 0; i < spacing; ++i)
                cout << ' ';
        }
        if(spacing == 0)
            cout << endl;
        else
            for(unsigned i = 0; i < spacing; ++i)
                cout << endl;
    }
}

void viewerOnTerminal::printLaser(const laser& l) const
{
    //There are 4 possibilities
    switch(l.getDirection())
    {
        //RIGHT or LEFT
        case RIGHT:
        case LEFT:
            {
                cout << '-';
                break;
            }
        //UP or DOWN
        case UP:
        case DOWN:
            {
                cout << '|';
                break;
            }
        default:
            {
                cerr << "ERROR : Direction is not defined" << endl;
                break;
            }
    }
}

void viewerOnTerminal::printMirror(const mirror& m) const
{
    //There are 2 possibilities
    switch(m.getSens())
    {
        case hautGauche_basDroit:
            {
                cout << '\\';
                break;
            }
        case basGauche_hautDroit:
            {
                cout << '/';
                break;
            }
        default:
            cerr << "ERROR : Sens is not defined" << endl;
            break;
    }
}

void viewerOnTerminal::printShooter(const shooter& s) const
{
    //There are 4 possibilities
    switch(s.getDirection())
    {
        case RIGHT:
            {
                cout << '>';
                break;
            }
        case LEFT:
            {
                cout << '<';
                break;
            }
        case UP:
            {
                cout << '^';
                break;
            }
        case DOWN:
            {
                cout << 'v';
                break;
            }
        default:
            {
                cerr << "ERROR : Direction is not defined" << endl;
                break;
            }
    }
}

void viewerOnTerminal::printTarget(const target&) const
{
    cout << 'O';
}

void viewerOnTerminal::printWall(const wall&) const
{
    cout << '#';
}
//---------- End of methods ----------------------------
