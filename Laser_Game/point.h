#ifndef POINT_H
#define POINT_H

//Declaring libraries
#include <iostream>
#include <string>

//Declaring namespace elements
using std::string;
using std::ostream;
using std::istream;

class point
{
    public:
        /**
        * @brief Constructor by default of point
        *
        * @return Create a point with x = 0.0 and y = 0.0
        */
        point();

        /**
        * @brief Constructor of point with parameters
        *
        * @param x : Cartesian coordinates of x (double)
        * @param y : Cartesian coordinates of y (double)
        *
        * @return Create a point
        */
        point(double x, double y);

        /**
        * @brief Function that returns the coordinate x of point
        *
        * @return the coordinate x
        */
        double x() const;

        /**
        * @brief Function that returns the coordinate y of point
        *
        * @return the coordinate y
        */
        double y() const;

        /**
        * @brief Procedure that moves coordinates of point on a new x and new y
        *
        * @param x : new coordinate x of point (double)
        * @param y : new coordinate y of point (double)
        *
        * @return void
        */
        void move(double x, double y);

        /**
        * @brief Procedure that translate a point thanks coordinates (x,y) in parameters
        *
        * @param x : new coordinate x of point (double)
        * @param y : new coordinate y of point (double)
        *
        * @return void
        */
        void shift(double x, double y);

        /**
        * @brief Allows to print characteristics of point
        *
        * @param ost : the flow (ostream)
        *
        * @return void
        */
        void print(ostream& ost) const;

        /**
        * @brief Allows to convert a point to string
        *
        * @return a string
        */
        string toString() const;

        /**
        * @brief Allows to read a flow
        *
        * @param ist : the flow (istream)
        *
        * @return void
        */
        void read(istream& ist);

        /** @brief Allows to test equality between 2 points
         *
         * @param p : a point (const point)
         *
         * @return a boolean
         */
        bool operator==(const point& p) const;

        /** @brief Allows to test inequality between 2 points
         *
         * @param p : a point (const point)
         *
         * @return a boolean
         */
        bool operator!=(const point& p) const;

        /** @brief Allows to test affectation between 2 points
         *
         * @param p : a point (const point)
         *
         * @return a point
         */
        point operator=(const point& p) const;

        /** @brief Allows to test affectation between 2 points
         *
         * @param p : a point (const point)
         *
         * @return the current point
         */
        point& operator=(const point& p);

        /** @brief Allows to test reverse of the current point
         *
         * @return a new point (reverse of the current point)
         *
         */
        point operator-() const;

        /** @brief Allows to test addition between 2 points
         *
         * @param p : a point (const point)
         *
         * @return a point
         */
        point operator+(const point& p) const;

        /** @brief Allows to test addition and affectation between 2 points
         *
         * @param p : a point (const point)
         *
         * @return the current point modified
         */
        point& operator+=(const point& p);

        /** @brief Allows to test substraction between 2 points
         *
         * @param p : a point (const point)
         *
         * @return a point
         */
        point operator-(const point& p) const;

        /** @brief Allows to test substraction and affectation between 2 points
         *
         * @param p : a point (const point)
         *
         * @return the current point modified
         */
        point& operator-=(const point& p);

        /** @brief Allows to test multiplication between a point and a real
         *
         * @param coef : a real coefficient (double)
         *
         * @return a point
         */
        point operator*(double coef) const;

        /** @brief Allows to test multiplication and affectation between a point and a real
         *
         * @param coef : a real coefficient (double)
         *
         * @return the current point modified
         */
        point& operator*=(double coef);

        /** @brief Allows to test divison between a point and a real
         *
         * @param coef : a real coefficient (double)
         *
         * @return a point
         */
        point operator/(double coef) const;

        /** @brief Allows to test division and affectation between a point and a real
         *
         * @param coef : a real coefficient (double)
         *
         * @return the current point modified
         */
        point& operator/=(double coef);

    private:
        //The coordinates of point
        double d_x, d_y;
};

        /** @brief Allows to print a point
         *
         * @param ost : the flow (ostream)
         * @param p   : the point to print (const point)
         *
         * @return the flow
         */
        ostream& operator<<(ostream& ost, const point & p);

        /** @brief Allows to read a point
         *
         * @param ist : the flow (istream)
         * @param p   : the point to read (const point)
         *
         * @return the flow
         */
        istream& operator>>(istream& ist, point& p);

        /** @brief Allows to test multiplication between a point and a real
         *
         * @param coef : a real coefficient (double)
         * @param p    : a point (const point)
         *
         * @return a point
         */
        point operator*(double coef, const point& p);

#endif // POINT_H
