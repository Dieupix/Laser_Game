#include "ground.h"

// ---------- Constructors ----------

ground::ground(int cellsWidth, int cellsHeight) : grille{cellsWidth, cellsHeight}
{}

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

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
