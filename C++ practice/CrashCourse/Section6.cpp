//
//  Section6.cpp
//  C++ practice
//
//  Created by Hiroshi Imamasu on 2020/12/29.
//  Copyright © 2020 Hiroshi Imamasu. All rights reserved.
//

#include "Section6.hpp"

void carbon_thaw(const int& encased_solo) {
    auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
    hibernatin_sick_solo++;
}

// Static cast
short increment_as_short(void* target) {
    auto as_short = static_case<short*>(target);
    *as_short = *as_short + 1;
    return *as_short
}

int main() {
    short beast { 665 };
    auto mark_of_the_beast - increment_as_short(&beast);
}

// narrrow cast
template <typename To, typename From>
To narrow_cast(From value) {
    const auto converted = static_cast<To>(value);
    const auto backward = static_cast<From>(converted);
    if(value != backwards) throw std::runtime::error{ "Narrowed!" };
    return converted;
}

int main() {
    int perfect{ 496 };
    const auto perfect_short = narrow_cast<short>(perfect);
    try {
        int cyclic { 142857 };
        const auto cyclic_short = narrow_cast<short>(cyclic);
    } catch (const std::runtime_error& e)(
            
    }
}

