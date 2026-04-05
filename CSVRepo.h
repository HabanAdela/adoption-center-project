#pragma once
#include "AdoptionRepository.h"

class CSVRepo : public AdoptionRepository {
private:
	std::vector<Dog> dogs;
	std::string filePath;
public:
	CSVRepo(std::string filePath) : filePath(filePath) {}
	void addElement(Dog dog) override;
	std::vector<Dog> getAll() override;
	std::string getType();
	
private:
	void writeToFile();

};