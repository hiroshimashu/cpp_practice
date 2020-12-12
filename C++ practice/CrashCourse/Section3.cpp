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

