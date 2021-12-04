#include "doctest.h"

#include "../Laser_Game/ground.h"

// Need to test the class grille before

TEST_CASE("Test of the class ground"){

    point position(0, 0);
    double cellsWidth = 1.0, cellsHeight = 1.0;
    unsigned nbCellsWidth = 5, nbCellsHeight = 5;

    ground g(position, cellsWidth, cellsHeight, nbCellsWidth, nbCellsHeight);

    SUBCASE("Test of the constructor"){
        //REQUIRE_EQ(g.getPosition(), point{-1, -1}); // SHOULD FAIL
        REQUIRE_EQ(g.getPosition(), position);
        REQUIRE_EQ(g.getNbCellsWidth(), nbCellsWidth);
        REQUIRE_EQ(g.getNbCellsHeight(), nbCellsHeight);
        REQUIRE_EQ(g.getObjects().size(), nbCellsHeight);

        for(unsigned i = 0; i < nbCellsHeight; ++i)
            REQUIRE_EQ(g.getObjects()[i].size(), nbCellsWidth);

        REQUIRE_EQ(g.getNbOfObjects(), 0);
    }

    SUBCASE("Test of the setters"){
    }

    SUBCASE("Test of the addObjectAt() function"){

    }

    SUBCASE("Test of the print() function"){
    }

    SUBCASE("Test of the removeObjectAt() function"){
    }
}
