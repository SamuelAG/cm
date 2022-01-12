#include "enumerator_decorator.h"


namespace cm {
namespace data {

class EnumeratorDecorator::Implementation {
public:
    EnumeratorDecorator* enumeratorDecorator{nullptr};
    int value;
    std::map<int, QString> descriptionMapper;
    Implementation(EnumeratorDecorator *_enumeratorDecorator, const int& _value, std::map<int, QString> _descriptionMapper) : enumeratorDecorator(_enumeratorDecorator), value(_value), descriptionMapper(_descriptionMapper)
    {
    }
};

EnumeratorDecorator::EnumeratorDecorator(Entity *parentEntity, const QString &key, const QString &label, int value, const std::map<int, QString> &descriptionMapper) : DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value, descriptionMapper));
}

EnumeratorDecorator::~EnumeratorDecorator()
{
}

void EnumeratorDecorator::setValue(int value)
{
    if(value != implementation->value) {
        implementation->value = value;
    } else {
        implementation->value = 0;
    }
    emit valueChanged();
}

int EnumeratorDecorator::value() const
{
    return implementation->value;
}

QString EnumeratorDecorator::valueDescription() const
{
    if (implementation->descriptionMapper.find(implementation->value) != implementation->descriptionMapper.end()) {
        return implementation->descriptionMapper.at(implementation->value);
    } else {
        return {};
    }
}

QJsonValue EnumeratorDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void EnumeratorDecorator::update(const QJsonObject &_jsonObject)
{
    if(_jsonObject.contains(key())) {
        setValue(_jsonObject.value(key()).toInt());
    } else {
        setValue(0);
    }
}



}
}
