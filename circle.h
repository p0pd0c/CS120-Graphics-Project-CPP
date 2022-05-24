#ifndef GRAPHICSEXAMPLES_CIRCLE_H
#define GRAPHICSEXAMPLES_CIRCLE_H

#include "Quad.h"

class Circle : public Quad {
private:
    double radius;
public:
    /* Constructors */
    Circle();
    explicit Circle(double radius);
    explicit Circle(color fill);
    explicit Circle(point center);
    Circle(color fill, point center);
    Circle(double red, double green, double blue, double alpha);
    Circle(double x, double y);
    Circle(double red, double green, double blue, double alpha, double x, double y);
    Circle(color fill, double x, double y);
    Circle(double red, double green, double blue, double alpha, point center);
    Circle(color fill, double radius);
    Circle(point center, double radius);
    Circle(color fill, point center, double radius);
    Circle(double red, double green, double blue, double alpha, double radius);
    Circle(double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius);
    Circle(color fill, double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha, point center, double radius);

    /* Destructor */
    virtual ~Circle() = default;

    /* Getters */
    double getRadius() const;
    int getLeftX() const override;
    int getRightX() const override;
    int getTopY() const override;
    int getBottomY() const override;

    /* Setter */
    void setRadius(double r);
    void changeRadius(double delta);

    /* Draw */
    void draw() const override;

};

#endif //GRAPHICSEXAMPLES_CIRCLE_H