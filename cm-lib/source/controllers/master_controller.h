#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <cm-lib_global.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage MEMBER welcomeMessage CONSTANT)
public:
    QString welcomeMessage = "This is MasterController to Major Tom";
    explicit MasterController(QObject *parent = nullptr);

signals:

};

}}

#endif // MASTERCONTROLLER_H
