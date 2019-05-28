/**
 * 1. C++ does not support returning the address of a local variable outside of a function
 *    unless the local variable is defined as local static variable, global variable or
 *    variable that dynamically allocate memory locally.
 */
//for example:
int *getRandom() {
    static int r[6] = {1, 2, 3, 4, 5, 6}; // rather than int r[10];

    int *r;
    r = new int[6]{1, 2, 3, 4, 5, 6};

    //全局变量
    //...
    return r;
}
/**
 * 2.
 *
 */