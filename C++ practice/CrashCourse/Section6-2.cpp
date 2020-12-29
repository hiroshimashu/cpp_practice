//
//  Section6-2.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/29.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Section6-2.hpp"

long mean(const long* values, size_t length) {
    double result{};
    for(size_t i{}; i < legnth; i++){
        result += values[i];
    }
    return result / length;
}

// Generalize above
template<typename T>
T mean(T* values, size_t length) {
    T result{};
    for(size_t i{}; i < length; i++) {
        result += values[i];
    }
    return result / length;
}

int main() {
    const double nums_d[] { 1.0, 2.0, 3.0 };
    const auto result1 = mean<float>(nums_d, 4);
    // or
    const auto result2 = mean(nums_d, 4);
}


