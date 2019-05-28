//
// Created by Apple on 2019-05-17.
//
#include <ctime>
#include <string>
#include <vector>
#include "FduQueue.h"
#include "FduQueue.cpp"

using namespace std;

const int NBPRODUCE = 10;
const int NBCONSUME = 5;
const int THPRODUCE = 15;
const int THCONSUME = 30;

template<class T>
class Producer {
private:
    FduQueue<T> *queue_;
    int pro_id_;
public:
    Producer() {
        queue_ = nullptr;
    }

    Producer(int pid, FduQueue<T> &que) {
        pro_id_ = pid;
        queue_ = &que;
    }

    void produce() {
        for (int i = 0; i < NBPRODUCE; ++i) {
            string str = "hello_world_" + to_string(pro_id_) + "_" + to_string(i);
            Node n(i, str, NULL);
            queue_->push(n);

            {
                lock_guard<mutex> lk(cout_mtx);
                cout << "Produce: " << pro_id_ << "\t ID: " << n.id << "\t Data: " << n.data << endl;
            }
            this_thread::sleep_for(chrono::milliseconds(rand() % 100 + 10));
        }
    }
};

template<class T>
class Consumer {
private:
    FduQueue<T> *queue_;
    int con_id_;
public:
    Consumer() {
        queue_ = nullptr;
    }

    Consumer(int cid, FduQueue<T> &que) {
        con_id_ = cid;
        queue_ = &que;
    }

    void consume() {
        for (int i = 0; i < NBCONSUME; ++i) {
            T *n = queue_->wait_pop();

            {
                lock_guard<mutex> lk(cout_mtx);
                cout << "Consume: " << con_id_ << "\t ID: " << n->id << "\t Data: " << n->data << endl;
            }
            this_thread::sleep_for(chrono::milliseconds(rand() % 100 + 10));
        }
    }
};

int main(int argc, char *argv[]) {
    srand(time(NULL));
    // Test 1:
    FduQueue<Node> queue;
    vector<thread> producers, consumers;

    for (int i = 0; i < THPRODUCE; ++i) {
        auto *p = new Producer<Node>(i, queue);
        thread prod(&Producer<Node>::produce, p);
        producers.push_back(std::move(prod));
    }

    for (int i = 0; i < THCONSUME; ++i) {
        auto *c = new Consumer<Node>(i, queue);
        thread cons(&Consumer<Node>::consume, c);
        consumers.push_back(std::move(cons));
    }

    for (auto &th:producers) {
        th.join();
    }
    for (auto &th:consumers) {
        th.join();
    }
    queue.clear();

    // Test 2: NodeMemPool
    NodeMemPool<Node> mp(sizeof(struct Node), 20);
    Node *n3 = (Node *) mp.malloc();
    n3->id = 3;
    n3->data = "Hello World!";
    Node *n4 = (Node *) mp.malloc();
    n4->id = 4;
    n4->data = "Hello World!";

    queue.push(*n3);
    queue.push(*n4);

    cout << "FduQueue \t" << "size: " << queue.size() << "\t" << "isEmpty: " << queue.empty() << endl;
    queue.clear();
    mp.free(n3);
    mp.free(n4);
    return 0;
}