#include "ground.h"

// ---------- Constructors ----------

ground::ground(const point& position, double cellsWidth, double cellsHeight, unsigned nbCellsWidth, unsigned nbCellsHeight) :
    grille{cellsWidth, cellsHeight}, position{position}, nbCellsWidth{nbCellsWidth}, nbCellsHeight{nbCellsHeight}, nbOfObjects{0}
{
    objects.resize(nbCellsHeight);
    for(unsigned i = 0; i < nbCellsHeight; ++i)
        objects[i].resize(nbCellsWidth);
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

int ground::getNbOfObjects() const {return this->nbOfObjects;}

/// @TODO - WHY IT DOES NOT WORK ???
//vector<vector<unique_ptr<object>>> ground::getObjects() const {return this->objects;}

// ---------- End of getters ----------

// ---------- Setters ----------

void ground::setPosition(const point& position){
    this->position = position;
}

void ground::setNbCellsWidth(int nbCellsWidth){
    this->nbCellsWidth = nbCellsWidth;
}

void ground::setNbCellsHeight(int nbCellsHeight){
    this->nbCellsHeight = nbCellsHeight;
}

// ---------- End of setters ----------

// ---------- Functions --------

void ground::addObjectAt(unique_ptr<object> obj, unsigned i, unsigned j){
    if(i > nbCellsHeight)
        throw std::out_of_range("The i index is out of range");
    else if(j > nbCellsWidth)
        throw std::out_of_range("The j index is out of range");
    else{
        if(!objects[i][j]) ++nbOfObjects;
        objects[i][j] = move(obj);
    }
}

void ground::print(std::ostream& ost) const{
    ost << "Ground[";
    grille::print(ost);
    ost << ", position" << position << ", nbCellsWidth(" << nbCellsWidth << "), nbCellsHeight(" << nbCellsHeight << ")]" << endl;
    ost << "List of objects (" << nbOfObjects << ')';

    if(nbOfObjects == 0) cout << endl;
    else {
        cout << " :" << endl;
        unsigned k = 0;
        for(unsigned i = 0; i < objects.size(); ++i){
            for(unsigned j = 0; j < objects.size(); ++j){
                if(objects[i][j]){
                   ost << ++k << " : " << *objects[i][j] << endl;
                }
            }
        }
    }
}

void ground::removeObjectAt(unsigned i, unsigned j){
    if(i > nbCellsHeight)
        throw std::out_of_range("The i index is out of range");
    else if(j > nbCellsWidth)
        throw std::out_of_range("The j index is out of range");
    else if(objects[i][j]){
        objects[i][j].reset();
        --nbOfObjects;
    }
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
