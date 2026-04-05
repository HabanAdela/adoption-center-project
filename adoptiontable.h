#ifndef ADOPTIONTABLE_H
#define ADOPTIONTABLE_H

#include <QTableView>
#include <QAbstractTableModel>
#include "Dog.h"

class AdoptionTable : public QAbstractTableModel {
    Q_OBJECT

private:
    std::vector<Dog> dogs;

public:
    AdoptionTable(QObject* parent, std::vector<Dog> dogs): QAbstractTableModel(parent), dogs(dogs) {}
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};

#endif // ADOPTIONTABLE_H
