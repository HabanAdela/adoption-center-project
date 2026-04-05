#pragma once
#include "Dog.h"
#include <vector>

class Repository {
public:
	Repository();
	virtual void addElement(Dog dog) = 0;
	virtual std::vector<Dog> getAll() = 0;
	virtual size_t findId(Dog dog) = 0;
	virtual void deleteElement(size_t index) = 0;
	virtual void updateElement(size_t index, std::string new_breed, int new_age, std::string new_photo) = 0;
	virtual std::vector<Dog> FilterElements(std::string breed, int age) = 0;
};

class MemoryRepository : public Repository {
private:
	std::vector<Dog> dogs;
public:
    MemoryRepository();
	void addElement(Dog dog) override;
	std::vector<Dog> getAll() override;
	size_t findId(Dog dog) override;
	void deleteElement(size_t index) override;
	void updateElement(size_t index, std::string new_breed, int new_age, std::string new_photo) override;
	std::vector<Dog> FilterElements(std::string breed, int age) override;
    void InitMemoryRepo();
};
