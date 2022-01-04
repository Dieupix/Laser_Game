#ifndef POINTTEST_H
#define POINTTEST_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Laser_Game/point.h"

using std::ostringstream;
using std::string;
void lesCoordonnesDuPointSontExactement(const point& p,double x,double y)
{
    REQUIRE( p.x() == x );
    REQUIRE( p.y() == y );
}

TEST_CASE("0 - Test de la classe point")
{
    double x = 4.7, y = 5.3;
    point pointTest{x, y};
    point pointTestVide{};

    SUBCASE("Test du constructeur")
        lesCoordonnesDuPointSontExactement(pointTest, x, y);
    SUBCASE("Test du constructeur par defaut")
        lesCoordonnesDuPointSontExactement(pointTestVide, 0.0,0.0);

    SUBCASE("Test de move()")
    {
        double nouveauX = 8.0, nouveauY = 4.5;
        pointTest.move(nouveauX, nouveauY);
        lesCoordonnesDuPointSontExactement(pointTest, nouveauX, nouveauY);
    }

    SUBCASE("Test de la fonction shit()")
    {
        double shiftX = 8.0, shiftY = 4.5;
        pointTest.shift(shiftX, shiftY);
        lesCoordonnesDuPointSontExactement(pointTest, x + shiftX, y + shiftY);
    }

    SUBCASE("Test de la fonction read()")
    {
        string expectedOutput = "(4.700000,5.300000)";
        ostringstream ost;
        pointTest.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
    }

    /*SUBCASE("Test de la fonction print()")
    {

    }*/

    SUBCASE("Test de l'operator *")
    {
        double d = 5.8;
        lesCoordonnesDuPointSontExactement(pointTest * d, x * d, y * d);
    }

    SUBCASE("Test de l'operator ==")
    {
        point p {4.7,5.3};
        REQUIRE_EQ(p, pointTest);
    }

    SUBCASE("Test de l'operator !=")
    {
        point p {27,1.2};
        REQUIRE_NE(p, pointTest);
    }

    SUBCASE("Test de l'operator =")
    {
        point p {};
        p = pointTest;
        REQUIRE_EQ(p, pointTest);
        p  = {0.0, 0.0};
        pointTest = p;
        REQUIRE_EQ(p, pointTest);
    }

    SUBCASE("Test de l'operator -")
    {
        point p {};
        p = -pointTest;
        REQUIRE_EQ(p, -pointTest);
    }

    SUBCASE("Test de l'operator +")
    {
        point p {4,7.2};
        point resultat = pointTest + p;
        lesCoordonnesDuPointSontExactement(resultat, x + 4, y + 7.2);
    }

    SUBCASE("Test de l'operator +=")
    {
        point p {4,7.2};
        pointTest += p;
        lesCoordonnesDuPointSontExactement(pointTest, x + 4, y + 7.2);
    }

    SUBCASE("Test de l'operator -")
    {
        point p {4,7.2};
        point resultat = pointTest - p;
        lesCoordonnesDuPointSontExactement(resultat, x - 4, y - 7.2);
    }

    SUBCASE("Test de l'operator -=")
    {
        point p {4,7.2};
        pointTest -= p;
        lesCoordonnesDuPointSontExactement(pointTest, x - 4, y - 7.2);
    }

    SUBCASE("Test de l'operator *")
    {
        double d = 4.9;
        point resultat = pointTest * d;
        lesCoordonnesDuPointSontExactement(resultat, x * 4.9, y * 4.9);
    }

    SUBCASE("Test de l'operator *=")
    {
        double d = 4.9;
        pointTest *= d;
        lesCoordonnesDuPointSontExactement(pointTest, x * 4.9, y * 4.9);
    }

    SUBCASE("Test de l'operator *")
    {
        double d = 4.9;
        point resultat = pointTest / d;
        lesCoordonnesDuPointSontExactement(resultat, x / 4.9, y / 4.9);
    }

    SUBCASE("Test de l'operator *=")
    {
        double d = 4.9;
        pointTest /= d;
        lesCoordonnesDuPointSontExactement(pointTest, x / 4.9, y / 4.9);
    }
}

#endif //POINTTEST_H
