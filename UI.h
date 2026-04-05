#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	void printMenu();
	void addDog();
	void deleteDog();
	void updateDog();
	void printAll();
	void DisplayDogs();
	void FilterByBreed();
	void printAdministratorMenu();
	void openPhoto(Dog dog) const;
	void printUserMenu();
	
public:
	void startAdministrator();
	void printVector(std::vector<Dog> dogs);
	void startUser();
	void start();
	void openAdoptedList();
	void addToList();
	//void testFilter();
    //UI(const Service& service) : service(service) {}
};
