#ifndef VIEWERONTERMINAL_H
#define VIEWERONTERMINAL_H

#include "viewer.h"

class viewerOnTerminal : public viewer
{
    private:
        /**
         * @brief The character to print when it is blank
         */
        char blank;
        /**
         * @brief The spacing
         */
        unsigned spacing;

    public:
        // Constructors
        viewerOnTerminal(char = '.', unsigned = 2);

        // Destructor
        /**
         * @brief Default-implemented destructor
         * @details Destroys the viewerOnTerminal
         */
        virtual ~viewerOnTerminal() = default;

        // Getters
        char getBlank() const;
        unsigned getSpacing() const;

        // Setters
        void setBlank(char);
        void setSpacing(unsigned);

        // Functions
        virtual void print(const unique_ptr<object>&) const override;

        virtual void printCible(const cible&) const override;
        virtual void printGround(const ground&) const override;
        virtual void printLaser(const laser&) const override;
        virtual void printMirror(const miroir&) const override;
        virtual void printShooter(const tireur&) const override;
        virtual void printWall(const wall&) const override;

}; // End of viewerOnTerminal

// Global functions

#endif // VIEWERONTERMINAL_H
