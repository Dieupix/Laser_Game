#ifndef VIEWERONTERMINAL_H
#define VIEWERONTERMINAL_H

#include "viewer.h"

class viewerOnTerminal : public viewer
{
    public:
        viewerOnTerminal() = default;
        virtual ~viewerOnTerminal() = default;

        virtual void printLaser(const unique_ptr<laser>& l) const override;
        virtual void printTireur(const unique_ptr<tireur>& t) const override;
};

#endif // VIEWERONTERMINAL_H
