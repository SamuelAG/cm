#ifndef ENTITY_H
#define ENTITY_H

#include "data_decorator.h"

#include <QObject>
#include <cm-lib_global.h>
#include <QJsonObject>

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
protected:
    Entity* addChild(Entity* entity, const QString& key);
    DataDecorator* addDataItem(DataDecorator* dataDecorator);
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}


#endif // ENTITY_H
