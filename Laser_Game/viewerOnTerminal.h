#ifndef VIEWERONTERMINAL_H
#define VIEWERONTERMINAL_H

#include "viewer.h"

class viewerOnTerminal : public viewer
{
    private:
        static constexpr unsigned spacing = 2;
        static constexpr char blanck = '.';

    public:
        viewerOnTerminal() = default;
        virtual ~viewerOnTerminal() = default;

        virtual void print(const unique_ptr<object>&) const override;

        virtual void printCible(const cible&) const override;
        virtual void printGround(const ground&) const override;
        virtual void printLaser(const laser&) const override;
        virtual void printMirror(const miroir&) const override;
        virtual void printShooter(const tireur&) const override;
        virtual void printWall(const wall&) const override;
};

#endif // VIEWERONTERMINAL_H
