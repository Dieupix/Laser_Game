#include "ground.h"

#include <sstream>
#include <string>

using std::string;
using std::stringstream;
using std::to_string;

// ---------- Constructors ----------

ground::ground() : grid{1, 1}, position{0, 0}, nbCellsWidth{0}, nbCellsHeight{0}, nbOfObjects{0}, nbOfMirrors{0}, nbMirrorMax{0}
{}

ground::ground(const point& position, double cellsWidth, double cellsHeight, unsigned nbCellsWidth, unsigned nbCellsHeight, unsigned nbMirrorMax) :
    grid{cellsWidth, cellsHeight}, position{position}, nbCellsWidth{nbCellsWidth}, nbCellsHeight{nbCellsHeight}, nbOfObjects{0}, nbOfMirrors{0}, nbMirrorMax{nbMirrorMax}
{
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
        objects[i].resize(nbCellsWidth);
}

ground::ground(const ground& g) :
    grid{g.getCellsWidth(), g.getCellsHeight()}, position{g.getPosition()}, nbCellsWidth{g.getNbCellsWidth()}, nbCellsHeight{g.getNbCellsHeight()}, nbOfObjects{g.getNbOfObjects()}, nbOfMirrors{g.getNbOfMirrors()}
{
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        objects[i].resize(nbCellsWidth);
        for(unsigned j = 0; j < g.getObjects()[i].size(); ++j)
        {
            auto obj = g.getObjects()[i][j].get()->clone();
            objects[i][j] = move(obj);
        }
    }
}

// ---------- End of constructors ----------

// ---------- Destructor ----------

// ---------- End of destructor ----------

// ---------- Overloads ----------

ground ground::operator=(const ground& g) const
{
   return {g};
}

ground& ground::operator=(const ground& g)
{
    if(this != &g)
    {
        setCellsWidth(g.getCellsWidth());
        setCellsHeight(g.getCellsHeight());
        nbCellsWidth = g.getNbCellsWidth();
        nbCellsHeight = g.getNbCellsHeight();

        objects.resize(nbCellsHeight);
        for(unsigned i = 0; i < nbCellsHeight; ++i)
        {
            objects[i].resize(nbCellsWidth);
            for(unsigned j = 0; j < nbCellsWidth; ++j)
            {
                auto obj = g.getObjects()[i][j].get()->clone();
                objects[i][j] = move(obj);
            }
        }

        nbOfObjects = g.getNbOfObjects();
        nbOfMirrors = g.getNbOfMirrors();
    }

    return *this;
}

// ---------- End of overloads ----------

// ---------- Getters ----------

point ground::getPosition() const {return this->position;}

unsigned ground::getNbCellsWidth() const {return this->nbCellsWidth;}

unsigned ground::getNbCellsHeight() const {return this->nbCellsHeight;}

unsigned ground::getNbOfObjects() const {return this->nbOfObjects;}

unsigned ground::getNbOfMirrors() const {return this->nbOfMirrors;}

unsigned ground::getNbMirrorMax() const {return this->nbMirrorMax;}

const vector<vector<unique_ptr<object>>>& ground::getObjects() const {return this->objects;}

// ---------- End of getters ----------

// ---------- Setters ----------

void ground::setPosition(const point& position){
    this->position = position;
}

void ground::setNbCellsWidth(unsigned nbCellsWidth){
    this->nbCellsWidth = nbCellsWidth;
    for(unsigned i = 0; i < objects.size(); ++i)
    {
        objects[i].resize(nbCellsWidth);
    }
}

void ground::setNbCellsHeight(unsigned nbCellsHeight){
    this->nbCellsHeight = nbCellsHeight;
    objects.resize(nbCellsHeight);
}

void ground::setNbMirrorMax(unsigned nbMirrorMax)
{
    this->nbMirrorMax = nbMirrorMax;
}

// ---------- End of setters ----------

// ---------- Functions --------

void ground::addObjectAt(unique_ptr<object> obj, unsigned i, unsigned j){
    if(i > nbCellsHeight)
    {
        throw std::out_of_range("addObject: the i index is out of range");
    }
    else if(j > nbCellsWidth)
    {
        throw std::out_of_range("addObject: the j index is out of range");
    }
    else
    {
        if(!objects[i][j].get())
        {
            if(dynamic_cast<mirror*>(obj.get()))
            {
                ++nbOfMirrors;
            }

            objects[i][j] = move(obj);
            ++nbOfObjects;
        }
    }
}

const shooter& ground::getShooter() const
{
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        for(unsigned j = 0; j < nbCellsWidth; ++j)
        {
            auto obj = objects[i][j].get();
            if(obj)
            {
                if(dynamic_cast<shooter*>(obj))
                {
                    return *dynamic_cast<shooter*>(obj);
                }
            }
        }
    }
}

void ground::loadFrom(istream& ist)
{
    cout << "Loading..." << endl;

    string loaded = "";
    auto line = 1;

    for(unsigned i = 0; i < 2; ++i)
    {
        getline(ist, loaded);

        try
        {
            double d = stod(loaded);
            if(i == 0)
            {
                setCellsWidth(d);
            }
            else
            {
                setCellsHeight(d);
            }
        }
        catch(...)
        {
            cerr << "ERROR: line " << line << endl;
        }

        ++line;
    }

    point p;
    if(ist >> p)
    {
        position = p;
    }
    ist.get();

    unsigned nbOfInter = 3;
    for(unsigned i = 0; i < nbOfInter; ++i)
    {
        getline(ist, loaded);

        try
        {
            unsigned d = stoi(loaded);

            switch(i)
            {
            case 0:
                {
                    nbCellsWidth = d;
                    break;
                }
            case 1:
                {
                    nbCellsHeight = d;
                    break;
                }
            case 2:
                {
                    nbMirrorMax = d;
                    break;
                }
            default:
                {
                    cerr << "ERROR: i = " << i << endl;
                    break;
                }
            }
        }
        catch(...)
        {
            cerr << "ERROR: line " << line << ": " << loaded << " is not a real" << endl;
        }

        ++line;
    }

    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        objects[i].resize(nbCellsWidth);
    }

    stringstream buffer;
    buffer << ist.rdbuf();
    loaded = buffer.str();

    unsigned i = 0, j = 0;
    for(unsigned k = 0; k < loaded.length(); ++k)
    {
        auto c = loaded[k];
        point pos = point{(double)j, (double)i} + position;
        switch(c)
        {
        case '.':
            {
                break;
            }
        case '\n':
        case '\r':
            {
                ++i;
                j = -1;
                ++line;
                break;
            }
        case '#':
            {
                addObjectAt(make_unique<wall>(pos), i, j);
                break;
            }
        case 'O':
            {
                addObjectAt(make_unique<target>(pos), i, j);
                break;
            }
        case '/':
        case '\\':
            {
                sens sMirror = (c == '/' ? basGauche_hautDroit : hautGauche_basDroit);
                addObjectAt(make_unique<mirror>(pos, sMirror), i, j);
                break;
            }
        case '>':
        case 'v':
        case '<':
        case '^':
            {
                directions direction;
                switch(c)
                {
                case '>':
                    {
                        direction = RIGHT;
                        break;
                    }
                case 'v':
                    {
                        direction = DOWN;
                        break;
                    }
                case '<':
                    {
                        direction = LEFT;
                        break;
                    }
                case '^':
                    {
                        direction = UP;
                        break;
                    }
                default:
                    {
                        cerr << "ERROR: line " << line << ": direction is not defined" << endl;
                        break;
                    }
                }

                addObjectAt(make_unique<shooter>(pos, direction), i, j);
                break;
            }
        default:
            {
                cerr << "ERROR: line " << line << ": undefined character" << endl;
                break;
            }
        }
        ++j;
    }

    cout << "Loaded." << endl;
}

void ground::print(ostream& ost) const
{
    ost << toString();
}

void ground::removeObjectAt(unsigned i, unsigned j)
{
    if(i > nbCellsHeight)
    {
        throw std::out_of_range("The i index is out of range");
    }
    else if(j > nbCellsWidth)
    {
        throw std::out_of_range("The j index is out of range");
    }
    else
    {
        auto obj = objects[i][j].get();
        if(obj)
        {
            if(dynamic_cast<mirror*>(obj))
            {
                --nbOfMirrors;
            }
            objects[i][j].reset();
            --nbOfObjects;
        }
    }
}

void ground::saveIn(ostream& ost) const
{
    cout << "Saving..." << endl;
    string toSave = to_string(getCellsWidth()) + '\n' +
                    to_string(getCellsHeight()) + '\n' +
                    position.toString() + '\n' +
                    to_string(nbCellsWidth) + '\n' +
                    to_string(nbCellsHeight) + '\n' +
                    to_string(nbOfObjects) + '\n' +
                    to_string(nbOfMirrors) + '\n' +
                    to_string(nbOfMirrors) + '\n';

    auto blank = '.';

    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        for(unsigned j = 0; j < nbCellsWidth; ++j)
        {
            auto obj = objects[i][j].get();
            if(obj)
            {
                if(dynamic_cast<mirror*>(obj)) // For the mirror
                {
                    auto m = dynamic_cast<mirror*>(obj);
                    auto str = ' ';
                    switch(m->getSens())
                    {
                    case hautGauche_basDroit:
                        {
                            str = '\\';
                            break;
                        }
                    case basGauche_hautDroit:
                        {
                            str = '/';
                            break;
                        }
                    default:
                        {
                            cerr << "ERROR : Sens is not defined" << endl;
                            break;
                        }
                    }
                    toSave += str;
                }
                else if(dynamic_cast<shooter*>(obj)) // For the shooter
                {
                    auto s = dynamic_cast<shooter*>(obj);
                    auto str = ' ';
                    switch(s->getDirection()){
                    case RIGHT:
                        {
                            str = '>';
                            break;
                        }
                    case LEFT:
                        {
                            str = '<';
                            break;
                        }
                    case UP:
                        {
                            str = '^';
                            break;
                        }
                    case DOWN:
                        {
                            str = 'v';
                            break;
                        }
                    default:
                        {
                            cerr << "ERROR : Direction is not defined" << endl;
                            break;
                        }
                    }
                    toSave += str;
                }
                else if(dynamic_cast<target*>(obj)) // For the target
                {
                    toSave += 'O' ;

                }
                else if(dynamic_cast<wall*>(obj)) // For the wall
                {
                    toSave += '#' ;

                }
                else cerr << "Unknown type" << endl;
            }
            else toSave += blank ;
        }
        toSave += '\n';
    }

    ost << toSave;
    cout << "Saved." << endl;
}

string ground::toString() const
{
    string t = "Ground[" + grid::toString() +
                    ", position" + position.toString() +
                    ", nbCellsWidth(" + to_string(nbCellsWidth) +
                    "), nbCellsHeight(" + to_string(nbCellsHeight) +
                    "), nbOfObjects(" + to_string(nbOfObjects) +
                    "), nbOfMirrors(" + to_string(nbOfMirrors) +
                    "), nbMirrorMax(" + to_string(nbMirrorMax) +
                    ")]" + '\n';

    t += "List of objects (" + to_string(nbOfObjects) + ") :" + '\n';

    if(nbOfObjects == 0) t += "Empty" + '\n';
    else
    {
        unsigned k = 0;
        for(unsigned i = 0; i < nbCellsHeight; ++i)
        {
            for(unsigned j = 0; j < nbCellsWidth; ++j)
            {
                if(objects[i][j])
                {
                   t += to_string(++k) + " : " + objects[i][j].get()->toString() + '\n';
                }
            }
        }
    }

    return t;
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
