#ifndef TIREUR_H
#define TIREUR_H
#include "object.h"
#include "laser.h"

class tireur : public object
{
    public:
         /** @brief L'enumeration des directions disponibles pour le tireur
          */


        /** @brief Constructeur du tireur
         *
         * @param p const point& une position
         * @param directions une direction de l'énumération de directions
         *
         */
        tireur(const point &p, directions);

        /** @brief Destructeur virtuel de la classe
         */
        virtual ~tireur() = default;
        directions getDirection() const;
        void setDirection(directions direction);
        virtual void print(std::ostream& ost) const override;


        /** @brief Permet au tireur de tirer
         *
         * @param un double qui determine le pas du tir
         * @return le laser
         *
         */
        laser tire(double step = 1.0);
    private:
        /** @brief la direction du tireur
         */
        directions direction;
};

#endif // TIREUR_H
