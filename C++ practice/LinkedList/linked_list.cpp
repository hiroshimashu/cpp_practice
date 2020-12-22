//
//  linked_list.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/22.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "linked_list.hpp"
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *next, *prev;
    string name;
    Node(string name_ = "") : next{NULL}, name{name_}, prev{NULL} { }
};

Node* nil;

void init() {
    nil = new Node();
    nil -> prev = nil ;
    nil -> next = nil;
}

void printList() {
    Node* cur = nil -> next;
    for(; cur != nil; cur = cur -> next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil) {
    v ->next = p -> next;
    p ->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase(Node *v) {
    if (v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main() {
    init();
    
    vector<string> names = {
        "yamamoto",
        "ito",
        "takenaka"
    };
    
    for (int i = 0; i < (int) names.size(); i++) {
        Node* node = new Node(names[i]);
        
        insert(node);
        
        cout << "step " << i << ": ";
        printList();
    }
}
