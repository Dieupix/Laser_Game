#ifndef VIEWERWALL_H
#define VIEWERWALL_H

#include "viewer.h"
class object;
class viewerWall : public viewer
{
public:
    virtual ~viewerWall() = default;
    virtual void printObject(const object& o,std::ostream& ost) const override;
    virtual void printObjectInGame(std::ostream& ost) const override;
};
#endif // VIEWERWALL_H
