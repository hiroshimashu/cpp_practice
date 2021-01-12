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

template<typename T>
T square(T value) {
    return value * value;
}

template<typename T>
T mean(T* values, size_t length) {
    static_assert(std::is_default_constructible<T>(), "Type must be default constructible.");
    static_assert(std::is_copy_constructible<T>(), "Type must be copy constructible");
    static_assert(std::is_arithmetic<T>(), "Type must support addition and division");
    static_assert(std::is_constructible<T, size_t>(), "Type must be cohnstructible from size_t");
    T result{};
    for (size_t i{}; i < length; i++) {
        result += values[i];
    }
    
    return result / length;
}

template<typename T, typename... Arguments>
SimpleUnquePointer<T> make_simple_unique(Arguments... arguments) {
    return SimpleUnquePointer<T>{ new T{ arguments... }};
}




