/*****************************************************************************
 * commonlistmodel.h
 *
 * Created: 8 2017 by amir
 *
 * Copyright 2017 "INTERSET". All rights reserved.
**************************************************************************/
#ifndef COMMONLISTMODEL_H
#define COMMONLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <commonlistitem.h>
class CommonListModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum ModelRoles {
        OneRole = Qt::UserRole + 1,
        TwoRole
    };
    explicit CommonListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    QHash<int, QByteArray> roleNames() const;
private slots:
    void updateData();
private:
    QList<CommonListItem> _items;
};

#endif // COMMONLISTMODEL_H
