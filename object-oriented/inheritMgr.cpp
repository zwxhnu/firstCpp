//
// Created by Apple on 2019-05-01.
//
#include <iostream>

using namespace std;

class Shape {
protected:
    int width;
    int height;
public:
    void setWidth(int w) {
        this->width = w;
    }

    void setHeight(int h) {
        this->height = h;
    }
};

class PaintCost {
public:
    int getCost(int area) {
        return 70 * area;
    }
};

/**
 * Access control and inheritance
 * access           public          protected           private
 * same class       yes             yes                 yes
 * derived class    yes             yes                 no
 * external class   yes             no                  no
 *
 * A derived class inherits all methods of the base class, with the following exceptions:
 * 1. The constructor, destructor, and copy constructor of the base class
 * 2. The overloaded operator of the base class
 * 3. The friend function of the base class
 *
 * Inheritance type
 * 1. public inheritance
 * 2. protected inheritance
 * 3. private inheritance
 */
class Rectangle : public Shape, public PaintCost {
public:
    int getArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect;
    rect.setWidth(4);
    rect.setHeight(6);
    int area = rect.getArea();

    cout << "Total area: " << area << endl;
    cout<< "Total paint cost: "<< rect.getCost(area)<<endl;

    return 0;
}