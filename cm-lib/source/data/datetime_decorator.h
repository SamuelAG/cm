#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H


class DateTimeDecorator
{
public:
    DateTimeDecorator();
};

#include <QObject>
#include <cm-lib_global.h>
#include <data/data_decorator.h>
#include <QJsonValue>
#include <QJsonObject>

namespace cm {
namespace data {

class CMLIB_EXPORT DateTimeDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)
public:
    DateTimeDecorator(Entity *parentEntity = nullptr, const QString& key = "SomeItemKey", const QString& label = "", const QDateTime& value = QDateTime::currentDateTime());
    ~DateTimeDecorator();

    DateTimeDecorator& setValue(const QDateTime& value);
    const QDateTime& value() const;
    QString toPrettyString() const;
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

#endif // DATETIMEDECORATOR_H
