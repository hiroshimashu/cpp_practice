//
//  stack.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/29.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "stack.hpp"
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int st[MAX];
int top = 0;

void init() {
    top = 0;
}

bool isEmpty() {
    return (top == 0);
}

bool isFull() {
    return (top == MAX);
}

void push(int x) {
    if(isFull()) {
        cout << "error stack is full." << endl;
        return;
    }
    st[top] = x;
    ++top;
}

int pop() {
    if (isEmpty()) {
        cout << "error stack is empyt." << endl;
        return -1;
    }
    --top;
    return st[top];
}

int main() {
    init();
    push(3);
    
    //etc
}


