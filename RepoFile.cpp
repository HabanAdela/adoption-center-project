#include "RepoFile.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "Exception.h"


FileRepository::FileRepository(std::string filePath) : filePath(filePath)
{
	readFromFile();
}

void FileRepository::addElement(Dog d) {
	this->dogs.push_back(d);
	this->writeToFile();
}

std::vector<Dog> FileRepository::getAll() {
	return this->dogs;
}

void FileRepository::readFromFile() {
	std::ifstream fin(this->filePath);
	if (fin.is_open() == false)
		throw Exception("File not open!");
	Dog d;
	while (fin >> d)
	{
		this->dogs.push_back(d);
	}
	fin.close();
}

void FileRepository::writeToFile() {
	std::ofstream fout(this->filePath);
	if (fout.is_open() == false)
		throw Exception("File not open!");
	for (int i = 0; i < this->dogs.size(); i++)
	{
		fout << this->dogs[i] << '\n';
	}
}

size_t FileRepository::findId(Dog dog) {
	auto it = std::find_if(dogs.begin(), dogs.end(),
		[&dog](Dog& d) { return d.getName() == dog.getName(); });

	return it != dogs.end() ? std::distance(dogs.begin(), it) : -1;
}

void FileRepository::updateElement(size_t index, std::string new_breed, int new_age, std::string new_photo) {

	if (new_breed != "")
		this->dogs[index].setBreed(new_breed);
	if (new_age != -1)
		this->dogs[index].setAge(new_age);
	if (new_photo != "")
		this->dogs[index].setPhoto(new_photo);
	this->writeToFile();
}

void FileRepository::deleteElement(size_t index) {
	this->dogs.erase(dogs.begin() + index);
	this->writeToFile();
}

std::vector<Dog> FileRepository::FilterElements(std::string breed, int age) {
	std::vector<Dog> filtered_vector;

	std::copy_if(dogs.begin(), dogs.end(), std::back_inserter(filtered_vector),
		[&](Dog& d) {
			return (breed.empty() || d.getBreed().find(breed) != std::string::npos) &&
				d.getAge() < age;
		});

	return filtered_vector;
}

//void FileRepository::adoptDog(Dog dog, size_t index) {
//	this->adopted_dogs.push_back(dog);
//	this->dogs.erase(dogs.begin() + index);
//
//	this->writeToFile();
//}