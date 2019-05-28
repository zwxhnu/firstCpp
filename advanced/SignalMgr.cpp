//
// Created by Apple on 2019-05-03.
//
#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received." << endl;
    exit(signum);
}

int main() {
    int i = 0;
    signal(SIGINT, signalHandler);
    while (++i) {
        cout << "Going to sleep..." << endl;
        if (i == 5) {
            raise(SIGINT);
        }
        sleep(1);
    }

    return 0;
}