#include "commonlistmodel.h"

#include <QRandomGenerator>
#include <QTimer>

CommonListModel::CommonListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    CommonListItem item(QVariantList() << QVariant("one") << QVariant("two"));
    CommonListItem item1(QVariantList() << "onedf" << "two231");
    CommonListItem item2(QVariantList() << "oneads" << "twoafsd");
    CommonListItem item3(QVariantList() << "onexcvzx" << "twobvnbcv");
    _items.push_back(item);
    _items.push_back(item1);
    _items.push_back(item2);
    _items.push_back(item3);

    QTimer *_timer = new QTimer(this); //Hi
    connect(_timer, &QTimer::timeout, this, &CommonListModel::exampleDataUpdate);
    _timer->setInterval(2000);
    _timer->start();

}

QVariant CommonListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(role);
    return QVariant();
}

bool CommonListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if (value != headerData(section, orientation, role)) {
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
    QVariant ret;
    switch (role) {
    case OneRole:
        ret = _items.at(index.row()).at(0);
        break;
    case TwoRole:
        ret = _items.at(index.row()).at(1);
        break;
    default:
        break;
    }
    return ret;
}

bool CommonListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        //you can avoid this nonesence with a "short if"
        //if you use a dictionary with a role keys for example
        _items[index.row()][role == OneRole ? 0 : 1] = value;
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags CommonListModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable;
}

bool CommonListModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; i++) {
        CommonListItem item(QVariantList() << "one14q" << "two22q");
        _items.insert(i + row, item);
    }
    endInsertRows();

    return true;
}

bool CommonListModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();

    return false;
}

QHash<int, QByteArray> CommonListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles.insert(OneRole, "onerole");
    roles.insert(TwoRole, "tworole");

    return roles;
}

void CommonListModel::exampleDataUpdate() {
    QVariant newData = QVariant("some data" + QString::number(QRandomGenerator::system()->bounded(0, 100)));
    //set new data for an item in a row #2 for a role = "tworole"
    setData(createIndex(2, 0), newData, ModelRoles::TwoRole);
}

CommonListModel::~CommonListModel(){
}
