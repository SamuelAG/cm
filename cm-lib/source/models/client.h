#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <cm-lib_global.h>
#include <QtQml/QQmlListProperty>

#include "data/entity.h"
#include "data/string_decorator.h"
#include "data/entity_collection.h"
#include "models/address.h"
#include "models/appointment.h"
#include "models/contact.h"

namespace cm {
namespace models {

class CMLIB_EXPORT Client : public data::Entity {

    Q_OBJECT
    Q_PROPERTY(cm::data::StringDecorator* ui_reference MEMBER reference CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_name MEMBER name CONSTANT)
    Q_PROPERTY(cm::models::Address* ui_supplyAddress MEMBER supplyAddress CONSTANT)
    Q_PROPERTY(cm::models::Address* ui_billingAddress MEMBER billingAddress CONSTANT)
    Q_PROPERTY(QQmlListProperty<Appointment> ui_appointments READ ui_appointments NOTIFY appointmentsChanged)
    Q_PROPERTY(QQmlListProperty<Contact> ui_contacts READ ui_contacts NOTIFY contactsChanged)

public:
    explicit Client(QObject* parent = nullptr);
    Client(QObject* parent, const QJsonObject& json);

    data::StringDecorator* reference;
    data::StringDecorator* name;
    Address* supplyAddress;
    Address* billingAddress;

    data::EntityCollection<Appointment>* appointments;
    data::EntityCollection<Contact>* contacts;

    QQmlListProperty<cm::models::Appointment> ui_appointments();
    QQmlListProperty<cm::models::Contact> ui_contacts();

signals:
    void appointmentsChanged();
    void contactsChanged();
};

}}
#endif // CLIENT_H
