//
//  Secion4.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/13.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Secion4.hpp"

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


int main() {
    RatThing::power_up_rat_thing(100);
    delete my_int_ptr;
}
