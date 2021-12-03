#ifndef GROUND_H
#define GROUND_H

#include <memory>
#include <vector>

#include "object.h"
#include "grille.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::vector;

class ground : public grille
{
    private:
        point position;
        int nbCellsWidth, nbCellsHeight;
        vector<unique_ptr<object>> objects;

    public:

        // Constructors
        ground(const point&, int, int, int, int);

        // Destructors
        virtual ~ground() = default;

        // Overloads

        // Getters
        point getPosition() const;
        int getNbCellsWidth() const;
        int getNbCellsHeight() const;
        vector<unique_ptr<object>>& getObjects();

        // Setters
        void setPosition(const point&);
        void setNbCellsWidth(int);
        void setNbCellsHeight(int);

        // Functions
        void print(std::ostream& ost) const;

}; // End of ground

// Global functions

#endif // GROUND_H
