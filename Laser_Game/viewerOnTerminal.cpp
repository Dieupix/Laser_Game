#include "viewerOnTerminal.h"

// ---------- Constructors ----------

viewerOnTerminal::viewerOnTerminal(char blank, unsigned spacing) : blank{blank}, spacing{spacing} {}

// ---------- End of constructors ----------

// ---------- Destructor ----------

// ---------- End of destructor ----------

// ---------- Overloads ----------

// ---------- End of overloads ----------

// ---------- Getters ----------

char viewerOnTerminal::getBlank() const {return this->blank;}

unsigned viewerOnTerminal::getSpacing() const {return this->spacing;}

// ---------- End of getters ----------

// ---------- Setters ----------

void viewerOnTerminal::setBlank(char blank)
{
    this->blank = blank;
}

void viewerOnTerminal::setSpacing(unsigned spacing)
{
    this->spacing = spacing;
}

// ---------- End of setters ----------

// ---------- Functions --------

void viewerOnTerminal::print(const unique_ptr<object>& obj) const
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

            for(unsigned i = 0; i < spacing; ++i) cout << ' ';
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

void viewerOnTerminal::printMirror(const mirror& m) const
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

void viewerOnTerminal::printShooter(const shooter& s) const
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

void viewerOnTerminal::printTarget(const target&) const
{
    cout << 'O';
}

void viewerOnTerminal::printWall(const wall&) const
{
    cout << '#';
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
