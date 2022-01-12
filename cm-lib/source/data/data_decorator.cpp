#include "data_decorator.h"


namespace cm {
namespace data {

class DataDecorator::Implementation
{
public:
    Implementation(Entity* _parent, const QString& _key, const QString&
    _label) : parentEntity(_parent), key(_key), label(_label)
    {
    }
    Entity* parentEntity{nullptr};
    QString key;
    QString label;
};

cm::data::DataDecorator::DataDecorator(Entity *parent, const QString &key, const QString &label)
{
    implementation.reset(new Implementation(parent, key, label));
}

DataDecorator::~DataDecorator()
{
}

const QString &DataDecorator::key() const
{
    return implementation->key;
}

const QString &DataDecorator::label() const
{
    return implementation->label;
}

Entity *DataDecorator::parentEntity()
{
    return implementation->parentEntity;
}

}
}


