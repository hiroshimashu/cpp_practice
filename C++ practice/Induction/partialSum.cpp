//
//  partial_sum.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/12.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "partial_sum.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int> &a) {
    if(i == 0) {
        if(w == 0) return true;
        else return false;
    }
    
    if(func(i-1, w, a)) return true;
    
    if(func(i-1, w - a[i - 1], a)) return true;
    
    return false;
}
