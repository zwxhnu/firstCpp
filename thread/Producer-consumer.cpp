//
// Created by Apple on 2019-05-17.
//
#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <string>

using namespace std;

class Buffer {
private:
    mutex mtx;
    condition_variable cond;
    deque<int> queue;
    int m_size;
public:
    Buffer() {
        m_size = 1;
    }

    Buffer(int s) {
        m_size = s;
    }

    void add(int item) {
        while (true) {
            unique_lock<mutex> lk(mtx);
            cond.wait(lk, [this] { return queue.size() < m_size; });
            cout << "queue.size():\t" << queue.size() << endl;
            queue.push_back(item);
            cond.notify_all();
            return;
        }
    }

    int remove() {
        while (true) {
            unique_lock<mutex> lk(mtx);
            cond.wait(lk, [this] { return queue.size() > 0; });
            int x = queue.back();
            queue.pop_back();

            cond.notify_all();
            return x;
        }
    }
};

class Producer {
private:
    Buffer *buf;
    string id;
public:
    Producer() {
        buf = nullptr;
    }

    Producer(string id, Buffer *buf) {
        this->id = id;
        this->buf = buf;
    }

    void produce() {
        while (true) {
            int x = rand() % 10000;

            buf->add(x);
            cout << "produce: " << x << endl;
            time_t tm = rand() % 1000 + 10;
            this_thread::sleep_for(chrono::milliseconds(tm));
        }
    }
};

class Consumer {
private:
    string id;
    Buffer *buf;
public:
    Consumer() {
        buf = nullptr;
    }

    Consumer(string id, Buffer *buf) {
        this->id = id;
        this->buf = buf;
    }

    void consume() {
        while (true) {
            int x = buf->remove();
            cout << "consume: " << x << endl;

            time_t tm = rand() % 2000 + 10;
            this_thread::sleep_for(chrono::milliseconds(tm));
        }
    }
};

int main(int argc, char *argv[]) {
    srand(time(NULL));

    Buffer *buf = new Buffer(stoi(argv[1]));
    Producer *prod = new Producer("prod", buf);
    Consumer *cons = new Consumer("cons", buf);

    thread pt(&Producer::produce, prod);
    thread ct(&Consumer::consume, cons);

    pt.join();
    ct.join();


    return 0;
}