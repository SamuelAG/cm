#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H

#include <QObject>
#include <cm-lib_global.h>
#include <framework/command.h>
#include <QtQml/QQmlListProperty>
#include <QDebug>

namespace cm {
namespace controllers {

class CMLIB_EXPORT CommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands READ ui_createClientViewContextCommands CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommands READ ui_findClientViewContextCommands CONSTANT)
public:
    explicit CommandController(QObject *parent = nullptr);
    ~CommandController();
    QQmlListProperty<framework::Command> ui_createClientViewContextCommands();
    QQmlListProperty<framework::Command> ui_findClientViewContextCommands();
public slots:
    // CreateClientView slots
    void onCreateClientSaveExecuted();
    // FindClientView slots
    void onFindClientExecuted();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}
#endif // COMMAND_CONTROLLER_H
