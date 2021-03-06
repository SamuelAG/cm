#include "appointment.h"



namespace cm {
namespace models {

using namespace cm::data;

Appointment::Appointment(QObject* parent) : Entity(parent, "appointment") {
    startAt = static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "startAt", "Start")));
    endAt = static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "endAt", "End")));
    notes = static_cast<StringDecorator*>(addDataItem(new DateTimeDecorator(this, "notes", "Notes")));
}

Appointment::Appointment(QObject* parent, const QJsonObject& json) : Appointment(parent) {
    update(json);
}

}}
