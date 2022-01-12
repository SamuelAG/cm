#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <cm-lib_global.h>
#include <controllers/navigation_controller.h>
#include <controllers/command_controller.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
    Q_PROPERTY(cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)
    Q_PROPERTY(cm::controllers::CommandController* ui_commandcontroller READ commandController CONSTANT)
public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();
    NavigationController* navigationController();
    CommandController* commandController();
    const QString& welcomeMessage() const;
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
signals:

};

}}

#endif // MASTERCONTROLLER_H
