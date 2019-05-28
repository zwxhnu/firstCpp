//
// Created by Apple on 2019-05-10.
//
/** @see https://www.geeksforgeeks.org/when-do-we-pass-arguments-by-reference-or-pointer/
 * 1. Declare
 * Pointers: A pointer is a variable that holds memory address of another variable. A
 * pointer needs to be de-referenced with * operator to access the memory location it
 * points to.
 * References : A reference variable is an alias, that is, another name for an already
 * existing variable. A reference, like a pointer is also implemented by storing the
 * address of an object.
 * A reference can be thought of as a constant pointer (not to be confused with a
 * pointer to a constant value!) with automatic indirection, i.e the compiler will
 * apply the * operator for you.
 *
 * 2. Difference
 * 1) Initalisation
 * 2) Reassignment
 *  A pointer can be re-assigned. This property is useful for implementation of data
 *   structures like linked list, tree, etc.
 *  On the other hand, a reference cannot be re-assigned, and must be assigned at
 *  initialization.
 * 3) Memory Address: A pointer has its own memory address and size on the stack
 * whereas a reference shares the same memory address (with the original variable)
 * but also takes up some space on the stack.
 * 4) NULL value: Pointer can be assigned NULL directly, whereas reference cannot.
 * The constraints associated with references (no NULL, no reassignment) ensure that
 * the underlying operations do not run into exception situation.
 * 5) Indirection: You can have pointers to pointers offering extra levels of
 * indirection. Whereas references only offer one level of indirection.I.e,
 * 6) Arithmetic operations: Various arithmetic operations can be performed on pointers
 * whereas there is no such thing called Reference Arithmetic.(but you can take the
 * address of an object pointed by a reference and do pointer arithmetics on it as
 * in &obj + 5).
 *
 * 3. when to use what
 * Use references
 *    1)In function parameters and return types.
 * Use pointers:
 *    1)Use pointers if  pointer arithmetic or passing NULL-pointer is needed.
 *  For example for arrays (Note that array access is implemented using pointer
 *  arithmetic).
 *    2)To implement data structures like linked list, tree, etc and their algorithms
 *  because to point different cell,we have to use the concept of pointers.
 *
 * 4. When do we pass arguments by reference or pointer?
 * In C++, variables are passed by reference due to following reasons:
 * 1) To modify local variables of the caller function
 * 2) For passing large sized arguments
 * 3) To avoid Object Slicing
 *   If we pass an object of subclass to a function that expects an object of superclass
 *   then the passed object is sliced if it is pass by value. For example, consider the
 *   following program, it prints “This is Pet Class”.
 * 4) To achieve Run Time Polymorphism in a function
 *   We can make a function polymorphic by passing objects as reference (or pointer)
 *   to it. For example, in the following program, print() receives a reference to the
 *   base class object. print() calls the base class function show() if base class
 *   object is passed, and derived class function show() if derived class object is
 *   passed.
 */

#include <iostream>
#include<string>

using namespace std;

class Pet {
public:
    virtual string getDescription() const {
        return "This is Pet class";
    }
};

class Dog : public Pet {
public:
    virtual string getDescription() const {
        return "This is Dog class";
    }
};

void describe(Pet p) { // Slices the derived class object
    cout << p.getDescription() << endl;
}

int main() {
    Dog d;
    describe(d);
    return 0;
}

/*
#include<iostream>
using namespace std;

class base {
public:
	virtual void show() { // Note the virtual keyword here
		cout<<"In base \n";
	}
};


class derived: public base {
public:
	void show() {
		cout<<"In derived \n";
	}
};

// Since we pass b as reference, we achieve run time polymorphism here.
void print(base &b) {
	b.show();
}

int main(void) {
	base b;
	derived d;
	print(b);
	print(d);
	return 0;
}
 */