//
//  queue.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/29.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "queue.hpp"
#include <vector>
using namespace std;
const int MAX = 1000000;

int qu[MAX];
int tail = 0, head = 0;

void init() {
    head = tail = 0;
}

bool isEmpty() {
    return (head == tail);
}

bool isFull() {
    return (head == (tail + 1) % MAX);
}

void enqueue(int x) {
    if(isFull()) {
        cout << "error: queue is full." << endl;
        return;
    }
    qu[tail] = x;
    ++tail;
    if(tail == MAX) tail = 0;
}

int dequeue() {
    if(isEmpty()) {
        cout << "error: queue is empty" << endl;
        return -1;
    }
    int res = qu[head];
    ++head;
    if(head == MAX) head = 0;
    return res;
}
