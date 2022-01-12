#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include <cm-lib_global.h>

namespace cm {
namespace data {

class Entity;

class CMLIB_EXPORT DataDecorator : public QObject
{
    Q_OBJECT
public:
    DataDecorator(Entity * parent = nullptr, const QString& key = "SomeItemKey", const QString& label = "");
    virtual ~DataDecorator();

    const QString& key() const;
    const QString& label() const;
    Entity* parentEntity();

    virtual QJsonValue jsonValue() const = 0;
    virtual void update(const QJsonObject& jsonObject) = 0;
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}
#endif // DATADECORATOR_H
