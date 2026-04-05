#include "adoptiontable.h"

int AdoptionTable::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return dogs.size();
}

int AdoptionTable::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 4;
}

QVariant AdoptionTable::data(const QModelIndex& index, int role) const {
    if (role != Qt::DisplayRole || !index.isValid()) return QVariant();

    const Dog& dog = dogs.at(index.row());
    switch (index.column()) {
    case 0: return QString::fromStdString(dog.getName());
    case 1: return QString::fromStdString(dog.getBreed());
    case 2: return dog.getAge();
    case 3: return QString::fromStdString(dog.getPhoto());
    default: return QVariant();
    }
}

