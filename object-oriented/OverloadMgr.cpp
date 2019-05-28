//
// Created by Apple on 2019-05-01.
//
#include <iostream>

using namespace std;

/**
 * C++ allows a single function and operator in the same scope to specify multiple
 * definitions, called function overloading and operator overloading.
 *
 * operator list that can be overloaded
 * +, -, *, /, %
 * ==, !=, <, >, <=, >=
 * ||, &&, !
 * +(positive), -(negative), *(pointer), &(take address)
 * ++, --
 * |, &, ~, ^, <<, >>
 * =, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=
 * new, delete, new[], delete[]
 * ()(function call), ->(member access), ,(comma), [](subscript)
 */
class printData {
public:
    void print(int i) {
        cout << "Integer is " << i << endl;
    }

    void print(double f) {
        cout << "Double is " << f << endl;
    }

    void print(char ch[]) {
        cout << "string is " << ch << endl;
    }
};

class Box {
private:
    double length;
    double breadth;
    double height;
public:
    Box() {

    }

    Box(double length, double breadth, double height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    ~Box() {

    }

    double getVolume(void) {
        return length * breadth * height;
    }

    Box operator+(const Box &b) {
        Box box;
        box.height = this->height + b.height;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        return box;
    }

    Box operator-() {
        length = -length;
        breadth = -breadth;
        height = -height;
        return Box(length, breadth, height);
    }

    bool operator==(const Box box) {
        return this->length == box.length && this->breadth == box.breadth
               && this->height == box.height;
    }

    friend ostream &operator<<(ostream &output, Box &box) {
        output << "length: " << box.length << "\tbreadth: " << box.breadth << "\theight: " << box.height << endl;
        return output;
    }

    friend istream &operator>>(istream &input, Box &box) {
        input >> box.length >> box.breadth >> box.height;
        return input;
    }

    void print() {
        cout << "length: " << length << "\tbreadth: " << breadth << "\theight: " << height << endl;
    }
};

int main() {
    printData pd;

    pd.print(5);
    pd.print(50.23);
    pd.print("Hello, C++");

    Box box1(6.0, 7.0, 5.0);
    Box box2(12.0, 13.0, 10.0);
    Box box3;

    box3 = box1 + box2;

    cout << "The volume of box1: " << box1.getVolume() << endl;
    cout << "The volume of box2: " << box2.getVolume() << endl;
    cout << "The volume of box3: " << box3.getVolume() << endl;

    -box1;
    box1.print();

    if (box1 == box2)
        cout << "box1 equals with box2" << endl;
    else
        cout << "box1 not equals with box2" << endl;

    cout << "Enter the value of object: " << endl;
    cin >> box3;
    cout << box3;

    Box box4;
    box4 = box2;
    cout << box4;

    return 0;
}