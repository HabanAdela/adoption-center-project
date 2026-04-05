#pragma once
#include "Repository.h"

class FileRepository : public Repository {
private:
	std::vector<Dog> dogs;
	std::string filePath;
public:
	FileRepository(std::string filePath);
	void addElement(Dog dog) override;
	std::vector<Dog> getAll() override;
	size_t findId(Dog dog) override;
	void deleteElement(size_t index) override;
	void updateElement(size_t index, std::string new_breed, int new_age, std::string new_photo) override;
	std::vector<Dog> FilterElements(std::string breed, int age) override;

private:
	void writeToFile();
	void readFromFile();
}; 