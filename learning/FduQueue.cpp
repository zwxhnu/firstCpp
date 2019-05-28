//
// Created by Apple on 2019-05-09.
//
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <cmath>
#include <math.h>
#include "FduQueue.h"
#include <thread>

using namespace std;

Node::Node(const int id, string data, Node *nextNode) {
    this->id = id;
    this->data = data;
    this->next = nextNode;
}

void Node::print() {
    lock_guard<mutex> lk(cout_mtx);
    cout << "ID: " << this->id << "\t Data: " << this->data << endl;
}

//void *Node::operator new(size_t size) {
//    return mp.malloc();
//}

//void Node::operator delete(void *p) {
//    return mp.free(p);
//}
template<class T>
FduQueue<T>::FduQueue() {
    this->front = NULL;
    this->rear = NULL;
    this->num = 0;
}

template<class T>
FduQueue<T>::~FduQueue() {
    this->clear();
}

template<class T>
bool FduQueue<T>::empty() const {
    lock_guard<mutex> lk(mtx);
    return this->num == 0;
}

template<class T>
int FduQueue<T>::size() const {
    std::lock_guard<std::mutex> lk(mtx);
    return this->num;
}

template<class T>
void FduQueue<T>::clear() {
    lock_guard<mutex> lk(mtx);
    T *temp = this->front;
    while (temp != NULL) {
        this->front = this->front->next;
        delete temp;
        temp = this->front;
    }
    this->rear = this->front = NULL;
    this->num = 0;
}

template<class T>
void FduQueue<T>::push(T &item) {
    unique_lock<mutex> lk(mtx);
    //给新加入节点分配空间
    T *newNode = (T *) std::malloc(sizeof(T));
    newNode->id = item.id;
    newNode->data = item.data;
    newNode->next = NULL;

    if (this->front == NULL) {
        this->front = this->rear = newNode;
    } else {
        this->rear->next = newNode;
        this->rear = this->rear->next;
    }
    this->num++;
    mtx.unlock();
    cond.notify_one();
}

//队列为空则阻塞
template<class T>
T *FduQueue<T>::wait_pop() {
    unique_lock<mutex> lk(mtx);
    cond.wait(lk, [this] { return num > 0; });
    //当前只有一个节点时，front和rear都指向NULL；否则front指向下一个节点即可
    T *temp = this->front;
    if (temp == this->rear) {
        this->rear = this->front = NULL;
    } else {
        this->front = this->front->next;
    }
    temp->next = nullptr;
    this->num--;
    return temp;
}

//队列为空则返回false
template<class T>
bool FduQueue<T>::try_pop() {
    unique_lock<mutex> lk(mtx);
    if (this->num == 0) {
        cout << "FduQueue is empty!" << endl;
        return false;
    }
    //当前只有一个节点时，front和rear都指向NULL；否则front指向下一个节点即可
    T *temp = this->front;
    if (temp == this->rear) {
        this->rear = this->front = NULL;
    } else {
        this->front = this->front->next;
    }
    delete temp;
    this->num--;
    return true;
}

template<class T>
T *FduQueue<T>::wait_top() {
    unique_lock<mutex> lk(mtx);
    cond.wait(lk, [this] { return num > 0; });
    return front;
}

template<class T>
T *FduQueue<T>::try_top() {
    lock_guard<mutex> lk(mtx);
    if (this->num == 0) {
        cout << "FduQueue is empty!" << endl;
        return this->front;
    }
    return this->front;
}

template<class T>
NodeMemPool<T>::NodeMemPool(size_t nodeSize,
                            int numOfNodes) {
    //初始化数据
    this->node_size_ = nodeSize;
    this->nodes_num_ = numOfNodes;
    this->free_node_header_ = nullptr;
    this->mem_block_header_ = nullptr;
}

template<class T>
NodeMemPool<T>::~NodeMemPool() {
    memBlock *ptr;
    //将所有分配给块的内存进行释放
    while (this->mem_block_header_ != NULL) {
        ptr = this->mem_block_header_->next_block;
        delete this->mem_block_header_;
        this->mem_block_header_ = ptr;
    }
}

template<class T>
void *NodeMemPool<T>::malloc() {
    unique_lock<mutex> lk(mtx);
    //没有空闲块的时候，需要重新申请一个块并加入memPool
    if (this->free_node_header_ == NULL) {
        //申请内存block
        memBlock *newBlock = (memBlock *) std::malloc(sizeof(memBlock));
        newBlock->nodes = (T *) std::malloc(this->node_size_ * this->nodes_num_);
        newBlock->next_block = NULL;
        //block中节点通过指针进行连接
        this->free_node_header_ = &newBlock->nodes[0];
        for (int i = 0; i < this->nodes_num_ - 1; ++i) {
            newBlock->nodes[i].next = &newBlock->nodes[i + 1];
        }
        newBlock->nodes[this->nodes_num_ - 1].next = NULL;
        //mem_block_header为NULL时则指向当前分配块，否则连入memPool再指向当前分配块
        if (this->mem_block_header_ == NULL) {
            this->mem_block_header_ = newBlock;
        } else {
            newBlock->next_block = this->mem_block_header_;
            this->mem_block_header_ = newBlock;
        }
    }
    //返回当前空闲节点，同时free_node_header_指向下一个空闲节点
    void *ret = this->free_node_header_;
    this->free_node_header_ = this->free_node_header_->next;
    return ret;
}

template<class T>
void NodeMemPool<T>::free(void *item) {
    unique_lock<mutex> lk(mtx);
    T *node = (T *) item;
    if (node == nullptr)
        return;
    node->next = this->free_node_header_;
    this->free_node_header_ = node;
}
