#pragma once
#include "Repository.h"
#include "AdoptionRepository.h"
#include "UndoRedo.h"
#include <memory>
#include <stack>

class Service{
private:
	Repository& repo;
	AdoptionRepository& adoptionRepo;
    std::stack<std::unique_ptr<undoredo>> UndoSTack;
    std::stack<std::unique_ptr<undoredo>> RedoSTack;
public:
	Service(Repository& repo, AdoptionRepository& adoptionRepo) : repo(repo), adoptionRepo(adoptionRepo) {}
    Service(const Service&) = delete;
    Service& operator=(const Service&) = delete;
	void addDog(Dog dog);
	std::vector<Dog> getAll();
	std::vector<Dog> getAllAdopted();
    void deleteDog(Dog dog);
    void updateDog(Dog dog, Dog newDog);
	std::vector<Dog> FilterByBreed(std::string breed, int age);
	void adoptDog(Dog dog);
	std::string getFileType();
    void undo();
    void redo();
};
