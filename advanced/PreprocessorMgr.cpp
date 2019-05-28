//
// Created by Apple on 2019-05-03.
//
#include <iostream>

using namespace std;

/**
 * All preprocessor directives start with a # sign.
 * #include #define #if #else #line
 */
#define PI 3.14159
#define MIN(a, b) (a < b ? a : b)
#define DEBUG

int main() {
    int i = 30;
    int j = 100;

    cout << PI << endl;
#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

#if 0
    /* This is the comment section     */
    cout<<MKSTR(HELLO C++)<<endl;
#endif

    cout << "Smaller value: " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming out of main function" << endl;
#endif

    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}