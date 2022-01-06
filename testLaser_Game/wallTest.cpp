#ifndef WALLTEST_H
#define WALLTEST_H

#include "doctest.h"

#include "../Laser_Game/point.h"
#include "../Laser_Game/wall.h"
#include "../Laser_Game/laser.h"

TEST_CASE("3 - Test of the class wall")
{
    point p{5,5};
    point np{2,5};
    wall w{p};
    SUBCASE("Test of the constructor")
    {
        REQUIRE_EQ(w.getPosition(), p);
    }
    laser l = createLaserForTest(p, RIGHT);
    laser new_laser = createLaserForTest(np, RIGHT);

    SUBCASE("Test of the affectation")
    {
        SUBCASE("Test of not affected")
        {
            bool flagInitial = new_laser.getIsAlive();
            w.collide(new_laser);
            bool flagTest = new_laser.getIsAlive();
            REQUIRE_EQ(flagTest, flagInitial);
        }
        SUBCASE("Test of affected")
        {
            bool flagInitial = l.getIsAlive();
            w.collide(l);
            bool flagTest = l.getIsAlive();
            REQUIRE_NE(flagTest, flagInitial);
        }
    }
}

#endif // WALLTEST_H
