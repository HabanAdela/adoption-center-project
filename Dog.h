#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Utils.h"

class Dog{
public:
	Dog() : breed{ "" }, name{ "" }, age{0}, photo{ "" }
	/*The constructor of the function*/
	{}
	Dog(std::string breed, std::string name, int age, std::string photo) :
		breed(breed), name(name), age(age), photo(photo)
	/*The constructor of the function that recieved a breed, a name, an age and a photo link*/
	{}
	Dog(std::string name) :
	/*The constructor of the function that recieves only the name*/
		breed{ "" }, name(name), age{ 0 }, photo{ "" }
	{}

	void setBreed(std::string breed) { this->breed = breed; }
	/*This sets the breed filed*/
	void setPhoto(std::string photo) { this->photo = photo; }
	/*This sets the photo filed*/
	void setAge(int age) { this->age = age; }
	/*This sets the age filed*/

    std::string getBreed() const{
	/*Returns the breed*/
		return this->breed;
	}
    std::string getName() const{
	/*Returns the Name*/
		return this->name;
	}
    std::string getPhoto() const{
	/*Returns the photo*/
		return this->photo;
	}
    int getAge() const{
	/*Returns the age*/
		return this->age;
	}

    std::string toString(){
        return breed + "," + name + "," + std::to_string(age) + "," + photo;
    }

	friend std::ostream& operator << (std::ostream& os, const Dog& dog)
	{
		os << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photo;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, Dog& dog)
	{
		std::string dogString;
		getline(is, dogString);
		std::vector<std::string> result = tokenize(dogString, ',');

		if (result.size() != 4)
			return is;
		
		Dog d{ result[0], result[1], stoi(result[2]), result[3]};
		dog = d;
		return is;
	}

    bool operator ==(const Dog& d2) {
        return this->getName() == d2.getName();
    }

private:
	std::string breed;
	std::string name;
	int age;
	std::string photo;
};
