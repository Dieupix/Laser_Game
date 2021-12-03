#include "ground.h"

// ---------- Constructors ----------

ground::ground(const point& position, int cellsWidth, int cellsHeight, int nbCellsWidth, int nbCellsHeight) :
    grille{cellsWidth, cellsHeight}, position{position}, nbCellsWidth{nbCellsWidth}, nbCellsHeight{nbCellsHeight}
{
}

// ---------- End of constructors ----------

// ---------- Destructor ----------

// ---------- End of destructor ----------

// ---------- Overloads ----------

// ---------- End of overloads ----------

// ---------- Getters ----------

point ground::getPosition() const {return this->position;}

int ground::getNbCellsWidth() const {return this->nbCellsWidth;}

int ground::getNbCellsHeight() const {return this->nbCellsHeight;}

vector<unique_ptr<object>>& ground::getObjects() {return this->objects;}

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

void ground::addObject(unique_ptr<object> obj){
    objects.push_back(move(obj));
}

void ground::removeObjectAt(unsigned index){
    if(index == 0)
        if(objects.size() == 0)
            throw std::out_of_range("Index is out of range");
        else
            objects.erase(objects.begin() + index);
    else if(index > objects.size())
        throw std::out_of_range("Index is out of range");
    else
        objects.erase(objects.begin() + index);
}

void ground::print(std::ostream& ost) const{
    ost << "Ground[";
    grille::print(ost);
    ost << ", position" << position << ", nbCellsWidth(" << nbCellsWidth << "), nbCellsHeight(" << nbCellsHeight << ")]" << endl;
    ost << "Objects (" << objects.size() << ')';

    if(objects.size() == 0) cout << endl;
    else {
        cout << " :" << endl;
        for(unsigned i = 0; i < objects.size(); ++i) ost << i+1 << " : " << *objects[i] << endl;
    }
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
