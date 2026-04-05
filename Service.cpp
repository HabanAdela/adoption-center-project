#include "Service.h"
#include <iostream>
#include <stdexcept>
#include "Exception.h"

void Service::addDog(Dog dog) {
    /*if (this->repo.findId(dog) != -1)
			throw Exception("The dog is already in the system");
	
    this->repo.addElement(dog);*/
    auto cmd = std::make_unique<commandAdd>(repo, dog);
    cmd->execute();
    UndoSTack.push(std::move(cmd));
    while(!RedoSTack.empty())
        RedoSTack.pop();
}

void Service::adoptDog(Dog dog) {
	size_t index = this->repo.findId(dog);
	if (index == -1)
		throw Exception("The dog is not found");

	this->adoptionRepo.addElement(dog);
	this->deleteDog(dog.getName());
}


std::vector<Dog> Service::getAllAdopted() {
	return this->adoptionRepo.getAll();
}

std::vector<Dog> Service::getAll() {
/*The function returns the vector containing all the Dog objects*/
	return this->repo.getAll();
}

void Service::deleteDog(Dog dog) {
/*The function recieves a name and deletes the Dog object that has that name*/
    /*Dog dog = Dog(name);
	size_t index = this->repo.findId(dog);
	if (index == -1)
		throw Exception("The dog is not in the system");
    // this->repo.deleteElement(index);*/
    auto cmd = std::make_unique<commandDelete>(repo, dog);
    cmd->execute();
    UndoSTack.push(std::move(cmd));
    while (!RedoSTack.empty())
        RedoSTack.pop();
}

std::string Service::getFileType() {
	return this->adoptionRepo.getType();
}

void Service::updateDog(Dog dog, Dog newDog) {
/*The function recieves a name by which we identiry the Dog object, a breed, an age and a photo link
If the breed, age or photo link are not empty those fields are modified*/
    auto cmd = std::make_unique<commandUpdate>(repo, dog, newDog);
    cmd->execute();
    UndoSTack.push(std::move(cmd));
    while (!RedoSTack.empty())
        RedoSTack.pop();
}

std::vector<Dog> Service::FilterByBreed(std::string breed, int age) {
/*The function recieves a string representing the breed and returns a vector containing all the Dog objects
that have that breed*/
	return this->repo.FilterElements(breed, age);
}

void Service::undo()
{
    if (UndoSTack.empty())
        throw Exception("No more undos");
    auto cmd = std::move(UndoSTack.top());
    UndoSTack.pop();
    cmd->undo();
    RedoSTack.push(std::move(cmd));
}

void Service::redo()
{
    if (RedoSTack.empty())
        throw Exception("No more redos");
    auto cmd = std::move(RedoSTack.top());
    RedoSTack.pop();
    cmd->execute();
    UndoSTack.push(std::move(cmd));
}
