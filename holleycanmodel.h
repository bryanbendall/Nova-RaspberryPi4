#ifndef HOLLEYCANMODEL_H
#define HOLLEYCANMODEL_H

#include <QAbstractListModel>

class HolleyCanModel : public QAbstractListModel
{
public:
    int rowCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex& index, int role) const override;

public slots:
    void insert(QObject* item);
    void remove(QObject* item);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<QObject*> mItems;

};

#endif // HOLLEYCANMODEL_H
