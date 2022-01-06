#ifndef POINTTEST_H
#define POINTTEST_H

#include "doctest.h"
#include <sstream>
#include <string>
#include "../Laser_Game/point.h"

using std::ostringstream;
using std::string;

void lesCoordonnesDuPointSontExactes(const point& p, double x, double y)
{
    REQUIRE(p.x() == x);
    REQUIRE(p.y() == y);
}

TEST_CASE("0 - Test de la classe point")
{
    double x = 4.7, y = 5.3;
    double random_double = 4.9;
    point pointTest{x, y};
    point p_2 {4,7.2};
    point pointTestVide{};
    SUBCASE("Test du constructeur")
    {
        lesCoordonnesDuPointSontExactes(pointTest, x, y);
    }
    SUBCASE("Test du constructeur par defaut")
    {
        lesCoordonnesDuPointSontExactes(pointTestVide, 0.0,0.0);
    }
    SUBCASE("Test de move()")
    {
        double nouveauX = 8.0, nouveauY = 4.5;
        pointTest.move(nouveauX, nouveauY);
        lesCoordonnesDuPointSontExactes(pointTest, nouveauX, nouveauY);
    }
    SUBCASE("Test de la fonction shit()")
    {
        double shiftX = 8.0, shiftY = 4.5;
        pointTest.shift(shiftX, shiftY);
        lesCoordonnesDuPointSontExactes(pointTest, x + shiftX, y + shiftY);
    }
    SUBCASE("Test de la fonction read()")
    {
        string expectedOutput = "(4.700000,5.300000)";
        ostringstream ost;
        pointTest.print(ost);
        string read = ost.str();
        CHECK_EQ(read, expectedOutput);
    }
    SUBCASE("Test de l'operator *")
    {
        lesCoordonnesDuPointSontExactes(pointTest * random_double, x * random_double, y * random_double);
    }
    SUBCASE("Test de l'operator ==")
    {
        point p{4.7,5.3};
        REQUIRE_EQ(p, pointTest);
    }
    SUBCASE("Test de l'operator !=")
    {
        REQUIRE_NE(p_2, pointTest);
    }
    SUBCASE("Test de l'operator =")
    {
        point p{};
        p = pointTest;
        REQUIRE_EQ(p, pointTest);
        p ={0.0, 0.0};
        pointTest = p;
        REQUIRE_EQ(p, pointTest);
    }
    SUBCASE("Test de l'operator -")
    {
        point p{};
        p = -pointTest;
        REQUIRE_EQ(p, -pointTest);
    }
    SUBCASE("Test de l'operator +")
    {
        point resultat = pointTest + p_2;
        lesCoordonnesDuPointSontExactes(resultat, x + 4, y + 7.2);
    }
    SUBCASE("Test de l'operator +=")
    {
        pointTest += p_2;
        lesCoordonnesDuPointSontExactes(pointTest, x + 4, y + 7.2);
    }
    SUBCASE("Test de l'operator -")
    {
        point resultat = pointTest - p_2;
        lesCoordonnesDuPointSontExactes(resultat, x - 4, y - 7.2);
    }
    SUBCASE("Test de l'operator -=")
    {

        pointTest -= p_2;
        lesCoordonnesDuPointSontExactes(pointTest, x - 4, y - 7.2);
    }
    SUBCASE("Test de l'operator *")
    {
        point resultat = pointTest * random_double;
        lesCoordonnesDuPointSontExactes(resultat, x * 4.9, y * 4.9);
    }
    SUBCASE("Test de l'operator *=")
    {
        pointTest *= random_double;
        lesCoordonnesDuPointSontExactes(pointTest, x * 4.9, y * 4.9);
    }
    SUBCASE("Test de l'operator *")
    {
        point resultat = pointTest / random_double;
        lesCoordonnesDuPointSontExactes(resultat, x / 4.9, y / 4.9);
    }
    SUBCASE("Test de l'operator *=")
    {

        pointTest /= random_double;
        lesCoordonnesDuPointSontExactes(pointTest, x / 4.9, y / 4.9);
    }
}

#endif //POINTTEST_H
