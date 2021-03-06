#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <cm-lib_global.h>
#include <data/entity.h>
#include <data/enumerator_decorator.h>
#include "data/string_decorator.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Contact : public data::Entity {
    Q_OBJECT
    Q_PROPERTY(cm::data::EnumeratorDecorator* ui_type MEMBER type CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_address MEMBER address CONSTANT)
public:
    enum ContactType {
        UNKNOWN = 0,
        TELEPHONE,
        EMAIL,
        FAX
    };
    explicit Contact(QObject* parent = nullptr);
    Contact(QObject *parent, const QJsonObject& json);

    data::EnumeratorDecorator* type;
    data::StringDecorator* address;
    static std::map<int, QString> contactTypeMapper;
};

}
}

#endif // CONTACT_H
