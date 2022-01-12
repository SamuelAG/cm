#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include <QObject>
#include <cm-lib_global.h>
#include <data/data_decorator.h>
#include <QJsonValue>
#include <QJsonObject>

namespace cm {
namespace data {

class CMLIB_EXPORT StringDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    StringDecorator(Entity *parentEntity = nullptr, const QString& key = "SomeItemKey", const QString& label = "", const QString& value = "");
    ~StringDecorator();

    void setValue(const QString& value);
    const QString& value() const;

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

#endif // STRINGDECORATOR_H
