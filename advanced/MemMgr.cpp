//
// Created by Apple on 2019-04-25.
//
#include <iostream>

using namespace std;

class Box {
public:
    Box() {
        cout << "call constructor" << endl;
    }

    ~Box() {
        cout << "call destructor" << endl;
    }
};

int main(int argc, char *argv[]) {
    double *pvalue = NULL;
    pvalue = new double;
    *pvalue = 29.91;
    cout << "Value of pvalue: " << *pvalue << endl;
    delete pvalue;

    /* linear array      */
    int *pone;
    pone = new int[8];
    for (int i = 0; i < 8; ++i) {
        pone[i] = i;
    }
    cout<<"linear: "<<endl;
    for (int i = 0; i < 8; ++i) {
        cout<<pone[i]<<"\t";
    }
    cout<<endl;

    /* two-dimension array      */
    int **p;
    p = new int *[4];
    for (int i = 0; i < 4; ++i) {
        p[i] = new int[8];
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            p[i][j] = i * j;
        }
    }
    cout<<"two-dimension: "<<endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] p[i];
    }
    delete[] p;

    /* three-dimensions array      */
    int ***pthree;
    pthree = new int **[2];
    for (int i = 0; i < 2; ++i) {
        pthree[i] = new int *[3];
        for (int j = 0; j < 3; ++j) {
            pthree[i][j] = new int[4];
        }
    }
    cout<<"three-dimensions: "<<endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                pthree[i][j][k] = i + j + k;
                cout << pthree[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            delete[] pthree[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        delete[] pthree[i];
    }
    delete pthree;

    /* Object dynamic memory allocation      */
    Box *mybox = new Box[4];
    delete[] mybox;

    return 0;
}