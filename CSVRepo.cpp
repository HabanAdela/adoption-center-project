#include "CSVRepo.h"
#include <fstream>
#include "Exception.h"

void CSVRepo::addElement(Dog dog)
{
	this->dogs.push_back(dog);
	this->writeToFile();
}

std::vector<Dog> CSVRepo::getAll()
{
	return this->dogs;
}

void CSVRepo::writeToFile()
{
	std::ofstream fout(this->filePath);
	if (!fout.is_open())
		throw Exception("File not opened");

	for (int i = 0; i < this->dogs.size(); ++i)
	{
		fout << this->dogs[i] << "\n";
	}
	fout.close();
}

std::string CSVRepo::getType()
{
	return "csv";
}

