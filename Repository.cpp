#include "Repository.h"
#include <algorithm>
Repository::Repository() {}

MemoryRepository::MemoryRepository() {
    InitMemoryRepo();
}

void MemoryRepository::addElement(Dog dog) {
/*The function recieves a Dog object adds it at the back of the std::vector*/
	this->dogs.push_back(dog);
}

size_t MemoryRepository::findId(Dog dog) {
/*The function recieves a Dog object and searches for it in the std::vector.
If the object is alreafy in the system we return the index, if not it returns -1*/
/*	for (size_t d = 0; d < this->dogs.size(); ++d)
		if (this->dogs[d].getName() == dog.getName())
			return d;
	return -1;*/
	auto it = std::find_if(dogs.begin(), dogs.end(),
		[&dog](Dog& d) { return d.getName() == dog.getName(); });

	return it != dogs.end() ? std::distance(dogs.begin(), it) : -1;

}

void MemoryRepository::updateElement(size_t index, std::string new_breed, int new_age, std::string new_photo) {
/*The function recieves a name by which we identiry the Dog object, a breed, an age and a photo link
If the breed, age or photo link are not empty those fields are modified*/
	if (new_breed != "")
		this->dogs[index].setBreed(new_breed);
	if (new_age != -1)
		this->dogs[index].setAge(new_age);
	if (new_photo != "")
		this->dogs[index].setPhoto(new_photo);
}

void MemoryRepository::deleteElement(size_t index) {
/*The function recieves a name and deletes the Dog object that has that name*/
	this->dogs.erase(dogs.begin() + index);
}

std::vector<Dog> MemoryRepository::getAll() {
/*The function returns the std::vector containing all the Dog objects*/
	return dogs;
}

std::vector<Dog> MemoryRepository::FilterElements(std::string breed, int age) {
/*The function recieves a string representing the breed and returns a std::vector containing all the Dog objects
that have that breed*/
	std::vector<Dog> filtered_vector;
	//for (size_t d = 0; d < this->dogs.size(); ++d)
		//if ((breed == "" || (this->dogs[d].getBreed().find(breed) != std::string::npos)) && 
			//this->dogs[d].getAge() < age)
			//filtered_vector.push_back(this->dogs[d]);
	
	std::copy_if(dogs.begin(), dogs.end(), std::back_inserter(filtered_vector),
		[&](Dog& d) {
			return (breed.empty() || d.getBreed().find(breed) != std::string::npos) &&
				d.getAge() < age;
		});

	return filtered_vector;
}

void MemoryRepository::InitMemoryRepo() {
    Dog d1{ "bichon havanez", "Zara", 15, "https://totuldesprebichoni.ro/wp-content/uploads/2022/08/probleme-sanatate-bichon-havanez.jpg" };
    Dog d2{ "german shepherd", "Roua", 0, "https://pet-health-content-media.chewy.com/wp-content/uploads/2024/09/11180014/202105German-Shepherd-1358309706-scaled-1.jpg" };
    Dog d3{ "beagle", "Tara", 3, "https://www.zooplus.ro/ghid/wp-content/uploads/2021/07/beagle-pui.webp" };
    Dog d4{ "labrador", "Faith", 5, "https://www.toateanimalele.ro/wp-content/uploads/2025/02/angel-luciano-latyezyw88c-unsplash-1170x570.jpg" };
    Dog d5{ "labrador", "Pickle", 2, "https://petzpark.com.au/cdn/shop/articles/Untitled_design_8_-min_800x.jpg?v=1638424495" };
    Dog d6{ "labrador", "Luna", 5, "https://media.hornbach.ro/cmsm/ro/chke2-e0/7d2dde17b48d05d01ac1ad37a0cb27/labrador-retriever-2-992x661.jpg" };
    Dog d7{ "golden retriever", "Amon", 3, "https://cdn.pixabay.com/photo/2019/04/17/20/18/golden-retriever-4135265_1280.jpg" };
    Dog d8{ "puddle", "Star", 5, "https://image.stirileprotv.ro/media/images/800x450/Mar2023/62333513.jpg" };
    Dog d9{ "pitbull", "Akira", 5, "https://cdn.shopify.com/s/files/1/1638/5471/files/Sparkpaws_Are_Pitbulls_Dangerous-01_480x480.jpg?v=1707202784" };
    Dog d10{ "cane corso", "Kara", 5, "https://fera.ro/images/companies/1/dog-428022_1920.jpg?1594894790215" };
    this->addElement(d1);
    this->addElement(d2);
    this->addElement(d3);
    this->addElement(d4);
    this->addElement(d5);
    this->addElement(d6);
    this->addElement(d7);
    this->addElement(d8);
    this->addElement(d9);
    this->addElement(d10);
}
