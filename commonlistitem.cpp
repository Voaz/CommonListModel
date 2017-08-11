/*****************************************************************************
 * commonlistitem.cpp
 *
 * Created: 8 2017 by amir
 *
 * Copyright 2017 "INTERSET". All rights reserved.
**************************************************************************/
#include "commonlistitem.h"

CommonListItem::CommonListItem(QVariantList data) : _data(data){

}

QVariantList CommonListItem::data() const {
    return _data;
}

void CommonListItem::setData(const QVariantList &data) {
    _data = data;
}

const QVariant CommonListItem::at(int i) const {
    if (i < _data.size() && i >= 0) {
        return _data.at(i);
    } else {
        return QVariant();
    }
}

QVariant &CommonListItem::operator[](int i) {
    return _data[i];
}
