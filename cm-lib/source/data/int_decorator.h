#ifndef INTDECORATOR_H
#define INTDECORATOR_H

#include <QObject>
#include <cm-lib_global.h>
#include <data/data_decorator.h>
#include <QJsonValue>
#include <QJsonObject>

namespace cm {
namespace data {

class CMLIB_EXPORT IntDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    IntDecorator(Entity *parentEntity = nullptr, const QString& key = "SomeItemKey", const QString& label = "", const int& value = 0);
    ~IntDecorator();

    void setValue(const int& value);
    const int& value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject& jsonObject) override;
signals:
    void valueChanged();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}

#endif // INTDECORATOR_H
