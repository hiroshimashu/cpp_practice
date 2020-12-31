//
//  Section3.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/11.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Section3.hpp"

int cal() {
    int frirst_pointer = {};
    printf("my first pointer: %d\n", frirst_pointer);
    int* pointer_to_value = &frirst_pointer;
    printf("pointer's address: %p\n", pointer_to_value);
    return frirst_pointer;
};

int key_to_universe[]{3, 4, 6};

int* ptr_to_iniverse = key_to_universe;

void petruchio(const char* shrew) {
    printf("Fear not, %s", shrew);
}

struct Avout {
    Avout(const char* name) : name { name } {
        
    }
    void announce() const {
        printf("My name is %s", name);
    }
    const char* name;
};

int main() {
    auto year{ 2020 };
    
    Avout raz{ "Erasms" };
    raz.announce();
}

struct Dwarf {
    
};

Dwarf dwarves[13];

struct Contract {
    void add(const Dwarf&);
};

void form_company(Contract &contract) {
    for(const auto& dwarf : dwarves) {
        contract.add(dwarf);
    }
}


