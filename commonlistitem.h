/*****************************************************************************
 * commonlistitem.h
 *
 * Created: 8 2017 by amir
 *
 * Copyright 2017 "INTERSET". All rights reserved.
**************************************************************************/
#ifndef COMMONLISTITEM_H
#define COMMONLISTITEM_H

#include <QVariant>
#include <QVariantList>

class CommonListItem {
public:
    CommonListItem(QVariantList data);

    QVariantList data() const;
    void setData(const QVariantList &data);
    const QVariant at(int i) const;
    QVariant& operator[] (int i);
private:
    QVariantList _data;
};

#endif // COMMONLISTITEM_H
