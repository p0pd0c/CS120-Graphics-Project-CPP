#ifndef CONFETTIFY_QUAD_H
#define CONFETTIFY_QUAD_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h> // This allows you to use sqrt and pow functions
#include <string>

const double PI = 3.14159265358979323846;

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Quad {
protected:
    color fill;
    point center;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(color fill);
    Quad(point center);
    Quad(color fill, point center);
    Quad(color fill, point center, unsigned int width, unsigned int height);

    virtual int getCenterX() const;
    virtual int getLeftX() const;
    virtual int getRightX() const;
    virtual int getCenterY() const;
    virtual int getTopY() const;
    virtual int getBottomY() const;
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setCenter(point new_center);
    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};

#endif //CONFETTIFY_QUAD_H