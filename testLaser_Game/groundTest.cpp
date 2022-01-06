#ifndef GROUNDTEST_H
#define GROUNDTEST_H

#include "doctest.h"

#include "../Laser_Game/ground.h"

#include <string>
#include <sstream>

using std::stringstream;
using std::string;

TEST_CASE("3 - Test of the class ground")
{
    point position(0, 0);
    double cellsWidth = 1.0, cellsHeight = 1.0;
    unsigned nbCellsWidth = 5, nbCellsHeight = 5, nbMirrorMax = 1;

    ground g(position, cellsWidth, cellsHeight, nbCellsWidth, nbCellsHeight, nbMirrorMax);

    SUBCASE("Test of the constructor")
    {
        //REQUIRE_EQ(g.getPosition(), point{-1, -1}); // SHOULD FAIL
        REQUIRE_EQ(g.getCellsWidth(), cellsWidth);
        REQUIRE_EQ(g.getCellsHeight(), cellsHeight);
        REQUIRE_EQ(g.getPosition(), position);
        REQUIRE_EQ(g.getNbCellsWidth(), nbCellsWidth);
        REQUIRE_EQ(g.getNbCellsHeight(), nbCellsHeight);
        REQUIRE_EQ(g.getNbOfObjects(), 0);
        REQUIRE_EQ(g.getNbOfMirrors(), 0);
        REQUIRE_EQ(g.getNbMirrorMax(), nbMirrorMax);

        REQUIRE_EQ(g.getObjects().size(), nbCellsHeight);

        for(unsigned i = 0; i < nbCellsHeight; ++i)
            REQUIRE_EQ(g.getObjects()[i].size(), nbCellsWidth);

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

    /// @TODO - Alex : implement the subcase
    SUBCASE("Test of the addObjectAt() function")
    {
        WHEN("The object is a mirror")
        {

        }

        WHEN("The object is not a mirror")
        {

        }
    }

    SUBCASE("Test of the loadGround() function")
    {
        string input = string("") + to_string(cellsWidth) + "\n" +
                                    to_string(cellsHeight) + "\n" +
                                    position.toString() + "\n" +
                                    to_string(nbCellsWidth) +"\n" +
                                    to_string(nbCellsHeight) + "\n" +
                                    to_string(nbMirrorMax) + "\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    ".....\n" +
                                    ".....\n";

        stringstream ist;
        for(auto c : input)
        {
            ist << c;
        }

        g.loadFrom(ist);

        //CHECK_EQ(g.getPosition(), point{-1, -1}); // SHOULD FAIL
        CHECK_EQ(g.getCellsWidth(), cellsWidth);
        CHECK_EQ(g.getCellsHeight(), cellsHeight);
        CHECK_EQ(g.getPosition(), position);
        CHECK_EQ(g.getNbCellsWidth(), nbCellsWidth);
        CHECK_EQ(g.getNbCellsHeight(), nbCellsHeight);
        CHECK_EQ(g.getNbOfObjects(), 0);
        CHECK_EQ(g.getNbOfMirrors(), 0);
        CHECK_EQ(g.getNbMirrorMax(), nbMirrorMax);

        CHECK_EQ(g.getObjects().size(), nbCellsHeight);

        for(unsigned i = 0; i < nbCellsHeight; ++i)
            CHECK_EQ(g.getObjects()[i].size(), nbCellsWidth);
    }

    SUBCASE("Test of the print() function")
    {
        g.addObjectAt(make_unique<shooter>(position, RIGHT), 0, 0);
        string expectedOutput = string("") +    "Ground[Grid[cellsWidth(" + to_string(cellsWidth) + ")" +
                                                ", cellsHeight(" + to_string(cellsHeight) + ")]" +
                                                ", position" + position.toString() +
                                                ", nbCellsWidth(" + to_string(nbCellsWidth) + ")" +
                                                ", nbCellsHeight(" + to_string(nbCellsHeight) + ")" +
                                                ", nbOfObjects(1), nbOfMirrors(0)" +
                                                ", nbMirrorMax(" + to_string(nbMirrorMax) + ")" + "]\n" +
                                                "List of objects (1) :\n" +
                                                "1 : Tireur[position(0.000000,0.000000), direction(RIGHT)]\n";

        stringstream ost;
        g.print(ost);

        string read = ost.str();

        //CHECK_EQ(read, "I want you to fail"); // SHOULD FAIL
        CHECK_EQ(read, expectedOutput);
    }

    SUBCASE("Test of the removeObjectAt() function")
    {

        WHEN("The object is a mirror")
        {

        }

        WHEN("The object is not a mirror")
        {

        }
    }

    SUBCASE("Test of the saveGround() function")
    {
        string expectedOutput = string("") +    to_string(cellsWidth) + "\n" +
                                                to_string(cellsHeight) + "\n" +
                                                position.toString() + "\n" +
                                                to_string(nbCellsWidth) +"\n" +
                                                to_string(nbCellsHeight) + "\n" +
                                                to_string(nbMirrorMax) + "\n" +
                                                ".....\n" +
                                                ".....\n" +
                                                ".....\n" +
                                                ".....\n" +
                                                ".....\n";

        stringstream ost;
        g.saveIn(ost);

        string read = ost.str();

        //CHECK_EQ(read, "I want you to fail"); // SHOULD FAIL
        CHECK_EQ(read, expectedOutput);
    }
}

#endif // GROUNDTEST_H
