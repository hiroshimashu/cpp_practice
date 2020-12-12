//
//  memorized_induction.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/08.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "memorized_induction.hpp"
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
const long long INF = 1LL << 60;

int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i) {
    if (dp[i] < INF) return dp[i];
    
    if (i == 0) return 0;
    
    long long res = INF;
    
    chmin(res, rec(i-1) + abs(h[i] - h[i-1]));
    
    if (i > 1) chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    
    return dp[i] = res;
}


