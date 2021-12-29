#include "ground.h"

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

// ---------- Constructors ----------

ground::ground(const point& position, double cellsWidth, double cellsHeight, unsigned nbCellsWidth, unsigned nbCellsHeight) :
    grille{cellsWidth, cellsHeight}, position{position}, nbCellsWidth{nbCellsWidth}, nbCellsHeight{nbCellsHeight}, nbOfObjects{0}, nbOfMirrors{0}
{
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
        objects[i].resize(nbCellsWidth);
}

ground::ground(const ground& g) :
    ///@TODO - I need the getters of the grid...
    grille{1, 1}, position{g.getPosition()}, nbCellsWidth{g.getNbCellsWidth()}, nbCellsHeight{g.getNbCellsHeight()}, nbOfObjects{g.getNbOfObjects()}, nbOfMirrors{g.getNbOfMirrors()}
{
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        objects[i].resize(nbCellsWidth);
        for(unsigned j = 0; j < g.getObjects()[i].size(); ++j)
        {
            auto obj = make_unique<object>(*g.getObjects()[i][j].get());
            objects[i][j] = move(obj);
        }
    }
}

// ---------- End of constructors ----------

// ---------- Destructor ----------

// ---------- End of destructor ----------

// ---------- Overloads ----------

// ---------- End of overloads ----------

// ---------- Getters ----------

point ground::getPosition() const {return this->position;}

unsigned ground::getNbCellsWidth() const {return this->nbCellsWidth;}

unsigned ground::getNbCellsHeight() const {return this->nbCellsHeight;}

unsigned ground::getNbOfObjects() const {return this->nbOfObjects;}

unsigned ground::getNbOfMirrors() const {return this->nbOfMirrors;}

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

// ---------- End of setters ----------

// ---------- Functions --------

void ground::addObjectAt(unique_ptr<object> obj, unsigned i, unsigned j){
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
        if(!objects[i][j])
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

void ground::loadFrom(istream& ist)
{
    /// @TODO - Alex : change the loading method

    stringstream buffer;
    buffer << ist.rdbuf();
    string loaded = buffer.str();
}

void ground::print(ostream& ost) const{
    ost << "Ground[";
    grille::print(ost);
    ost << ", position" << position << ", nbCellsWidth(" << nbCellsWidth << "), nbCellsHeight(" << nbCellsHeight << ")]" << endl;
    ost << "List of objects (" << nbOfObjects << ") :" << endl;

    if(nbOfObjects == 0) cout << "Empty" << endl;
    else
    {
        unsigned k = 0;
        for(unsigned i = 0; i < objects.size(); ++i)
        {
            for(unsigned j = 0; j < objects[i].size(); ++j)
            {
                if(objects[i][j])
                {
                   ost << ++k << " : " << *objects[i][j] << endl;
                }
            }
        }
    }
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
        if(objects[i][j])
        {
            if(dynamic_cast<mirror*>(objects[i][j].get()))
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
    string toSave = "";

    auto blank = '.';

    for(unsigned i = 0; i < getObjects().size(); ++i)
    {
        for(unsigned j = 0; j < getObjects()[i].size(); ++j)
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
                    toSave += 'X' ;

                }
                else if(dynamic_cast<wall*>(obj)) // For the wall
                {
                    toSave += '*' ;

                }
                else cerr << "Unknown type" << endl;
            }
            else toSave += blank ;
        }
        toSave += '\n';
    }

    ost << toSave;
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
