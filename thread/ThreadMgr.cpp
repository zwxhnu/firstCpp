//
// Created by Apple on 2019-05-17.
//
#include <iostream>
#include <thread>
#include <ctime>

using namespace std;


void independentThread() {
    cout << "Starting concurrent thread." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "Exiting concurrent thread." << endl;
}

void threadCaller() {
    cout << "Starting thread caller." << endl;
    thread t(independentThread);
//    t.detach();
    t.join();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Exiting thread caller." << endl;
}

/**
 * 测试线程的detach和join方法
 * 1.   Separates the thread of execution from the thread object, allowing execution to
 * continue independently. Any allocated resources will be freed once the thread exits.
 *      After calling detach *this no longer owns any thread.
 * 2.   Blocks the current thread until the thread identified by *this finishes its execution.
 *      The completion of the thread identified by *this synchronizes with the corresponding
 * successful return from join().
 *      No synchronization is performed on *this itself. Concurrently calling join()
 * on the same std::thread object from multiple threads constitutes a data race that
 * results in undefined behavior.
 */
void test1() {
    //    time_t now1 = time(0);
    std::chrono::milliseconds ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    time_t now1 = ms1.count();
    threadCaller();
//    time_t now2 = time(0);
    std::chrono::milliseconds ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    time_t now2 = ms2.count();
    cout << "now1: " << now1 << "\tnow2: " << now2 << "\tnow2-now1=" << now2 - now1 << endl;
    this_thread::sleep_for(chrono::seconds(2));
//    time_t now3 = time(0);
    std::chrono::milliseconds ms3 = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    time_t now3 = ms3.count();
    cout << "now2: " << now2 << "\tnow3: " << now3 << "\tnow3-now2=" << now3 - now2 << endl;
}

int main() {
    test1();
    return 0;
}