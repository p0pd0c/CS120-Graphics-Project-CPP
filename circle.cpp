#include "circle.h"

#include "graphics.h"



Circle::Circle() : Quad(), radius(0) {

}



Circle::Circle(double radius) : Quad() {

    setRadius(radius);

}



Circle::Circle(color fill) : Quad(fill), radius(0) {

}



Circle::Circle(point center) : Quad(center), radius(0) {

}



Circle::Circle(color fill, point center) : Quad(fill, center), radius(0) {

}



Circle::Circle(double red, double green, double blue, double alpha) : Quad({red, green, blue}), radius(0) {

}



Circle::Circle(double x, double y) : Quad(point {static_cast<int>(x), static_cast<int>(y)}), radius(0) {

}



Circle::Circle(double red, double green, double blue, double alpha, double x, double y) : Quad({red, green, blue}, {static_cast<int>(x), static_cast<int>(y)}), radius(0) {

}



Circle::Circle(color fill, double x, double y) : Quad(fill, {static_cast<int>(x), static_cast<int>(y)}), radius(0) {

}



Circle::Circle(double red, double green, double blue, double alpha, point center) : Quad({red, green, blue}, center), radius(0) {

}



Circle::Circle(color fill, double radius) : Quad(fill) {

    setRadius(radius);

}



Circle::Circle(point center, double radius) : Quad(center) {

    setRadius(radius);

}



Circle::Circle(color fill, point center, double radius) : Quad(fill, center) {

    setRadius(radius);

}



Circle::Circle(double red, double green, double blue, double alpha, double radius) : Quad({red, green, blue}) {

    setRadius(radius);

}



Circle::Circle(double x, double y, double radius) : Quad(point {static_cast<int>(x), static_cast<int>(y)}) {

    setRadius(radius);

}



Circle::Circle(double red, double green, double blue, double alpha, double x, double y, double radius) : Quad({red, green, blue}, {static_cast<int>(x), static_cast<int>(y)}) {

    setRadius(radius);

}



Circle::Circle(color fill, double x, double y, double radius) : Quad(fill, {static_cast<int>(x), static_cast<int>(y)}) {

    setRadius(radius);

}



Circle::Circle(double red, double green, double blue, double alpha, point center, double radius) : Quad({red, green, blue}, center) {

    setRadius(radius);

}



double Circle::getRadius() const {

    return radius;

}



int Circle::getLeftX() const {

    return center.x - radius;

}



int Circle::getRightX() const  {

    return center.x + radius;

}



int Circle::getTopY() const {

    return center.y - radius;

}



int Circle::getBottomY() const {

    return center.y + radius;

}



void Circle::setRadius(double r) {

    if (r < 0) {

        r = 0;

    }

    radius = r;

}



void Circle::changeRadius(double delta) {

    setRadius(radius + delta);

}



void Circle::draw() const {

    // Set drawing color to fill color

    glColor3f(fill.red, fill.green, fill.blue);

    // Draw circle as Triangle Fan

    glBegin(GL_TRIANGLE_FAN);

    // Draw center point

    glVertex2i(center.x, center.y);

    // Draw points on edge of circle

    for (double i = 0; i < 2.0*PI+0.05; i += (2.0*PI)/360.0) {

        glVertex2i(center.x + (radius * cos(i)),

                   center.y + (radius * sin(i)));

    }

    // End Triangle Fan

    glEnd();

}
