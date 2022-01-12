#include "string_decorator.h"

namespace cm {
namespace data {

class StringDecorator::Implementation {
public:
    StringDecorator* stringDecorator{nullptr};
    QString value;

    Implementation(StringDecorator* _stringDecorator, const QString& _value) : stringDecorator(_stringDecorator), value(_value)
    {
    }
};

StringDecorator::StringDecorator(Entity *parentEntity, const QString &key, const QString &label, const QString &value) : DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value));
}

StringDecorator::~StringDecorator()
{
}

void StringDecorator::setValue(const QString &value)
{
    if(value != implementation->value) {
        implementation-> value = value;
        emit valueChanged();
    }
//    return *this;
}

const QString &StringDecorator::value() const
{
    return implementation->value;
}

QJsonValue cm::data::StringDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void StringDecorator::update(const QJsonObject &_jsonObject)
{
    if(_jsonObject.contains(key())) {
        setValue(_jsonObject.value(key()).toString());
    } else {
        setValue("");
    }
}
}
}

