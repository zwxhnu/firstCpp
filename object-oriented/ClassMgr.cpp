//
// Created by Apple on 2019-04-25.
//
#include <iostream>

using namespace std;

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    /* initialize the list to initialize the field     */
    // C::C( double a, double b, double c): X(a), Y(b), Z(c)
    Box();
    /**
     * In C++, every object can access its own address through the this pointer. The
     * this pointer is an implicit parameter for all member function, Therefore, inside
     * a member function, it can be used to point to the calling object.
     */
    Box(double length, double breadth, double height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    /**
     * 1. The destructor is executed each time the created object is deleted.
     * 2. The destructor helps to free resources before jumping out of the program(such as
     * closing files, freeing memory, etc.)
     */
    ~Box();

    void print() {
        cout << "length: " << length << "\t breadth: " << breadth << "\t height: " << height << endl;
    }

    /**
     * 1. A friend function of a class is defined outside the class, but has access to
     * all private and protected members of the class. Although the prototype of the friend
     * function has appeared in the definition of the class, the friend function is not
     * a member function.
     * 2. A friend can be a function called a friend function; A friend can also be a class
     * called a friend class, in which case the entire class and all its members are
     * friends.
     */
    friend void printLength(Box box);
};

Box::Box() {
    cout << "box object is being created" << endl;
    this->length = 0;
    this->breadth = 0;
    this->height = 0;
}

Box::~Box() {
    cout << "box object is being deleted" << endl;
}

void printLength(Box box){
    cout<<"the length of box: "<<box.length<<endl;
}

class Line {
private:
    int *ptr;
public:
    int getLength();

    Line(int len);

    /**
     * the copy constructor are commonly used for:
     * 1. initializes a newly created object by using another object of the same type.
     * 2. the copy object passes it as a parameter to the function.
     * 3. copy object and return it from the function.
     * @param obj
     */
    Line(const Line &obj);

    ~Line();
};

Line::Line(int len) {
    cout << "call constructor Line(int len)" << endl;
    //allocate memory space for ptr pointer
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj) {
    cout << "call the copy constructor and allocate memory space for ptr pointer." << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line() {
    cout << "free memory" << endl;
    delete ptr;
}

int Line::getLength() {
    return *ptr;
}

void display(Line obj) {
    cout << "the line size: " << obj.getLength() << endl;
}

int main(int argc, char *argv[]) {
    /**
     * 1. public inheritance: the access properties of the base class public member,
     * protected member, and private member become public, protected, private respectively
     * in the derived class.
     * 2. protected inheritance: the access properties of the base class public member,
     * protected member, and private member become protected, protected, private respectively
     * in the derived class.
     * 3. private inheritance: the access properties of the base class public member,
     * protected member, and private member become private, private, private respectively
     * in the derived class.
     *
     * Regardless of public, protected, or private inheritance, the following two points
     * have not changed.
     * 1. private members can be accessed by members of this class(within the class) and
     * friends, and cannot be accessed by derived classes.
     * 2. protected members can be accessed by derived classes.
     */
    Box box1;
    Box box2(12, 6.4, 3.2);
    Box *ptrBox;

    box1.print();
    box2.print();
    /* pointer to class      */
    ptrBox = &box2;
    ptrBox->print();
    printLength(box2);

    Line line1(10);
    Line line2 = line1;

    display(line1);
    display(line2);

    return 0;
}
