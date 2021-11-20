#ifndef VIEWER_H
#define VIEWER_H
#include "object.h"

class viewer
{
public:
    virtual ~viewer() = default;
    virtual void printObject(const object& o, std::ostream& ost) const = 0;
    virtual void printObjectInGame(std::ostream& ost) const = 0;
};
#endif // VIEWER_H
