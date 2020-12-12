//
//  main.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/03/06.
//  Copyright © 2020年 Hiroshi Imamasu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int absolute_value(int x) {
    if (x < 0) return -x;
    return x;
}

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}


enum class Race {
    Dian,
    Ivan
};

enum class Opelation {
    add,
    substact,
    multiply,
    divide,
};

struct Calculator {
    Opelation opr;
    Calculator(Opelation operation) {
        opr = operation;
    }
    
    int Calculate(int a, int b) {
        switch (opr) {
            case Opelation::add:
                return a + b;
                break;
            case Opelation::substact:
                return a - b;
            case Opelation::multiply:
                return a * b;
            case  Opelation::divide:
                return a / b;
            default:
                printf("no matching operation");
                break;
        }
    }
};

struct ClockOfTime {
    int year;
    ClockOfTime(int year_in) {
        year = year_in;
    }
    public:
    void add_year(int a) {
        year += a;
    }
};


int main() {
    ClockOfTime ctime {
        2019
    };
    ClockOfTime* clock_ptr = &ctime;
    clock_ptr -> add_year(3);
    Race race = Race::Dian;
    switch (race) {
        case Race::Dian:
            printf("Dian");
            break;
            
        default:
            break;
    }
}

