#include <iostream>
#include <cmath>
#include <string>
#include <thread>

using namespace std;
mutex mu1;

int *getRandom() {
//    static int r[6] = {1, 299, 388, 4, 5, 6};
    int *r;
    r = new int[6]{1, 299, 388, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        cout << *(r + i) << endl;
    }
    return r;
}

void Print() {
    unique_lock<mutex> lk(mu1);
    cout << "this is print!" << endl;
}

void DeadLock(double) {
    unique_lock<mutex> lk(mu1);
    cout << "this is a deadlock" << endl;
    Print();
}

int main() {
//    int a = 10;
//    int &x = a;
//    int &y = x;
//    cout << &x << endl;
//    cout << &a << endl;
//    cout << &y << endl;
//
//    void *p;
//    p = getRandom();


//    for (int i = 0; i < 6; i++) {
//        cout << *((int *)p + i) << endl;
//    }
//    delete p;
    string ss = "hello_" + to_string(0);
    cout << ss << endl;
    DeadLock(1.2);
    return 0;
}