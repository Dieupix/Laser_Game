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

point ground::getPosition() const { return this->position; }

int ground::getNbCellsWidth() const { return this->nbCellsWidth; }

int ground::getNbCellsHeight() const { return this->nbCellsHeight; }

vector<unique_ptr<object>>& ground::getObjects() { return this->objects; }

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

void ground::print(std::ostream& ost) const{
    ost << "Terrain[grille";
    grille::print(ost);
    ost << ", position" << position << ", nbCellsWidth(" << nbCellsWidth << "), nbCellsHeight(" << nbCellsHeight << ")]" << endl;
    ost << "Objets " << objects.size() << " :" << endl;
    for(unsigned i = 0; i < objects.size(); ++i) ost << i+1 << " : " << *objects[i] << endl;
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
