#include "entity.h"

namespace cm {
namespace data {

class Entity::Implementation {
public:
    Implementation(Entity* _entity, const QString& _key) : entity(_entity), key(_key)
    {
    }
    Entity* entity{nullptr};
    QString key;
    std::map<QString, Entity*> childEntities;
    std::map<QString, DataDecorator*> dataDecorators;
};

Entity::Entity(QObject *parent, const QString &key) : QObject(parent)
{
    implementation.reset(new Implementation(this, key));
}

Entity::Entity(QObject *parent, const QString &key, const QJsonObject &jsonObject) : Entity(parent, key)
{
    update(jsonObject);
}

Entity::~Entity()
{
}

const QString &Entity::key() const
{
    return implementation->key;
}

void Entity::update(const QJsonObject &jsonObject)
{
    // Update data decorators
    for (std::pair<QString, DataDecorator*> dataDecoratorPair : implementation->dataDecorators) {
        dataDecoratorPair.second->update(jsonObject);
    }
    // Update child entities
    for (std::pair<QString, Entity*> childEntityPair : implementation->childEntities) {
        childEntityPair.second->update(jsonObject.value(childEntityPair.first).toObject());
    }
}

QJsonObject Entity::toJson() const
{
    QJsonObject returnValue;
    // Add data decorators
    for (std::pair<QString, DataDecorator*> dataDecoratorPair : implementation->dataDecorators) {
        returnValue.insert( dataDecoratorPair.first,
        dataDecoratorPair.second->jsonValue() );
    }
    // Add child entities
    for (std::pair<QString, Entity*> childEntityPair : implementation->childEntities) {
        returnValue.insert( childEntityPair.first,
        childEntityPair.second->toJson() );
    }
    return returnValue;
}

Entity *Entity::addChild(Entity *entity, const QString &key)
{
    if(implementation->childEntities.find(key) == std::end(implementation->childEntities)) {
        implementation->childEntities[key] = entity;
        emit childEntitiesChanged();
    }
    return entity;
}

DataDecorator *Entity::addDataItem(DataDecorator *dataDecorator)
{
    if(implementation->dataDecorators.find(dataDecorator->key()) ==
        std::end(implementation->dataDecorators)) {
        implementation->dataDecorators[dataDecorator->key()] =
        dataDecorator;
        emit dataDecoratorsChanged();
    }
    return dataDecorator;
}

}
}
