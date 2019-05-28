//
// Created by Apple on 2019-05-02.
//
#include <iostream>

using namespace std;

/**
 * C++ polymorphism means that when a member function is called, different functions
 * are executed depending on the type of the object that called the function.
 *
 * There are three conditions that must be established to form a polymorphism
 * 1. There must be an inheritance relationship.
 * 2. The inheritance relationship must have the same name virtual function(where the
 * virtual function is a function declared in the base class using the keyword virtual,
 * when the virtual function defined in the base class is redefined in the derived class,
 * it will tell the compiler not to statically link to the function.)
 * 3. There is a pointer or reference of the base class type, and the virtual function
 * is called by the pointer or reference.
 */
class Shape {
protected:
    int width;
    int height;
public:
    Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    }

    virtual int area() {
        cout << "Parent class area : " << endl;
        return 0;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int a, int b) {
        Shape(a, b);
    }

    virtual int area() {
        cout << "Rectangle class area : " << endl;
        return width * height;
    }
};

class Triangle : public Shape {
public:
    Triangle(int a, int b) {
        Shape(a, b);
    }

    virtual int area() {
        cout << "Triangle class area : " << endl;
        return (width * height) / 2;
    }
};

int main() {
    Shape *shape;
    Rectangle rect(10, 7);
    Triangle triangle(10, 5);

    shape = &rect;
    shape->area();

    shape = &triangle;
    shape->area();

    return 0;
}