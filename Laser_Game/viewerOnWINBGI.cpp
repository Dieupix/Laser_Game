#include "viewerOnWINBGI.h"

// ---------- Constructors ----------

viewerOnWINBGI::viewerOnWINBGI() : width{500}, height{500}, scale{20}
{
    initialize();
}

viewerOnWINBGI::viewerOnWINBGI(unsigned w, unsigned h, float s = 25) : width{w}, height{h}, scale{s}
{
    initialize();
}

// ---------- End of constructors ----------

// ---------- Destructor ----------

viewerOnWINBGI::~viewerOnWINBGI()
{
    closegraph();
}

// ---------- End of destructor ----------

// ---------- Overloads ----------

// ---------- End of overloads ----------

// ---------- Getters ----------

unsigned viewerOnWINBGI::getHeight() const {return this->height;}

unsigned viewerOnWINBGI::getWidth() const {return this->width;}

float viewerOnWINBGI::getScale() const {return this->scale;}

// ---------- End of getters ----------

// ---------- Setters ----------

void viewerOnWINBGI::setHeight(unsigned h)
{
    this->height = h;
}

void viewerOnWINBGI::setWidth(unsigned w)
{
    this->width = w;
}

void viewerOnWINBGI::setScale(float s)
{
    this->scale = s;
}

// ---------- End of setters ----------

// ---------- Functions --------

void viewerOnWINBGI::initialize()
{
    opengraphsize(width, height);
    setbkcolor(BLACK);
    setcolor(WHITE);
}

void viewerOnWINBGI::print(const unique_ptr<object>& obj) const
{
    if(dynamic_cast<laser*>(obj.get())) // For the laser
    {
        auto tmp = dynamic_cast<laser*>(obj.get());
        printLaser(*tmp);

    }
    else if(dynamic_cast<mirror*>(obj.get())) // For the mirror
    {
        auto tmp = dynamic_cast<mirror*>(obj.get());
        printMirror(*tmp);

    }
    else if(dynamic_cast<shooter*>(obj.get())) // For the shooter
    {
        auto tmp = dynamic_cast<shooter*>(obj.get());
        printShooter(*tmp);

    }
    else if(dynamic_cast<target*>(obj.get())) // For the target
    {
        auto tmp = dynamic_cast<target*>(obj.get());
        printTarget(*tmp);

    }
    else if(dynamic_cast<wall*>(obj.get())) // For the wall
    {
        auto tmp = dynamic_cast<wall*>(obj.get());
        printWall(*tmp);

    }
    else
        cerr << "Unknown type" << endl;
}

void viewerOnWINBGI::printGround(const ground& g) const
{
    cleardevice();
    for(unsigned i = 0; i < g.getNbCellsHeight(); ++i)
    {
        for(unsigned j = 0; j < g.getNbCellsWidth(); ++j)
        {
            if(g.getObjects()[i][j])
            {
                print(g.getObjects()[i][j]);
            }
            else
            {
                point pos = point(j, i) + g.getPosition();
                pos *= 2 * scale;
                plot(pos.x(), pos.y());
            }
        }
    }
    waituntilbuttonpressed();
}

void viewerOnWINBGI::printLaser(const laser& l) const
{
    point pos = l.getPosition() * 2 * scale;

    switch(l.getDirection())
    {
    case RIGHT:
    case LEFT:
        {
            int x0 = pos.x() - scale;
            int y0 = pos.y();
            int x1 = pos.x() + scale;
            int y1 = pos.y();

            line(x0, y0, x1, y1);

            break;
        }
    case UP:
    case DOWN:
        {
            int x0 = pos.x();
            int y0 = pos.y() + scale;
            int x1 = pos.x();
            int y1 = pos.y() - scale;

            line(x0, y0, x1, y1);

            break;
        }
    default:
        {
            cerr << "ERROR : Direction is not defined" << endl;
            break;
        }
    }
}

void viewerOnWINBGI::printMirror(const mirror& m) const
{
    point pos = m.getPosition() * 2 * scale;

    int left = pos.x() - scale;
    int top = pos.y() + scale;
    int right = pos.x() + scale;
    int bottom = pos.y() - scale;

    switch(m.getSens())
    {
    case hautGauche_basDroit:
        {
            line(left, bottom, right, top);
            break;
        }
    case basGauche_hautDroit:
        {
            line(left, top, right, bottom);
            break;
        }
    default:
        cerr << "ERROR : Sens is not defined" << endl;
        break;
    }
}

void viewerOnWINBGI::printShooter(const shooter& s) const
{
    point pos = s.getPosition() * 2 * scale;

    point left, right, top;

    switch(s.getDirection())
    {
    case RIGHT:
        {
            left = point(pos.x() - scale, pos.y() - scale);
            right = point(pos.x() - scale, pos.y() + scale);
            top = point(pos.x() + scale, pos.y());

            triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());

            break;
        }
    case LEFT:
        {
            left = point(pos.x() + scale, pos.y() + scale);
            right = point(pos.x() + scale, pos.y() - scale);
            top = point(pos.x() - scale, pos.y());

            triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());

            break;
        }
    case UP:
        {
            left = point(pos.x() - scale, pos.y() + scale);
            right = point(pos.x() + scale, pos.y() + scale);
            top = point(pos.x(), pos.y() - scale);

            triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());

            break;
        }
    case DOWN:
        {
            left = point(pos.x() + scale, pos.y() - scale);
            right = point(pos.x() - scale, pos.y() - scale);
            top = point(pos.x(), pos.y() + scale);

            triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());

            break;
        }
    default:
        {
            cerr << "ERROR : Direction is not defined" << endl;
            break;
        }
    }
}

void viewerOnWINBGI::printTarget(const target& t) const
{
    point pos = t.getPosition() * 2 * scale;

    int x = pos.x(), y = pos.y();
    circle(x, y, scale);
}

void viewerOnWINBGI::printWall(const wall& w) const
{
    point pos = w.getPosition() * 2 * scale;

    int left = pos.x() - scale;
    int top = pos.y() + scale;
    int right = pos.x() + scale;
    int bottom = pos.y() - scale;

    rectangle(left, top, right, bottom);
}

// ---------- End of functions ----------

// ---------- Global functions ----------

// ---------- End of global functions ----------
