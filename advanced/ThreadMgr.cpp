//
// Created by Apple on 2019-05-04.
//
#include <iostream>
#include <pthread.h>
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>

#define NUM_THREADS 5
using namespace std;

typedef struct thread_data {
    int thread_id;
    char *message;
} thread_data;

void *say_hello(void *tid) {
    cout << "Hello, Runoob! id of thread is " << *((int *) tid) << endl;
    return 0;
}

void *print_hello(void *threadarg) {
    struct thread_data *mydata;
    mydata = (struct thread_data *) threadarg;
    cout << "Thread id: " << mydata->thread_id << endl;
    cout << "Message: " << mydata->message << endl;
}

int main() {
    /* Threads pass simple parameters      */
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        cout << "main() : create thread, " << i << endl;
        int ret = pthread_create(&tids[i], NULL, say_hello, (void *) &i);
        if (ret) {
            cout << "pthread_create error: error_code = " << ret << endl;
        }
    }

    /* Threads pass structure parameters     */
    struct thread_data td[NUM_THREADS];
    pthread_t ttids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        td[i].thread_id = i;
//        ostringstream ss;
//        ss << "this is message_" << i;
        td[i].message = (char *) ("this is message_" + to_string(i)).c_str();
        int ret = pthread_create(&ttids[i], NULL, print_hello, (void *) &td[i]);
        if (ret)
            cout << "pthread_create error: error code = " << ret << endl;
    }
    pthread_exit(NULL);
}