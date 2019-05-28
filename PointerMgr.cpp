//
// Created by Apple on 2019-04-26.
//
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int *getRandom() {

    static int r[10];
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
}

int main() {
    /**
     * the actual data type of all pointer values, whether integer, float, character,
     * or any other data type, is the same, a long hexadecimal number that represents
     * a memory address.
     */

    /* introduction to pointers     */
    int var1;
    char var2[10];
    cout << "Address of the var1 variable: " << &var1 << endl;
    cout << "Address of the var2 variable: " << &var2 << endl;

    int var = 20;
    int *ip;

    ip = &var;//store the address of the var in the pointer variable

    cout << "Value of the var variable: " << var << endl;

    cout << "Address stored in the ip variable: " << ip << endl;

    //access the value of the address in the pointer ip
    cout << "Value of *ip variable: " << *ip << endl;


    /* Arithmetic operations on pointers including ++, --, +, -     */
    const int MAX = 3;
    int arr[MAX] = {10, 100, 200};
    int *ptr = arr;
    for (int i = 0; i < MAX; ++i) {
        cout << "Address of arr[" << i << "] = " << ptr << "\t";
        cout << "Value of arr[" << i << "] = " << *ptr << endl;
        ptr++;
    }

    ptr = &arr[MAX - 1];
    for (int i = MAX - 1; i >= 0; --i) {
        cout << "Address of arr[" << i << "] = " << ptr << "\t";
        cout << "Value of arr[" << i << "] = " << *ptr << endl;
        ptr--;
    }

    for (int i = 0, *ptr = arr; ptr <= &arr[MAX - 1]; ++i, ++ptr) {
        cout << "Address of arr[" << i << "] = " << ptr << "\t";
        cout << "Value of arr[" << i << "] = " << *ptr << endl;
    }

    *(arr + 2) = 1000;
    cout << arr[0] << "---" << arr[1] << "---" << arr[2] << endl;


    /* pointer arrays     */
    // ptrarr is declared as an array of MAX integer pointers
    int *ptrarr[MAX];
    for (int i = 0; i < MAX; ++i) {
        ptrarr[i] = &arr[i];
    }
    for (int i = 0; i < MAX; ++i) {
        cout << "Address of arr[" << i << "] = " << ptrarr[i] << "\t";
        cout << "Value of arr[" << i << "] = " << *ptrarr[i] << endl;
    }

    /* pointer to pointer       */
    int pvar = 3000;
    int *point;
    int **ppoint;

    point = &pvar;
    ppoint = &point;

    cout << "point: " << point << "\t" << "*point: " << *point << endl;
    cout << "ppoint: " << ppoint << "\t" << "*ppoint: " << *ppoint << "\t" << "**ppoint: " << **ppoint << endl;

    /* pass a pointer to function     */

    /* return a pointer from a function      */
    point = getRandom();
    for (int i = 0; i < 10; ++i) {
        cout<<"*(point+"<<i<<"): "<<*(point+i)<<endl;
    }
    return 0;
}
