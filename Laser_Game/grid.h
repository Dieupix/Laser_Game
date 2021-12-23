#ifndef GRILLE_H
#define GRILLE_H
#include <iostream>

class grille
{
    public:
        /** @brief Construteur d'une grille
         *
         * @param longueur double la taille d'une cellule en longueur de la grille
         * @param largeur double la taille d'une cellule en largeur de la grille
         *
         */
        grille(double longueur, double largeur);

        /** @brief Destructeur virtuel de la grile
         *
         * @return virtual
         *
         */
        virtual ~grille() = default;

        /**
        * @brief Permet d'écrire sur un flux
        *
        * @param ist istream&
        *
        * @return void
        */
        virtual void print(std::ostream& ost) const;

        /** @brief Permet de lire un flux
         *
         * @param ist std::istream&
         * @return void
         *
         */
        void read(std::istream& ist);
    private:
        /** @brief Le nombre de cellule en longueur et en largeur
         *
         * @param Le nombre de cellule en longueur
         * @param Le nombre de cellule en largeur
         */
        double d_longueurCells, d_largeurCells;
        /// @TODO - Mathis : add getters function for private variable members
};

std::ostream& operator<<(std::ostream& ost, const grille & g);
std::istream& operator>>(std::istream& ist, grille& g);
#endif // GRILLE_H
