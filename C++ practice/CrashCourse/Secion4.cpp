//
//  Secion4.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/13.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Secion4.hpp"
#include <stdexcept>
#include <cstring>

int* my_int_ptr = new int{ 42 };

void power_up_rat_thing(int nuclear_isotopes) {
    static thread_local int rat_things_power = 200;
    rat_things_power = rat_things_power + nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if(waste_heat > 10000) {
        printf("Warning! Hot doggie!\n");
    }
}

struct RatThing {
    static int rat_things_power;
    static void power_up_rat_thing(int nuclear_isotopes) {
        rat_things_power = rat_things_power + nuclear_isotopes;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 100000) {
            printf("Warning! Hot doggie!\n");
        }
    }
};

int RatThing::rat_things_power = 100;

struct Tracer {
    const char* name;
    Tracer(const char* name) : name { name } {
        printf("%s constructed \n", name);
    }
    
    ~Tracer() {
        printf("%s destructed", name);
    }
};

static Tracer t1 { "Static variable" };

struct some_throw {
    void forget(int x) {
        if (x == 0xFACE) {
            throw std::runtime_error {"I'd be glad to make an exception."};
        }
        printf("Forgot ox\n");
    }
};



struct SimpleString {
    SimpleString(size_t max_size) : max_size{ max_size }, length{} {
        if(max_size == 0) {
            throw std::runtime_error{ "MAX size must be at least 1" };
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }
    
    
    SimpleString(const SimpleString& other)
        : max_size { other.max_size },
          buffer { new char[other.max_size] },
          length { other.length } {
              std::strncpy(buffer, other.buffer, max_size);
    }
    
    SimpleString(SimpleString&& other) noexcept :
        max_size{ other.size },
    buffer{ other.buffer },
    length { other.length } {
        othehhhr.size = 0;
        other.buffer = nullptr;
        other.max_size = 0;
    }
    
    ~SimpleString() {
        delete[] buffer;
    }
    
    SimpleString& operator=(const SimpleString& other) {
        if(this == &other) return *this;
        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        strcpy_s(buffer, max_size, other.buffer);
        
    }
    
    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }
    
    bool append_line(const char* x) {
        const auto x_len = strlen(x);
        if(x_len + length + 2 > max_size) return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
private:
    size_t max_size;
    char* buffer;
    size_t length;
};

struct Groucho {
    void forget(int x) {
        if (x == 0xFACE) {
            throw std::runtime_error{ "I'd be glad to make an exception" };
        }
        
        printf("Forgot ");
    }
};

bool is_odd(int x) noexcept {
    return 1 == (x % 2);
}

void ref_type(int &x) {
    printf("lvalue: %d", x);
}

void ref_tyep(int &&x) {
    printf("rvalue* %d", x);
}





int main() {
    Groucho groucho;
    try {
        groucho.forget(0xC0DE);
    } catch (const std::runtime_error& e) {
        printf("exception caught with message: %s\n", e.what());
    }
    
    delete my_int_ptr;
    
    auto x = 1;
    ref_tyep(std::move(x));
}
