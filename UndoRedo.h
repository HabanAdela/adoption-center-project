#ifndef UNDOREDO_H
#define UNDOREDO_H

#include "Repository.h"

class undoredo {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class commandAdd : public undoredo {
private:
    Repository& repo;
    Dog dog;

public:
    commandAdd(Repository& r, Dog d): repo(r), dog(d) {}

    void execute() override {
        repo.addElement(dog);
    }

    void undo() override {
        size_t index = this->repo.findId(dog);
        if (index == -1)
            return;
        this->repo.deleteElement(index);
    }
};

class commandDelete : public undoredo {
private:
    Repository& repo;
    Dog dog;

public:
    commandDelete(Repository& r, Dog d) : repo(r), dog(d) {}

    void execute() override {
        size_t index = this->repo.findId(dog);
        if (index == -1)
            return;
        this->repo.deleteElement(index);
    }

    void undo() override {
        repo.addElement(dog);
    }
};

class commandUpdate : public undoredo {
private:
    Repository& repo;
    Dog dog;
    Dog newDog;

public:
    commandUpdate(Repository& r, Dog d, Dog newDog) : repo(r), dog(d), newDog(newDog) {}

    void execute() override {
        size_t index = this->repo.findId(dog);
        if (index == -1)
            return;
        repo.updateElement(index, newDog.getBreed(), newDog.getAge(), newDog.getPhoto());
    }

    void undo() override {
        size_t index = this->repo.findId(newDog);
        if (index == -1)
            return;
        repo.updateElement(index, dog.getBreed(), dog.getAge(), dog.getPhoto());
    }
};


#endif // UNDOREDO_H
