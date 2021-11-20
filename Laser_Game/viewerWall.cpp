#include "viewerWall.h"
#include "viewer.h"
#include "wall.h"
#include "object.h"

void viewerWall::printObject(const object& o,std::ostream& ost) const
{
    ost<<"WALL : "<<o.getPosition();
}
void viewerWall::printObjectInGame(std::ostream& ost) const
{
    ost<<'#';
}
