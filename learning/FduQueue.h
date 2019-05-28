/// @file FduQueue.h
/// @brief 概述
/// 并发队列头文件，定义了Node节点信息，Queue以及memPool的相关声明
///
/// @author zouwenxiong z_wenxiong@163.com
/// @version maj.min
/// @date 2019/05/20
///

#ifndef FIRSTCPP_FDUQUEUE_H
#define FIRSTCPP_FDUQUEUE_H

#include <mutex>
#include <condition_variable>
#include <string>

///
/// @brief Node节点信息
///
/// 详细概述
///
struct Node {
    int id;
    std::string data;///< 存放节点的数据
    Node *next;///< 指向下一个节点

    ///
    /// 构造声明
    ///
    Node(const int id, std::string data, Node *nextNode = NULL);

    ///
    /// 打印id和data
    ///
    void print();

//    void *operator new(size_t size);

//    void operator delete(void *p);
};

/// Note: 内存池中内存块的大小是固定的，内存节点的大小也是固定的。内存块在申请之初就被划分为多个内存节点，每个Node的大小为ItemSize。
template<class T>
class NodeMemPool {
public:
    /// 节点大小
    size_t node_size_;
    /// 每个块中节点个数
    int nodes_num_ = 20;
    /// 指向空闲节点的指针
    T *free_node_header_;
    /// 块结构体定义，由多个节点和块指针组成
    struct memBlock {
        T *nodes;
        memBlock *next_block;
    };
    memBlock *mem_block_header_;///< 指向当前块的指针
    mutable std::mutex mtx;
    mutable std::condition_variable cv;
public:
    NodeMemPool(size_t nodeSize, int numOfNodes);

    ~NodeMemPool();

    void *malloc();

    void free(void *item);
};

NodeMemPool<Node> mp(sizeof(struct Node), 20);
std::mutex cout_mtx;

template<class T>
class FduQueue {
private:
    int num; ///< 队列元素个数
    T *front;///< 队列首指针
    T *rear;///< 队列尾指针
    mutable std::mutex mtx;///< 互斥量
    mutable std::condition_variable cond;///< 条件变量

public:
    ///
    /// 构造函数
    /// @todo xxx
    ///
    FduQueue();

    ///
    /// 析构函数
    ///
    ~FduQueue();

    ///
    /// 判断队列是否为空
    /// @return 空返回true，否则返回false
    ///
    bool empty() const;

    ///
    /// 获取队列大小
    /// @return 返回大小
    ///
    int size() const;

    ///
    /// 队列清空
    ///
    void clear();

    /// 向队列push一个元素
    /// \param item 参数item
    void push(T &item);

    /// 从队列pop一个元素，为空则阻塞
    /// \return 返回Node节点
    T *wait_pop();

    /// 从队列pop一个元素，空则返回false
    /// \return 成功返回true，否则返回false
    bool try_pop();

    /// 获取队列头部元素
    /// \return 返回Node节点
    T *try_top();

    /// 获取队列头部元素，空则阻塞
    /// \return 返回Node节点
    T *wait_top();

};

#endif //FIRSTCPP_FDUQUEUE_H
