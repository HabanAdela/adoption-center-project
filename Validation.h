#pragma once
#include "Dog.h"
#include <vector>
#include <string>

class Validation {
public:
    static size_t validate(Dog dog, std::vector<Dog> dogs) {
        auto it = std::find_if(dogs.begin(), dogs.end(),
            [&dog](Dog& d) { return d.getName() == dog.getName(); });

        return it != dogs.end() ? std::distance(dogs.begin(), it) : -1;
    }
};