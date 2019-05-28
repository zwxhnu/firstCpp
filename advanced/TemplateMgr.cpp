//
// Created by Apple on 2019-05-03.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * function template general form:
 * template <class type> ret-type func-name(parameter list){
 *      // content
 * }
 *
 */
template<typename T>
inline T const &Max(T const &a, T const &b) {
    return a < b ? b : a;
}


/**
 * Generic form of a generic class declaration
 * template <class type> class class-name {
 *      // content
 * }
 */
template<class T>
class Stack {
private:
    vector<T> elems;
public:
    void push(T const &);

    void pop();

    T top() const;

    bool empty() const {
        return elems.empty();
    }
};

template<class T>
void Stack<T>::push(T const &elem) {
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop() {
    if (elems.empty())
        throw out_of_range("Stack<T>::pop(): empty stack");
    elems.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (elems.empty())
        throw out_of_range("Stack<T>::top(): empty stack");
    return elems.back();
}

int main() {
    int i = 20, j = 39;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 12.1, f2 = 14.9;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "hello", s2 = "world";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

    try {
        Stack<int> intstack;
        Stack<string> stringstack;

        intstack.push(7);
        cout << intstack.top() << endl;

        stringstack.push("Hello,world");
        cout << stringstack.top() << endl;
        stringstack.pop();
        stringstack.pop();
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
    return 0;
}