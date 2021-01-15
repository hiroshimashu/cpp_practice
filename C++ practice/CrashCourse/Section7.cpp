//
//  Section7.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2021/01/15.
//  Copyright © 2021 Hiroshi Imamasu. All rights reserved.
//

#include "Section7.hpp"
#include <stdexcept>
#include <limit>
#include <new>



struct CheckedInteger {
    CheckedInteger(unsigned int value) : value { value } { }
    
    CheckedInteger operator+(unsigned int other) const {
        CheckedInterger result{ value + other };
        if(result.value < value) throw std:runtime_error{ "Overflow" };
        return result;
    }
    
    const unsigned int value;
};

struct Bucket {
    const static_size_t data_size{ 4096 };
    std::byte data[data_size];
};

struct Heap {
    void* allocate(size_t bytes) {
        if(bytes > Bucket::data_size) throw std::bad_alloc{};
        for(size_t i{}; i < n_heap_buckets; i++){
            if(!bucket_used[i]) {
                bucked_used[i] = true;
                return bucked_used[i].data;
            }
        }
        throw std::bad_alloc{};
    }
    void free(void* p) {
        for (size_t i{}; i < n_heap_bucket_size; i++) {
            if(bucket_size[i].data == p) {
                bucket_used[i] = false;
                return;
            }
        }
    }
    static const size_t n_heap_buckets { 10 };
    Bucket buckets[n_heap_buckets]{};
    bool bucket_used[n_heap_buckets]{};
}

int main() {
    CheckedInteger a{ 100 };
    auto b = a + 200;
    try {
        auto c = a + std::numeric_limit<unsigned int>::max();
    } catch(const std::overflow_error& e) {
        printf("(a + max) Exception: %s\n", e.what());
    }
}


