#ifndef GROUND_H
#define GROUND_H

#include <memory>
#include <vector>

#include "object.h"
#include "grille.h"

class ground : public grille
{
    private:
        point position;
        int nbCellsWidth, nbCellsHeight;
        vector<unique_ptr<object>> objects;

    public:
        ground();
        virtual ~ground() = default;

};

#endif // GROUND_H
