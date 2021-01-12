//
//  Section4-2.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2021/01/03.
//  Copyright © 2021 Hiroshi Imamasu. All rights reserved.
//

#include "Section4-2.hpp"
#include <ctime>


struct TimeClass {
    TimeClass() : timestamp{ std::time(0) } {
        
    }
    ~TimeClass() {
        timestamp = std::time(0) - timestamp;
        printf("%ld", timestamp);
    }
    
private:
    std::time_t timestamp;
};
