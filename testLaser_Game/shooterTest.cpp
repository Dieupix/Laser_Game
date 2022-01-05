#ifndef SHOOTERTEST_H
#define SHOOTERTEST_H

#include "doctest.h"
#include <sstream>
#include "../Laser_Game/shooter.h"
#include "../Laser_Game/laser.h"

using std::ostringstream;
using std::string;
TEST_CASE("3 - Test of the shooter class")
{
    point p {4, 3};
    auto direction = directions::RIGHT;
    shooter tireurTest {p, direction};
    SUBCASE("Test du constructeur")
    {
        REQUIRE_EQ(p, tireurTest.getPosition()); //on verifie la position
        REQUIRE_EQ(direction, tireurTest.getDirection()); //on verifie la direction
    }
    SUBCASE("Test de setpoint()")
    {
        point nouveauPoint{5,3};
        tireurTest.setPosition(nouveauPoint);
        REQUIRE_NE(p, tireurTest.getPosition()); //on verifie que l'ancienne position n'est plus valide
        REQUIRE_EQ(nouveauPoint, tireurTest.getPosition()); //on verifie que la nouvelle position est valide
    }

    SUBCASE("Test de setdirection()")
    {
        auto nouvelleDirection = directions::LEFT;
        tireurTest.setDirection(nouvelleDirection);
        REQUIRE_NE(direction, tireurTest.getDirection()); //on verifie que l'ancienne direction n'est plus valide
        REQUIRE_EQ(nouvelleDirection, tireurTest.getDirection()); //on verifie que la nouvelle position est valide
    }
  /*
    SUBCASE("Test de tire")
    {
        auto laserTest = tireurTest.tire();
        REQUIRE_EQ(tireurTest.getDirection(), laserTest.getDirection());
        REQUIRE_EQ(tireurTest.getPosition(), laserTest.getPosition());
        REQUIRE_EQ(1.0, laserTest.getStep());
    }

    SUBCASE("Test de la fonction print()")
    {
        string expectedOutput = "Tireur[position(4.000000,3.000000), direction(RIGHT)]";
        ostringstream ost;
        tireurTest.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
    }
*/
}

#endif //SHOOTERTEST_H
