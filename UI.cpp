#include "UI.h"
#include <iostream>
#include <cassert>
#include "Exception.h"
using namespace std;

void UI::openPhoto(Dog dog) const {
	std::string url = dog.getPhoto();
	ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void UI::printMenu() {
	cout << "0 - Exit" << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
}

void UI::printAdministratorMenu() {
	cout << "0 - Exit" << endl;
	cout << "1 - Add" << endl;
	cout << "2 - Delete" << endl;
	cout << "3 - Update" << endl;
	cout << "4 - Print all" << endl;
}

void UI::startAdministrator() {
	while (true) {
		string str;
		int command = 0x3f3f3f3f;
		this->printAdministratorMenu();
		cout << "Enter command: ";
		getline(cin, str);

		try {
			command = stoi(str);
		}
		catch (invalid_argument) {
			cout << "The command is not valid\n";
			continue;
		}

		switch (command) {
		case 0:
			return;
		case 1:
			this->addDog();
			break;
		case 2:
			this->deleteDog();
			break;
		case 3:
			this->updateDog();
			break;
		case 4:
			this->printAll();
			break;
		default:
			cout << "The command is not valid\n";
		}
	}
}

void UI::printUserMenu() {
	cout << "0 - Exit" << endl;
	cout << "1 - See all dogs" << endl;
	cout << "2 - Filter by breed and age" << endl;
	cout << "3 - See adoption list" << endl;
	cout << "4 - Print all" << endl;
	cout << "5 - See all adopted dogs" << endl;
}

void UI::startUser() {
	
	while (true) {
		string str;
		int command = 0x3f3f3f3f;
		this->printUserMenu();
		cout << "Enter command: ";
		getline(cin, str);
		try {
			command = stoi(str);
		}
		catch (invalid_argument) {
			cout << "The command is not valid\n";
			continue;
		}

		switch (command) {
		case 0:
			return;
		case 1:
			this->DisplayDogs();
			break;
		case 2:
			this->FilterByBreed();
			break;
		case 3:
			this->printVector(this->service.getAllAdopted());
			break;
		case 4:
			this->printAll();
			break;
		case 5:
			this->openAdoptedList();
			break;
		default:
			cout << "The command is not valid\n";
		}
	}
}

void UI::openAdoptedList() {
	std::string fileType = this->service.getFileType();
	std::string path;
	if (fileType == "csv")
	{
		path = "Adopted.csv";
		std::string com = "start notepad.exe " + path;
		system(com.c_str());
	}
	else
	{
		path = "adopted.html";
		std::string com = "start " + path;
		system(com.c_str());
	}
}

void UI::addToList()
{
	for (int i = 0; i < this->service.getAllAdopted().size(); ++i) {
		this->service.adoptDog(this->service.getAllAdopted()[i]);
	}
}

void UI::start() {

	string str;
	int command = 0x3f3f3f3f;
	while (true) {
		printMenu();
		cout << "Enter command: ";
		getline(cin, str);

		try {
			command = stoi(str);
		}
		catch (invalid_argument) {
			cout << "The command is not valid\n";
			start();
		}

		switch (command) {
		case 0:
			exit(0);
		case 1:
			startAdministrator();
			break;
		case 2:
			startUser();
			break;
		}
	}
}

void UI::printAll() {
	std::vector<Dog> dogs = this->service.getAll();
	if (dogs.size() == 0) {
		cout << "There are no dogs in the list\n";
		return;
	}
	for (auto dog : dogs) {
		cout << "Breed : " << dog.getBreed() << ", "
			<< "Name : " <<  dog.getName() << ", "
			<< "Age : " << dog.getAge() << ", "
			<< "Photo link : " << dog.getPhoto() << '\n';
	}
}
//void UI::testFilter()
//{
//	MemoryRepository repo{};
//	Service service{ repo };
//	Dog d1{ "german shepherd", "Roua", 0, "idk2" };
//	Dog d2{ "beagle", "Tara", 3, "idk3" };
//	Dog d3{ "labrador", "Faith", 5, "idk4" };
//	Dog d4{ "labrador", "Pickle", 2, "idk4" };
//	repo.addElement(d1);
//	repo.addElement(d2);
//	repo.addElement(d3);
//	repo.addElement(d4);
//	assert(service.FilterByBreed("labrador", 100).size() == 2);
//}

void UI::printVector(std::vector<Dog> dogs) {
	if (dogs.size() == 0) {
		cout << "There are no dogs in the list\n";
		return;
	}
	for (auto dog : dogs) {
		cout << "Breed : " << dog.getBreed() << ", "
			<< "Name : " << dog.getName() << ", "
			<< "Age : " << dog.getAge() << ", "
			<< "Photo link : " << dog.getPhoto() << '\n';
	}
}

void UI::FilterByBreed() {
	string breed, age_str;
	int age;
	try {
		cout << "Enter the breed: ";
		getline(cin, breed);

		cout << "Enter the maximum age: ";
		getline(cin, age_str);
		age = stoi(age_str);
		
	}
	catch (...) {
		cout << "error" << '\n';
		return;
	}
	std::vector<Dog> dogs = this->service.FilterByBreed(breed, age);
	vector<Dog> remaining;
	int i = 0;
	string command;
	
	while (true) {
		if (dogs.size() == 0)
			break;
		remaining.clear();
		for (auto dog : dogs) {
			cout << "Breed : " << dog.getBreed() << ", "
				<< "Name : " << dog.getName() << ", "
				<< "Age : " << dog.getAge() << ", "
				<< "Photo link : " << dog.getPhoto() << '\n';
			openPhoto(dog);

			cout << "Do you want to adopt this dog? (Y/n) ";
			getline(cin, command);
			try {
				if (command.empty() || (command != "Y" && command != "y" && command != "N" && command != "n"))
					throw Exception("Invalid command");
			}
			catch (Exception e) {
				cout << e.getMessage() << '\n';
			}

			if (command == "Y" || command == "y") {
				this->service.adoptDog(dog);
			}
			else {
				remaining.push_back(dog);
			} 

			cout << "Do you want to go to the next dog? (Y/n) ";
			getline(cin, command);
			try {
				if (command.empty() || (command != "Y" && command != "y" && command != "N" && command != "n"))
					throw Exception("Invalid command");
			}
			catch (Exception e) {
				cout << e.getMessage() << '\n';
			}

			if (command == "Y" || command == "y")
				continue;
				

			if (command == "N" || command == "n")
				return;
		}

		if (!remaining.empty())
			dogs = remaining;
		else
			break;
	}
	cout << "The are no more dogs in the shelter\n";
}

void UI::DisplayDogs() {
	int i = 0;
	string command;
	vector<Dog> dogs = this->service.getAll();
	vector<Dog> remaining;

	while (true) {
		for (auto dog : dogs) {

			cout << "Breed : " << dog.getBreed() << ", "
				<< "Name : " << dog.getName() << ", "
				<< "Age : " << dog.getAge() << ", "
				<< "Photo link : " << dog.getPhoto() << '\n';
			openPhoto(dog);

			cout << "Do you want to adopt this dog? (Y/n) ";
			getline(cin, command);
			try {
				if (command.empty() || (command != "Y" && command != "y" && command != "N" && command != "n"))
					throw Exception("Invalid command");
			}
			catch (Exception e) {
				cout << e.getMessage() << '\n';
			}

			if (command == "Y" || command == "y") {
				this->service.adoptDog(dog);
			}
			else remaining.push_back(dog);

			cout << "Do you want to go to the next dog? (Y/n) ";
			getline(cin, command);
			try {
				if (command.empty() || (command != "Y" && command != "y" && command != "N" && command != "n"))
					throw Exception("Invalid command");
			}
			catch (Exception e) {
				cout << e.getMessage() << '\n';
			}

			if (command == "Y" || command == "y")
				continue;

			if (command == "N" || command == "n")
				return;
		}
		if (!remaining.empty())
			dogs = remaining;
		else break;
	}

	cout << "The are no more dogs in the shelter\n";
}

void UI::updateDog() {
	string new_breed, name, new_photo, new_age_str;
	int new_age = -1;
	try {
		cout << "Enter the name of the dog you want to modify : ";
		getline(cin, name);
		if (name.empty()) {
			throw Exception("Name cannot be empty");
		}

		cout << "Enter the new breed: ";
		getline(cin, new_breed);

		cout << "Enter the age: ";
		getline(cin, new_age_str);
		if (!new_age_str.empty())
			new_age = stoi(new_age_str);
		else
			new_age = -1;

		cout << "Enter the photo link: ";
		getline(cin, new_photo);
	}
	catch (...) {
		cout << "Invalid input" << '\n';
	}
	try{
        //this->service.updateDog(name, new_breed, new_age, new_photo);
	}
	catch (...) {
		cout << "The dog was not found\n";
	}
	
}

void UI::deleteDog() {
	string name;
	try {
		cout << "Enter the name: ";
		getline(cin, name);
		if (name.empty()) {
			throw Exception("Name cannot be empty");
		}

        //this->service.deleteDog(name);
	}
	catch (...) {
		cout << "The dog was not found" << '\n';
	}
}

void UI::addDog() {
	string breed, name, photo, age_str;
	int age;
	try {
		cout << "Enter the breed: ";
		getline(cin, breed);
		if (breed.empty()) {
			throw Exception("Breed cannot be empty");
		}

		cout << "Enter the name: ";
		getline(cin, name);
		if (name.empty()) {
			throw Exception("Name cannot be empty");
		}

		cout << "Enter the age: ";
		getline(cin, age_str);
		age = stoi(age_str);
		if (age < 0)
			throw Exception("The age cannot be a negativ integer");

		cout << "Enter the photo link: ";
		getline(cin, photo);
		if (name.empty()) {
			throw Exception("Photo link cannot be empty");
		}

		Dog dog = Dog(breed, name, age, photo);
		this->service.addDog(dog);
	}

	catch(Exception e){
		cout << e.getMessage() << '\n';
	}
}
