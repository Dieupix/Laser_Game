#include "viewerOnWINBGI.h"

// ---------- Constructors ----------

viewerOnWINBGI::viewerOnWINBGI() : height{500}, width {500}, scale{10}
{
    ///@TODO - Open graph here
}

viewerOnWINBGI::viewerOnWINBGI(unsigned w, unsigned h, unsigned s = 10) : height{h}, width{w}, scale{s}
{
    ///@TODO - Open graph here
}

// ---------- End of constructors ----------

// ---------- Destructor ----------

viewerOnWINBGI::~viewerOnWINBGI()
{
    ///@TODO - Close graph here
}

// ---------- End of destructor ----------

// ---------- Overloads ----------

// ---------- End of overloads ----------

// ---------- Getters ----------

unsigned viewerOnWINBGI::getHeight() const {return this->height;}

unsigned viewerOnWINBGI::getWidth() const {return this->width;}

unsigned viewerOnWINBGI::getScale() const {return this->scale;}

// ---------- End of getters ----------

// ---------- Setters ----------

void viewerOnWINBGI::setHeight(unsigned h)
{
    this->height = h;
}

void viewerOnWINBGI::setWidth(unsigned w)
{
    this->width = w;
}

void viewerOnWINBGI::setScale(unsigned s)
{
    this->scale = s;
}

// ---------- End of setters ----------

// ---------- Functions --------

void viewerOnWINBGI::print(const unique_ptr<object>& obj) const
{
    if(dynamic_cast<laser*>(obj.get())) // For the laser
    {
        auto tmp = dynamic_cast<laser*>(obj.get());
        printLaser(*tmp);

    }
    else if(dynamic_cast<mirror*>(obj.get())) // For the mirror
    {
        auto tmp = dynamic_cast<mirror*>(obj.get());
        printMirror(*tmp);

    }
    else if(dynamic_cast<shooter*>(obj.get())) // For the shooter
    {
        auto tmp = dynamic_cast<shooter*>(obj.get());
        printShooter(*tmp);

    }
    else if(dynamic_cast<target*>(obj.get())) // For the target
    {
        auto tmp = dynamic_cast<target*>(obj.get());
        printTarget(*tmp);

    }
    else if(dynamic_cast<wall*>(obj.get())) // For the wall
    {
        auto tmp = dynamic_cast<wall*>(obj.get());
        printWall(*tmp);

    }
    else
        cerr << "Unknown type" << endl;
}

void viewerOnWINBGI::printGround(const ground& g) const
{
    for(unsigned i = 0; i < g.getNbCellsHeight(); ++i)
    {
        for(unsigned j = 0; j < g.getNbCellsWidth(); ++j)
        {
            if(g.getObjects()[i][j])
                ///@TODO - Print objects using the scale variable member
                print(g.getObjects()[i][j]);
        }
    }
}

void viewerOnWINBGI::printLaser(const laser& l) const
{
    switch(l.getDirection())
    {
    case RIGHT:
    case LEFT:
        {
            cout << '-';
            break;
        }
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

void viewerOnWINBGI::printMirror(const mirror& m) const
{
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

void viewerOnWINBGI::printShooter(const shooter& s) const
{
    switch(s.getDirection()){
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

void viewerOnWINBGI::printTarget(const target&) const
{
    cout << 'O';
}

void viewerOnWINBGI::printWall(const wall&) const
{
    cout << '#';
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
