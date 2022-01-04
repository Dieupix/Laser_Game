#ifndef VIEWERONWINBGI_H
#define VIEWERONWINBGI_H

#include "../winGraphics/graphics.h"

#include "viewer.h"

class viewerOnWINBGI : public viewer
{
    private:
        unsigned width, height;
        float scale;

        void initialize();

    public:
        // Constructors
        viewerOnWINBGI();
        viewerOnWINBGI(unsigned, unsigned, float);

        // Destructor
        virtual ~viewerOnWINBGI();

        // Getters
        unsigned getHeight() const;
        unsigned getWidth() const;
        float getScale() const;

        // Setters
        void setHeight(unsigned);
        void setWidth(unsigned);
        void setScale(float);

        // Functions
        virtual void print(const unique_ptr<object>&) const override;

        virtual void printGround(const ground&) const override;
        virtual void printLaser(const laser&) const override;
        virtual void printMirror(const mirror&) const override;
        virtual void printShooter(const shooter&) const override;
        virtual void printTarget(const target&) const override;
        virtual void printWall(const wall&) const override;

}; // End of viewerOnWINBGI

// Global functions

#endif // VIEWERONWINBGI_H
