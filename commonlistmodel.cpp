/*****************************************************************************
 * commonlistmodel.cpp
 *
 * Created: 8 2017 by amir
 *
 * Copyright 2017 "INTERSET". All rights reserved.
**************************************************************************/
#include "commonlistmodel.h"

CommonListModel::CommonListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    CommonListItem item(QVariantList << "one" << "two");
    CommonListItem item1(QVariantList << "onedf" << "two231");
    CommonListItem item2(QVariantList << "oneads" << "twoafsd");
    CommonListItem item3(QVariantList << "onexcvzx" << "twobvnbcv");
    _items.push_back(item);
    _items.push_back(item1);
    _items.push_back(item2);
    _items.push_back(item3);
}

QVariant CommonListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    // FIXME: Implement me!
}

bool CommonListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int CommonListModel::rowCount(const QModelIndex &parent) const {
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return _items.size();
}

QVariant CommonListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    return _items.at(index.row()).at(role);
}

bool CommonListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        _items.at(index.row())[role] = value;
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags CommonListModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool CommonListModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    for (int i = 0; i < count; i++) {
        CommonListItem item();
        _items.insert(i + row, item);
    }
    endInsertRows();
}

bool CommonListModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}
