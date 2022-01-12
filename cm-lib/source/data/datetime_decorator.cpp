#include "datetime_decorator.h"

namespace cm {
namespace data {

class DateTimeDecorator::Implementation {
public:
    DateTimeDecorator* dateTimeDecorator{nullptr};
    QDateTime value;

    Implementation(DateTimeDecorator* _stringDecorator, const QDateTime& _value) : dateTimeDecorator(_stringDecorator), value(_value)
    {
    }
};


DateTimeDecorator::DateTimeDecorator(Entity *parentEntity, const QString &key, const QString &label, const QDateTime &value) : DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value));
}


DateTimeDecorator::~DateTimeDecorator()
{
}

DateTimeDecorator &DateTimeDecorator::setValue(const QDateTime &value)
{
    if(value != implementation->value) {
        implementation-> value = value;
        emit valueChanged();
    }
    return *this;
}

const QDateTime &DateTimeDecorator::value() const
{
    return implementation->value;
}

QString DateTimeDecorator::toPrettyString() const
{
    if (implementation->value.isNull()) {
        return "Not set";
    } else {
        return implementation->value.toString( "ddd d MMM yyyy @ HH:mm:ss");
    }
}

QJsonValue DateTimeDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void DateTimeDecorator::update(const QJsonObject &_jsonObject)
{
    if(_jsonObject.contains(key())) {
//        setValue(_jsonObject.value(key()).toVariant);
    } else {
        setValue(QDateTime::currentDateTime());
    }
}
}
}
