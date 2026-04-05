#include "HtmlRepo.h"
#include <fstream> 
#include "Exception.h"

void HtmlRepo::addElement(Dog dog)
{
	this->dogs.push_back(dog);
	this->writeToFile();
}

std::vector<Dog> HtmlRepo::getAll()
{
	return this->dogs;
}

void HtmlRepo::writeToFile()
{
	std::ofstream fout(filePath);
	if (fout.is_open() == false)
		throw Exception("Repo not open!");

	fout << "<!DOCTYPE html>\n";
	fout << "<html>\n<head>\n<title>Your adopted dogs</title>\n</head>\n<body>\n<table border = \"1\">\n";
	fout << "	<tr>\n";
	fout << "		<td>Breed</td>\n";
	fout << "		<td>Name</td>\n";
	fout << "		<td>Age</td>\n";
	fout << "		<td>Photo link</td>\n";
	fout << "	</tr>\n";


	for (auto a : dogs)
	{
		fout << "	<tr>\n";
		fout << "		<td>" << a.getBreed() << "</td>\n";
		fout << "		<td>" << a.getName() << "</td>\n";
		fout << "		<td>" << a.getAge() << "</td>\n";
		fout << "		<td>" << a.getPhoto() << "</td>\n";
		fout << "	</tr>\n";
	}

	fout << "</table>\n</body>\n</html>";

	fout.close();
}

std::string HtmlRepo::getType()
{
	return "html";
}

