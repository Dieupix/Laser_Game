#include "doctest.h"

#include "../Laser_Game/ground.h"
#include "../Laser_Game/tireur.h"

#include <string>
#include <sstream>

using std::stringstream;
using std::string;

TEST_CASE("3 - Test of the class ground"
          * doctest::skip(true))
{
    point position(0, 0);
    double cellsWidth = 1.0, cellsHeight = 1.0;
    unsigned nbCellsWidth = 5, nbCellsHeight = 5;

    ground g(position, cellsWidth, cellsHeight, nbCellsWidth, nbCellsHeight);

    SUBCASE("Test of the constructor")
    {
        //REQUIRE_EQ(g.getPosition(), point{-1, -1}); // SHOULD FAIL
        REQUIRE_EQ(g.getPosition(), position);
        REQUIRE_EQ(g.getNbCellsWidth(), nbCellsWidth);
        REQUIRE_EQ(g.getNbCellsHeight(), nbCellsHeight);
        REQUIRE_EQ(g.getObjects().size(), nbCellsHeight);

        for(unsigned i = 0; i < nbCellsHeight; ++i)
            REQUIRE_EQ(g.getObjects()[i].size(), nbCellsWidth);

        REQUIRE_EQ(g.getNbOfObjects(), 0);
    }

    SUBCASE("Test of the setters")
    {
        SUBCASE("Test of the setPosition() function")
        {
            point p{-1.16, 45.1};
            g.setPosition(p);

            //CHECK_EQ(g.getPosition(), point{-1, -1}); // SHOULD FAIL
            CHECK_EQ(g.getPosition(), p);
        }

        SUBCASE("Test of the setNbCellsWidth() function")
        {
            unsigned nb = 10;
            g.setNbCellsWidth(nb);

            //CHECK_EQ(g.getNbCellsdWidth(), -1); // SHOULD FAIL
            CHECK_EQ(g.getNbCellsWidth(), nb);
            for(unsigned i = 0; i < g.getObjects().size(); ++i)
            {
                REQUIRE_EQ(g.getObjects()[i].size(), nb);
            }
        }

        SUBCASE("Test of the setNbCellsHeight() function")
        {
            unsigned nb = 10;
            g.setNbCellsHeight(nb);

            //CHECK_EQ(g.getNbCellsHeight(), -1); // SHOULD FAIL
            CHECK_EQ(g.getNbCellsHeight(), nb);
            REQUIRE_EQ(g.getObjects().size(), nb);
        }
    }

    SUBCASE("Test of the addObjectAt() function")
    {
        /// @TODO : implement the subcase
    }

    SUBCASE("Test of the loadGround() function")
    {
        string expectedInput = "";

        stringstream ist;
        for(auto c : expectedInput)
        {
            ist << c;
        }

        g.loadFrom(ist);

        /// @TODO : setup all check
        CHECK_EQ(true, true); // SHOULD FAIL
        CHECK_EQ(false, false);
    }

    SUBCASE("Test of the print() function")
    {
        g.addObjectAt(make_unique<tireur>(position, RIGHT), 0, 0);
        string expectedOutput = string("") +    "Ground[(1,1), position(0,0), nbCellsWidth(5), nbCellsHeight(5)]\n" +
                                                "List of objects (1) :\n" +
                                                "1 : Tireur[position(0,0), direction(RIGHT)]\n";

        stringstream ost;
        g.print(ost);

        string read = ost.str();

        CHECK_EQ(read, expectedOutput);
    }

    SUBCASE("Test of the removeObjectAt() function")
    {
        /// @TODO : implement the subcase
    }

    SUBCASE("Test of the saveGround() function")
    {
        string expectedOutput = "";

        stringstream ost;
        g.saveIn(ost);

        string read = ost.str();

        /// @TODO : setup all check
        //CHECK_EQ(read, "I want you to fail"); // SHOULD FAIL
        CHECK_EQ(read, expectedOutput);
    }
}
