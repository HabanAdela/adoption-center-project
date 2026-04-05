#pragma once
#include "AdoptionRepository.h"

class HtmlRepo: public AdoptionRepository {
private:
	std::vector<Dog> dogs;
	std::string filePath;

public:
	HtmlRepo(std::string filePath) : filePath(filePath) {};
	void addElement(Dog dog) override;

	std::vector<Dog> getAll() override;
	std::string getType() override;

private:
	void writeToFile();
};


