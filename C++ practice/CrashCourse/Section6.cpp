//
//  Section6.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/29.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Section6.hpp"
#include <utility>

template <typename T>
struct SimpleUnquePointer {
    SimpleUnquePointer() = default;
    SimpleUnquePointer(T* pointer) : pointer { pointer } {}
    ~SimpleUnquePointer() {
        if(pointer) delete pointer;
    }
    SimpleUnquePointer(const SimpleUnquePointer&) = delete;
    SimpleUnquePointer & operator=(const SimpleUnquePointer&) = delete;
    SimpleUnquePointer(SimpleUnquePointer&& other) noexcept : pointer { other.pointer } {
        other.pointer = nullptr;
    }
    SimpleUnquePointer& operator=(SimpleUnquePointer&& other) noexcept {
        if(pointer) delete pointer;
        pointer = other.pointer;
        other.pointer = nullptr;
        return *this;
    }
    T* get() {
        return pointer;
    }
    
        
    private:
        T* pointer;
    
};


struct Tracer {
    Tracer(const char* name) : name{ name } {
        printf("%s constructed\n", name);
    }
    ~Tracer() {
        printf("%s destructed.\n", name);
    }
private:
    const char* const name;
};

void consumer(SimpleUnquePointer<Tracer> consumer_ptr) {
    printf("cons");
}
