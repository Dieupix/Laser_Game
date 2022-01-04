#ifndef TIREUR_H
#define TIREUR_H
#include "object.h"

using namespace enumTypes;

class laser;

class shooter : public object
{
    public:

        /** @brief Constructeur du tireur
         *
         * @param p const point& une position
         * @param directions une direction de l'énumération de directions
         *
         */
        shooter(const point &p, directions);

        /** @brief Destructeur virtuel de la classe
         */
        virtual ~shooter() = default;
        directions getDirection() const;
        void setDirection(directions direction);

        virtual unique_ptr<object> clone() const override;
        virtual void collide(laser& l);
        virtual void print(std::ostream& ost) const override;
        virtual string toString() const override;

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
