//
// Created by Apple on 2019-04-26.
//
#include <iostream>
/**
 * The cstring header provides functions for dealing with C-style strings -- null-terminated
 * arrays of characters. This includes functions like strlen and strcpy. It is the C++ version
 * of the classic string.h from C.
 * The string header provides the std::string class and related functions and operators.
 *
 */
#include <cstring>
#include <string>

using namespace std;


class stringDemoC {
private:
    char str1[11];
    char str2[11];
    char str3[11];
public:
    stringDemoC() {

    }
};

int main() {
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    int len;

    //strcpy(s1,s2): copy s2 to s1
    strcpy(str3, str1);
    cout << str3 << endl;

    //strcat(s1,s2): connect s2 to the end of s1
    strcat(str1, str2);
    cout << str1 << endl;

    //strlen(s1): return the length of s1
    len = strlen(str1);
    cout << len << endl;

    //strcmp(s1,s2): return 0 if s1 and s2 are the same, the return value is less than 0 if s1<s2,
    // the return value is greater than 0 if s1>s2.
    int rval = strcmp(str1, str2);
    cout << rval << endl;

    //strchr(s1,ch): return a pointer to the first occurrence of the character ch in string s1
    char *p = strchr(str1, 'r');
    cout << p << endl;

    //strstr(s1,s2): return a pointer to the first occurrence of the string s2 in string s1
    p = strstr(str1, str2);
    cout << p << endl;


    string cppstr1 = "hello";
    string cppstr2 = "world";
    string cppstr3;
    int cpplen;

    //copy cppstr1 to cppstr3
    cppstr3 = cppstr1;
    cout << "cppstr3: " << cppstr3 << endl;

    //connect cppstr1 with cppstr2
    cppstr3 = cppstr1 + cppstr2;
    cout << "cppstr1 + cppstr2: " << cppstr3 << endl;

    //the length of cppstr3
    cpplen = cppstr3.size();
    cout << "cppstr3.size(): " << cpplen << endl;

    return 0;
}
