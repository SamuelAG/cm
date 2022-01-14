#ifndef ENTITY_H
#define ENTITY_H

#include "data_decorator.h"

#include <QObject>
#include <cm-lib_global.h>
#include <QJsonObject>
#include <data/entity_collection.h>

namespace cm {
namespace data {

class CMLIB_EXPORT Entity : public QObject
{
    Q_OBJECT
public:
    Entity(QObject *parent = nullptr, const QString& key = "SomeEntityKey");
    Entity(QObject *parent, const QString& key, const QJsonObject& jsonObject);
    virtual ~Entity();


    const QString& key() const;
    void update(const QJsonObject& jsonObject);
    QJsonObject toJson() const;
signals:
    void childEntitiesChanged();
    void dataDecoratorsChanged();
    void childCollectionsChanged(const QString& collectionKey);
protected:
    Entity* addChild(Entity* entity, const QString& key);
    DataDecorator* addDataItem(DataDecorator* dataDecorator);
    EntityCollectionBase* addChildCollection(EntityCollectionBase* entityCollection);
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}


#endif // ENTITY_H
