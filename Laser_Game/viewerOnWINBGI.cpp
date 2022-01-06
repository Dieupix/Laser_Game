//Declaring libraries
#include "viewerOnWINBGI.h"

//---------- Constructors------------------------------
viewerOnWINBGI::viewerOnWINBGI() :  width{500},
                                    height{500},
                                    scale{20}
{
    initialize();
}

viewerOnWINBGI::viewerOnWINBGI(unsigned new_width, unsigned new_height, float new_scale = 20) : width{new_width},
                                                                                                height{new_height},
                                                                                                scale{new_scale}

{
    initialize();
}
//---------- End of constructors-----------------------
//---------- Destructor--------------------------------
viewerOnWINBGI::~viewerOnWINBGI()
{
    closegraph();
}
//---------- End of Destructor-------------------------
//---------- Setter------------------------------------
void viewerOnWINBGI::setWidth(unsigned new_width)
{
    this->width = new_width;
}

void viewerOnWINBGI::setHeight(unsigned new_height)
{
    this->height = new_height;
}

void viewerOnWINBGI::setScale(float new_scale)
{
    this->scale = new_scale;
}
//---------- End of Setter-----------------------------
//---------- Getter------------------------------------
unsigned viewerOnWINBGI::getWidth() const
{
    return this->width;
}

unsigned viewerOnWINBGI::getHeight() const
{
    return this->height;
}

float viewerOnWINBGI::getScale() const
{
    return this->scale;
}
//---------- End of Getter-----------------------------
//---------- Methods ----------------------------------
void viewerOnWINBGI::print(const unique_ptr<object>& obj) const
{
    //There are many possibilities (1 per object)
    //If this object is a laser
    if(dynamic_cast<laser*>(obj.get()))
    {
        auto print_laser = dynamic_cast<laser*>(obj.get());
        printLaser(*print_laser);
    }
    //If this object is a mirror
    else if(dynamic_cast<mirror*>(obj.get()))
    {
        auto print_mirror = dynamic_cast<mirror*>(obj.get());
        printMirror(*print_mirror);
    }
    //If this object is a shooter
    else if(dynamic_cast<shooter*>(obj.get()))
    {
        auto print_shooter = dynamic_cast<shooter*>(obj.get());
        printShooter(*print_shooter);
    }
    //If this object is a target
    else if(dynamic_cast<target*>(obj.get()))
    {
        auto print_target = dynamic_cast<target*>(obj.get());
        printTarget(*print_target);
    }
    //If this object is a wall
    else if(dynamic_cast<wall*>(obj.get()))
    {
        auto print_wall = dynamic_cast<wall*>(obj.get());
        printWall(*print_wall);
    }
    //If this object is an unknown type
    else
        cerr << "Unknown type" << endl;
}

void viewerOnWINBGI::printGround(const ground& g) const
{
    //Clear window
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
                //If ther are not object, print a pixel
                point position = point(j, i) + g.getPosition();
                position *= 2 * scale;
                plot(position.x(), position.y());
            }
        }
    }
    waituntilbuttonpressed();
}

void viewerOnWINBGI::printLaser(const laser& l) const
{
    point position = l.getPosition() * 2 * scale;
    //There are 4 possibilities
    switch(l.getDirection())
    {
        //RIGHT or LEFT
        case RIGHT:
        case LEFT:
            {
                //Initializing position
                int x0 = position.x() - scale;
                int y0 = position.y();
                int x1 = position.x() + scale;
                int y1 = position.y();
                //Print
                line(x0, y0, x1, y1);
                break;
            }
        //UP or DOWN
        case UP:
        case DOWN:
            {
                //Initializing position
                int x0 = position.x();
                int y0 = position.y() + scale;
                int x1 = position.x();
                int y1 = position.y() - scale;
                //Print
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
    point position = m.getPosition() * 2 * scale;

    int left    = position.x() - scale;
    int top     = position.y() + scale;
    int right   = position.x() + scale;
    int bottom  = position.y() - scale;
    //There are 2 possibilities
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
    point position = s.getPosition() * 2 * scale;

    point left, right, top;
    //There are 4 possibilities
    switch(s.getDirection())
    {
        case RIGHT:
            {
                left  = point(position.x() - scale, position.y() - scale);
                right = point(position.x() - scale, position.y() + scale);
                top   = point(position.x() + scale, position.y());

                triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());
                break;
            }
        case LEFT:
            {
                left  = point(position.x() + scale, position.y() + scale);
                right = point(position.x() + scale, position.y() - scale);
                top   = point(position.x() - scale, position.y());

                triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());
                break;
            }
        case UP:
            {
                left  = point(position.x() - scale, position.y() + scale);
                right = point(position.x() + scale, position.y() + scale);
                top   = point(position.x(), position.y() - scale);

                triangle(left.x(), left.y(), right.x(), right.y(), top.x(), top.y());
                break;
            }
        case DOWN:
            {
                left  = point(position.x() + scale, position.y() - scale);
                right = point(position.x() - scale, position.y() - scale);
                top   = point(position.x(), position.y() + scale);

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
    //Initialize position of the target
    point position = t.getPosition() * 2 * scale;
    int x = position.x(), y = position.y();
    //Target is a circle
    circle(x, y, scale);
}

void viewerOnWINBGI::printWall(const wall& w) const
{
    //Initialize position of the wall
    point position = w.getPosition() * 2 * scale;

    int left   = position.x() - scale;
    int top    = position.y() + scale;
    int right  = position.x() + scale;
    int bottom = position.y() - scale;

    //Target is a rectangle
    rectangle(left, top, right, bottom);
}
//---------- End of methods ----------------------------
//---------- Private Methods ---------------------------
void viewerOnWINBGI::initialize()
{
    opengraphsize(width, height);
    setbkcolor(BLACK);
    setcolor(WHITE);
}
//---------- End of private methods --------------------
