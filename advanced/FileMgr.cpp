//
// Created by Apple on 2019-05-02.
//
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char data[100];
    ofstream outfile;
    outfile.open("afile.dat",ios::app);

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    //writes data user entered to a file
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();

    ifstream infile;
    infile.open("afile.dat");
    cout << "Reading from the file" << endl;
    while (infile >> data) {
        cout << data << endl;
    }
    infile.close();

    return 0;
}