//Declaring libraries
#include "ground.h"
#include <sstream>
#include <string>

//Declaring namespace elements
using std::string;
using std::stringstream;
using std::to_string;

//---------- Constructors------------------------------
ground::ground() : grid{1, 1},
                   position{0, 0},
                   nbCellsWidth{0},
                   nbCellsHeight{0},
                   nbOfObjects{0},
                   nbOfMirrors{0},
                   nbMirrorMax{0}
{}

ground::ground(const point& position, double cellsWidth, double cellsHeight,
    unsigned nbCellsWidth, unsigned nbCellsHeight, unsigned nbMirrorMax) : grid{cellsWidth, cellsHeight},
                                                                           position{position},
                                                                           nbCellsWidth{nbCellsWidth},
                                                                           nbCellsHeight{nbCellsHeight},
                                                                           nbOfObjects{0},
                                                                           nbOfMirrors{0},
                                                                           nbMirrorMax{nbMirrorMax}
{
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
       objects[i].resize(nbCellsWidth);
    }
}

ground::ground(const ground& g) : grid{g.getCellsWidth(), g.getCellsHeight()},
                                  position{g.getPosition()},
                                  nbCellsWidth{g.getNbCellsWidth()},
                                  nbCellsHeight{g.getNbCellsHeight()},
                                  nbOfObjects{g.getNbOfObjects()},
                                  nbOfMirrors{g.getNbOfMirrors()}
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
//---------- End of constructors-----------------------
//---------- Setter------------------------------------
void ground::setPosition(const point& position)
{
    this->position = position;
}

void ground::setNbCellsWidth(unsigned nbCells)
{
    this->nbCellsWidth = nbCells;
    for(unsigned i = 0; i < objects.size(); ++i)
    {
        objects[i].resize(nbCellsWidth);
    }
}

void ground::setNbCellsHeight(unsigned nbCells)
{
    this->nbCellsHeight = nbCells;
    objects.resize(nbCellsHeight);
}

void ground::setNbMirrorMax(unsigned MirrorMax)
{
    this->nbMirrorMax = MirrorMax;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
point ground::getPosition() const
{
    return this->position;
}

unsigned ground::getNbCellsWidth() const
{
    return this->nbCellsWidth;
}

unsigned ground::getNbCellsHeight() const
{
    return this->nbCellsHeight;
}

unsigned ground::getNbOfObjects() const
{
    return this->nbOfObjects;
}

unsigned ground::getNbOfMirrors() const
{
    return this->nbOfMirrors;
}

unsigned ground::getNbMirrorMax() const
{
    return this->nbMirrorMax;
}

const vector<vector<unique_ptr<object>>>& ground::getObjects() const
{
    return this->objects;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
void ground::addObjectAt(unique_ptr<object> obj, unsigned i, unsigned j)
{
    //If i is not in the ground
    if(i > nbCellsHeight)
    {
        throw std::out_of_range("addObject: the i index is out of range");
    }
    //If j is not in the ground
    else if(j > nbCellsWidth)
    {
        throw std::out_of_range("addObject: the j index is out of range");
    }
    //I and j are in the ground
    else
    {
        //If there are not object in this position
        if(!objects[i][j].get())
        {
            //If this object is a mirror
            if(dynamic_cast<mirror*>(obj.get()))
            {
                ++nbOfMirrors;
            }
            //The object will be now in the ground
            objects[i][j] = move(obj);
            ++nbOfObjects;
        }
    }
}

const shooter& ground::getShooter() const
{
    for(unsigned i = 0 ; i < nbCellsHeight ; ++i)
    {
        for(unsigned j = 0 ; j < nbCellsWidth ; ++j)
        {
            auto obj = objects[i][j].get();
            //If there are an object in this position
            if(obj)
            {
                //If this object is a shooter
                if(dynamic_cast<shooter*>(obj))
                {
                    return *dynamic_cast<shooter*>(obj);
                }
            }
        }
    }
}

const target& ground::getTarget() const
{
    for(unsigned i = 0 ; i < nbCellsHeight ; ++i)
    {
        for(unsigned j = 0 ; j < nbCellsWidth ; ++j)
        {
            auto obj = objects[i][j].get();
            //If there are an object in this position
            if(obj)
            {
                //If this object is a target
                if(dynamic_cast<target*>(obj))
                {
                    return *dynamic_cast<target*>(obj);
                }
            }
        }
    }
}

void ground::loadFrom(istream& ist)
{
    string loaded = "";

    //To know where is the error
    auto line = 1;

    //Reading dimension of cells
    for(unsigned i = 0; i < 2; ++i)
    {
        getline(ist, loaded);
        try
        {
            double dimension_cells = stod(loaded);
            if(i == 0)
            {
                setCellsWidth(dimension_cells);
            }
            else
            {
                setCellsHeight(dimension_cells);
            }
        }
        catch(...)
        {
            cerr << "ERROR: line " << line << endl;
        }
        ++line;
    }

    //Reading position of the ground
    point p;
    ist>>p;
    if(ist.good())
    {
        position = p;
    }
    ist.get();

    //Reading other parameters of the ground
    unsigned nbOfParameters = 3;
    for(unsigned i = 0; i < nbOfParameters; ++i)
    {
        getline(ist,loaded);
        try
        {
            unsigned numberOf = stoi(loaded);
            //There are 3 parameters
            switch(i)
            {
            //Case : the number of cells on width
            case 0:
                {
                    nbCellsWidth = numberOf;
                    break;
                }
            //Case : the number of cells on width
            case 1:
                {
                    nbCellsHeight = numberOf;
                    break;
                }
            //Case : the limited number of installed mirrors
            case 2:
                {
                    nbMirrorMax = numberOf;
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

    //Applying new parameters
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        objects[i].resize(nbCellsWidth);
    }

    //Reading of the ground (without parameters)
    stringstream buffer;
    buffer << ist.rdbuf();
    loaded = buffer.str();

    //Adding of the new objects presents in the ground
    unsigned i = 0, j = 0;
    for(unsigned k = 0; k < loaded.length(); ++k)
    {
        char char_loaded = loaded[k];
        point pos = point{(double)j, (double)i} + position;
        //Now, we have an unknown loaded character. There are many possibilities (possibility of evolution)
        switch(char_loaded)
        {
            //The unknown loaded character is a point. It means that, in this position, there is nothing.
            case '.':
                {
                    break;
                }
            //The unknown loaded character is a backslash with a 'n' or a backslash with a 'r'.
            //It means that, in this position, there is a line break.
            case '\n':
            case '\r':
                {
                    ++i;
                    j = -1;
                    ++line;
                    break;
                }
            //The unknown loaded character is a hashtag. It means that, in this position, there is a wall.
            case '#':
                {
                    addObjectAt(make_unique<wall>(pos), i, j);
                    break;
                }
            //The unknown loaded character is a capital 'o'. It means that, in this position, there is a target.
            case 'O':
                {
                    addObjectAt(make_unique<target>(pos), i, j);
                    break;
                }
            //The unknown loaded character is a slash or a backslash. It means that, in this position, there is a mirror.
            case '/':
            case '\\':
                {
                    //If this is a slash, the sense of the mirror is basGauche_hautDroit else hautGauche_basDroit
                    sens sMirror = (char_loaded == '/' ? basGauche_hautDroit : hautGauche_basDroit);
                    addObjectAt(make_unique<mirror>(pos, sMirror), i, j);
                    break;
                }
            //The unknown loaded character is a greater-than sign or the lowercase letter v or a lower-than sign or circumflex accent.
            //It means that, in this position, there is a shooter.
            case '>':
            case 'v':
            case '<':
            case '^':
                {
                    directions direction;
                    //There are 4 possibilities for the direction
                    switch(char_loaded)
                    {
                        //The direction is RIGHT
                        case '>':
                            {
                                direction = RIGHT;
                                break;
                            }
                        //The direction is DOWN
                        case 'v':
                            {
                                direction = DOWN;
                                break;
                            }
                        //The direction is LEFT
                        case '<':
                            {
                                direction = LEFT;
                                break;
                            }
                        //The direction is UP
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
            //The unknown loaded character is not a valid character.
            default:
                {
                    cerr << "ERROR: line " << line << ": undefined character" << endl;
                    break;
                }
        }
        ++j;
    }
}

void ground::print(ostream& ost) const
{
    ost << toString();
}
/*
invalid_argument throwException(const string& s)
{
  return invalid_argument(s);
}

bool exceptions(unsigned i, unsigned j)
{
    //If i is not in the ground
    if(i > nbCellsHeight)
    {
        throw std::out_of_range("The i index is out of range");
        return true;
    }
    //If j is not in the ground
    else if(j > nbCellsWidth)
    {
        throw std::out_of_range("The j index is out of range");
        return true;
    }
    return false;
}
*/

void ground::removeObjectAt(unsigned i, unsigned j)
{

    //If i is not in the ground
    if(i > nbCellsHeight)
    {
        throw std::out_of_range("The i index is out of range");
    }
    //If j is not in the ground
    else if(j > nbCellsWidth)
    {
        throw std::out_of_range("The j index is out of range");
    }
    else
    {
        auto obj = objects[i][j].get();
        //If there are an object in this position
        if(obj)
        {
            //If this object is a mirror
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
    //The string in which we add the parameters of the current ground
    string toSave = to_string(getCellsWidth())  + '\n' +
                    to_string(getCellsHeight()) + '\n' +
                    position.toString()         + '\n' +
                    to_string(nbCellsWidth)     + '\n' +
                    to_string(nbCellsHeight)    + '\n' +
                    to_string(nbOfObjects)      + '\n' +
                    to_string(nbOfMirrors)      + '\n' +
                    to_string(nbOfMirrors)      + '\n' ;

    //Adding objects of the current ground in the string
    for(unsigned i = 0; i < nbCellsHeight; ++i)
    {
        for(unsigned j = 0; j < nbCellsWidth; ++j)
        {
            auto obj = objects[i][j].get();
            //If there are an object in this position
            if(obj)
            {
                //If this object is a mirror
                if(dynamic_cast<mirror*>(obj))
                {
                    auto m = dynamic_cast<mirror*>(obj);
                    auto str = ' ';
                    //For the sense of the mirror, there are 2 possibilities
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
                //If this object is a shooter
                else if(dynamic_cast<shooter*>(obj))
                {
                    auto s = dynamic_cast<shooter*>(obj);
                    auto str = ' ';
                    //For the direction of the shooter, there are 4 possibilities
                    switch(s->getDirection())
                    {
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
                //If this object is a target
                else if(dynamic_cast<target*>(obj))
                {
                    toSave += 'O' ;
                }
                //If this object is a wall
                else if(dynamic_cast<wall*>(obj))
                {
                    toSave += '#' ;
                }
                //The object is unknow (possibility of evolution)
                else cerr << "Unknown type" << endl;
            }
            //If there are not an object in this position
            else toSave += '.' ;
        }
        toSave += '\n';
    }
    //Print
    ost << toSave;
}

string ground::toString() const
{
    //Parameters of the ground
    string str_ground = "Ground[" + grid::toString() +
                        ", position" + position.toString() +
                        ", nbCellsWidth(" + to_string(nbCellsWidth) +
                        "), nbCellsHeight(" + to_string(nbCellsHeight) +
                        "), nbOfObjects(" + to_string(nbOfObjects) +
                        "), nbOfMirrors(" + to_string(nbOfMirrors) +
                        "), nbMirrorMax(" + to_string(nbMirrorMax) +
                        ")]" + '\n';
    //List of objects
    str_ground += "List of objects (" + to_string(nbOfObjects) + ") :" + '\n';
    if(nbOfObjects == 0)
        str_ground += "Empty" + '\n';
    else
    {
        unsigned k = 0;
        for(unsigned i = 0; i < nbCellsHeight; ++i)
        {
            for(unsigned j = 0; j < nbCellsWidth; ++j)
            {
                if(objects[i][j])
                {
                   str_ground += to_string(++k) + " : " + objects[i][j].get()->toString() + '\n';
                }
            }
        }
    }
    return str_ground;
}
//---------- End of methods ----------------------------
//---------- Operators in class  -----------------------
ground ground::operator=(const ground& g) const
{
   return {g};
}

ground& ground::operator=(const ground& g)
{
    if(this != &g)
    {
        //Changing parameters
        setCellsWidth(g.getCellsWidth());
        setCellsHeight(g.getCellsHeight());
        nbCellsWidth = g.getNbCellsWidth();
        nbCellsHeight = g.getNbCellsHeight();
        objects.resize(nbCellsHeight);

        //Changing objects
        for(unsigned i = 0; i < nbCellsHeight; ++i)
        {
            objects[i].resize(nbCellsWidth);
            for(unsigned j = 0; j < nbCellsWidth; ++j)
            {
                auto obj = g.getObjects()[i][j].get()->clone();
                objects[i][j] = move(obj);
            }
        }

        //Changing parameters
        nbOfObjects = g.getNbOfObjects();
        nbOfMirrors = g.getNbOfMirrors();
    }
    return *this;
}
//---------- End of Operators in class  ---------------
