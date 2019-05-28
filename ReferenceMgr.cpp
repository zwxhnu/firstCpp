//
// Created by Apple on 2019-04-26.
//

#include <iostream>

using namespace std;

void swap(int &x, int &y);

double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5};

double &setValue(int i);

int main() {
    /* A reference variable is an alias, that is, it is another name for an existing variable.
     * The difference between pointers and references
     * 1、There is no null reference. The reference must be connected to a valid block of memory.
     * 2、Once reference is initialized to an object, it cannot be pointed to another object.
     *    A pointer can point to another object at any time.
     * 3、Reference must be initialized at creation time. Pointer can be initialized at any time.
     *
     */
    int i;
    double d;
    int &r = i;
    double &s = d;
    i = 5;
    cout << "Value of i: " << i << endl;
    cout << "Value of i reference: " << r << endl;
    d = 11.7;
    cout << "Value of d: " << d << endl;
    cout << "Value of d reference: " << s << endl;

    /* reference as parameter     */
    int a = 100;
    int b = 200;
    cout << "The value of a before exchange: " << a << endl;
    cout << "The value of b before exchange: " << b << endl;
    swap(a, b);
    cout << "The value of a after exchange: " << a << endl;
    cout << "The value of b after exchange: " << b << endl;

    /* reference as the return value      */
    cout<<"value before change:"<<endl;
    for (int i = 0; i < 5; ++i) {
        cout<<"vals["<<i<<"] = "<< vals[i]<<endl;
    }
    setValue(1) = 6.6;
    setValue(3) = 7.7;
    cout<<"value after change:"<<endl;
    for (int i = 0; i < 5; ++i) {
        cout<<"vals["<<i<<"] = "<<vals[i]<<endl;
    }

    return 0;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

double &setValue(int i) {
    return vals[i];
}