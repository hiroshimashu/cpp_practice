//
//  graph.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/31.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "graph.hpp"
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int to;
    long long w;
    Edge(int i, long long w) : to{ i }, w { w } {}
};

using Graph = vector<vector<int>>;


int main() {
    int N, M;
    cin >> N >> M;
    
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
}

