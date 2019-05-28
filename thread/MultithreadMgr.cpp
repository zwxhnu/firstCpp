//
// Created by Apple on 2019-05-17.
//

#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std;
int i = 0;
condition_variable cv;
/**
 *This mutex is used for three purposes:
 * 1) to synchronize accesses to i
 * 2) to synchronize accesses to std::cerr
 * 3) for the condition variable cv
 */
mutex mutex1;
int x = 0;

/**
 * [this]{return !Empety();}
 * 是C++11新引入的功能，lambda表达式，是一种匿名函数。方括号内表示捕获变量。当lambda表达式返回true时
 * （即queue不为空），wait函数会锁定mutex。当lambda表达式返回false时，wait函数会解锁mutex同时会
 * 将当前线程置于阻塞或等待状态。
 */
void waits() {
    unique_lock<std::mutex> lk(mutex1);
    cout << "Waiting..." << endl;
    cv.wait(lk, [] { return i == 1; });
    cout << "Waiting finished! i==1" << endl;
}

void signals() {
    this_thread::sleep_for(chrono::seconds(1));

    {
        unique_lock<std::mutex> lk(mutex1);
        cout << "Notifying..." << endl;
    }
    cv.notify_all();
    {
        unique_lock<std::mutex> lk(mutex1);
        i = 1;
        cout << "Notifying again..." << endl;
    }
    cv.notify_all();
}

void test1() {
    thread t1(waits), t2(waits), t3(waits), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

class Thread1 {
public:
    Thread1() {}

    ~Thread1() {}

    void prod() {
        while (true) {
            unique_lock<mutex> lk(mutex1);
            cv.wait(lk, [] { return i == 0; });
            x = rand() % 1000;
            cout << "produce: " << x << endl;

            i = 1;
//            lk.unlock();
            cv.notify_all();
            this_thread::sleep_for(chrono::milliseconds(rand() % 1000 + 1000));
        }
    }
};

class Thread2 {
public:
    Thread2() {}

    ~Thread2() {}

    int cons() {
        while (true) {
            unique_lock<mutex> lk(mutex1);
            cv.wait(lk, [] { return i == 1; });
            cout << "consume: " << x << endl;

            i = 0;
//            lk.unlock();
            cv.notify_all();
            this_thread::sleep_for(chrono::milliseconds(rand() % 1000 + 10));
        }
    }
};

int main() {
//    test1();
    srand(time(NULL));

    Thread1 *tc1 = new Thread1();
    Thread2 *tc2 = new Thread2();

    thread t1(&Thread1::prod, tc1);
    thread t2(&Thread2::cons, tc2);

    t2.join();
    this_thread::sleep_for(10ms);
    t1.join();

    return 0;
}