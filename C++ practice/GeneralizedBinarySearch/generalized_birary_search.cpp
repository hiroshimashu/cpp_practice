//
//  generalized_birary_search.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/18.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "generalized_birary_search.hpp"
#include <iostream>
using namespace std;

bool P(int x) {
    return true;
    
};

int main() {
    int left, right;
    
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (P(mid)) right = mid;
        else left = mid;
    };
    return right;
}
