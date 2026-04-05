#pragma once
#include "Dog.h"

class AdoptionRepository{
public:
	virtual void addElement(Dog dog) = 0;
	virtual std::vector<Dog> getAll() = 0;
	virtual std::string getType() = 0;

};
