#ifndef POINT_H
#define POINT_H

#include <iostream>

class point
{
    public:
        /**
        * @brief Constructeur d'un point avec les coordonnees x et y en parametres
        *
        * @param x : Coordonnee de x
        * @param y : Coordonnee de y
        *
        * @return Créer un point
        */
        point(double x, double y);
        /**
        * @brief Constructeur d'un point par defaut sans parametre
        *
        * @return Creer un point en x = 0.0 et y = 0.0
        */
        point();
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
        bool operator==(const point& b) const ;
    private:
        double d_x, d_y;
};

#endif // POINT_H
