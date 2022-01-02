#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <string>

class grid
{
    public:
        /** @brief Construteur d'une grid
         *
         * @param longueur double la taille d'une cellule en longueur de la grid
         * @param largeur double la taille d'une cellule en largeur de la grid
         *
         */
        grid(double largeur, double hauteur);

        /** @brief Destructeur virtuel de la grile
         *
         * @return virtual
         *
         */
        virtual ~grid() = default;

        double getCellsHeight() const;
        double getCellsWidth() const;

        void setCellsHeight(double);
        void setCellsWidth(double);

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
        virtual std::string toString() const;
    private:
        /** @brief Le nombre de cellule en longueur et en largeur
         *
         * @param Le nombre de cellule en longueur
         * @param Le nombre de cellule en largeur
         */
        double d_largeurCells, d_hauteurCells;
};

std::ostream& operator<<(std::ostream& ost, const grid & g);
std::istream& operator>>(std::istream& ist, grid& g);
#endif // GRID_H
