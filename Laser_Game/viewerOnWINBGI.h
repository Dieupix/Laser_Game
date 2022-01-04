#ifndef VIEWERONWINBGI_H
#define VIEWERONWINBGI_H

#include "viewer.h"

class viewerOnWINBGI : public viewer
{
    private:
        unsigned height, width;
        unsigned scale;

    public:
        // Constructors
        viewerOnWINBGI();
        viewerOnWINBGI(unsigned, unsigned, unsigned);

        // Destructor
        virtual ~viewerOnWINBGI();

        // Getters
        unsigned getHeight() const;
        unsigned getWidth() const;
        unsigned getScale() const;

        // Setters
        void setHeight(unsigned);
        void setWidth(unsigned);
        void setScale(unsigned);

        // Functions
        virtual void print(const unique_ptr<object>&) const = 0;

        virtual void printGround(const ground&) const = 0;
        virtual void printLaser(const laser&) const = 0;
        virtual void printMirror(const mirror&) const = 0;
        virtual void printShooter(const shooter&) const = 0;
        virtual void printTarget(const target&) const = 0;
        virtual void printWall(const wall&) const = 0;
}; // End of viewerOnWINBGI

// Global functions

#endif // VIEWERONWINBGI_H
