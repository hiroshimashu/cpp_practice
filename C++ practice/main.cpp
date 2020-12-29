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


struct Collage {
    char name[256];
};

void print_name(Collage* collages, size_t n_collages) {
    for (size_t i = 0; i < n_collages; i++) {
        printf("%s Collage\n", collages[i].name);
    }
}

int main() {
    Collage oxford[] = { "Mandalen", "Nuffield", "Kellogg" };
    print_name(oxford, sizeof(oxford) / sizeof(Collage));
}

