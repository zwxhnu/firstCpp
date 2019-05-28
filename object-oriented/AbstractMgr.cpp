//
// Created by Apple on 2019-05-02.
//
#include <iostream>

using namespace std;


/**
 * C++ interfaces are implemented using abstract classes. Abstract classes are not
 * confused with data abstractions. Data abstraction is a concept that separates implementation
 * details from related data.
 *
 * If at least one function in the class is declared as a pure virtual function, then
 * this class is an abstract class.
 */
class Shape {
protected:
    double width;
    double height;
public:
    virtual double getArea() = 0;

    void setWidth(int w) {
        this->width = w;
    }

    void setHeight(int h) {
        this->height = h;
    }
};

class Rectangle : public Shape {
public:
    double getArea() {
        return width * height;
    }
};

class Triangle : public Shape {
public:
    double getArea() {
        return (width * height) / 2;
    }
};

int main() {
    Rectangle rect;
    Triangle tri;

    rect.setWidth(5);
    rect.setHeight(7);
    cout << "Total rectangle area : " << rect.getArea() << endl;

    tri.setWidth(5);
    tri.setHeight(7);
    cout << "Total triangle area : " << tri.getArea() << endl;
    return 0;
}