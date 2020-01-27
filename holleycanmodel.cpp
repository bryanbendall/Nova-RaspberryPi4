#include "holleycanmodel.h"


int HolleyCanModel::rowCount(const QModelIndex &) const
{
    return mItems.size();
}

QVariant HolleyCanModel::data(const QModelIndex &index, int role) const
{
    QObject* item = mItems.at(index.row());
    return QVariant::fromValue(item);
}

void HolleyCanModel::insert(QObject *item)
{
    beginInsertRows(QModelIndex(), 0, 0);
    mItems.push_front(item);
    endInsertRows();
}

void HolleyCanModel::remove(QObject *item)
{
    for (int i = 0; i < mItems.size(); ++i) {
      if (mItems.at(i) == item) {
        beginRemoveRows(QModelIndex(), i, i);
        mItems.remove(i);
        endRemoveRows();
        break;
      }
    }
}

QHash<int, QByteArray> HolleyCanModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "item";
    return roles;
}
