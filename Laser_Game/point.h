#ifndef POINT_H
#define POINT_H

#include <iostream>

class point
{
    public:
        /**
        * @brief Constructeur d'un point par defaut sans parametre
        *
        * @return Creer un point en x = 0.0 et y = 0.0
        */
        point();

        /**
        * @brief Constructeur d'un point avec les coordonnees x et y en parametres
        *
        * @param x : Coordonnee de x
        * @param y : Coordonnee de y
        *
        * @return Creer un point
        */
        point(double x, double y);

        /**
        * @brief Fonction qui retourne la coordonee du point en x
        *
        * @return La coordonnee x du point
        */
        double x() const;

        /**
        * @brief Fonction qui retourne la coordonee du point en y
        *
        * @return La coordonnee y du point
        */
        double y() const;

        /**
        * @brief Procedure qui deplace un point aux cordonnees x et y en parametre
        *
        * @param x double : nouvelle coordonee du point en x
        * @param y double : nouvelle coordonee du point en y
        *
        * @return Déplace un point aux cordonnees (x,y)
        */
        void move(double x, double y);

        /**
        * @brief Procédure qui translate un point grace aux coordonnees (x,y) en parametres
        *
        * @param x double : nouvelle coordonee du point en x
        * @param y double : nouvelle coordonee du point en y
        *
        * @return Translate un point grace aux cordonnees (x,y)
        */
        void shift(double x, double y);

        /**
        * @brief Permet de lire un flux
        *
        * @param ost ostream&
        *
        * @return void
        */
        void print(std::ostream& ost) const;

        /**
        * @brief Permet d'écrire sur un flux
        *
        * @param ist istream&
        *
        * @return void
        */
        void read(std::istream& ist);
<<<<<<< HEAD

        /** @brief Permet de tester l'égaliter de 2 points
         *
         * @param p const point&
         * @return un bool (vrai/faux)
         *
         */
        bool operator==(const point& p) const;

        /** @brief Permet de tester la difference de 2 points
         *
         * @param p const point&
         * @return un bool (vrai/faux)
         *
         */
        bool operator!=(const point& p) const;

        /** @brief Permet l'affection d'un point
         *
         * @param p const point&
         * @return point
         *
         */
        point operator=(const point& p) const;

        /** @brief Permet l'affection d'un point
         *
         * @param p const point&
         * @return point&
         *
         */
        point& operator=(const point& p);

        /** @brief Permet la soustraction
         *
         * @return point
         *
         */
        point operator-() const;

        /** @brief Permet l'addition
         *
         * @param p const point&
         * @return point
         *
         */
        point operator+(const point& p) const;

        /** @brief Permet l'addition et l'affectation
         *
         * @param p const point&
         * @return point&
         *
         */
        point& operator+=(const point& p);

        /** @brief Permet la soustraction de deux points
         *
         * @param p const point&
         * @return point
         *
         */
        point operator-(const point& p) const;

        /** @brief Permet la soustraction et l'affectation
         *
         * @param p const point&
         * @return point&
         *
         */
        point& operator-=(const point& p);

        /** @brief Permet la multiplication par un coefficient reel
         *
         * @param d double
         * @return point
         *
         */
        point operator*(double d) const;

        /** @brief Permet la multiplication et l'affectation
         *
         * @param d double
         * @return point&
         *
         */
        point& operator*=(double d);

        /** @brief Permet la division par un reel
         *
         * @param d double
         * @return point
         *
         */
        point operator/(double d) const;

        /** @brief Permet la division et l'affectation
         *
         * @param d double
         * @return point&
         *
         */
    point& operator/=(double d);
=======
        bool operator==(const point& b) const ;
>>>>>>> 3d12b6ff4c7376e5ff4ea871ba02ad4793bd6617
    private:
        double d_x, d_y;
};

        /** @brief Permet d'imprimer un point
         *
         * @param ost std::ostream&
         * @param p const point&
         * @return le flux d'un point
         *
         */
        std::ostream& operator<<(std::ostream& ost, const point & p);

        /** @brief Permet de lire un point
         *
         * @param ost std::ostream&
         * @param p const point&
         * @return le flux d'un point
         *
         */
        std::istream& operator>>(std::istream& ist, point& p);

        /** @brief Permet de multiplier un point par un reel
         *
         * @param d double
         * @param p const point&
         * @return point
         *
         */
        point operator*(double d, const point& p);

#endif // POINT_H
