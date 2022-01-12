#include "command_controller.h"

using namespace cm::framework;
namespace cm {
namespace controllers {

class CommandController::Implementation {
public:
    CommandController *commandController{nullptr};
    QList<Command*> createClientViewContextCommands{};
    QList<Command*> findClientViewContextCommands{};

    Implementation(CommandController *_commandController) : commandController(_commandController) {
        Command *createClientSaveCommand = new Command(commandController, QChar(0xf0c7), "Save");
        QObject::connect(createClientSaveCommand, &Command::executed, commandController, &CommandController::onCreateClientSaveExecuted);
        createClientViewContextCommands.append(createClientSaveCommand);

        Command *findClientCommand = new Command(commandController, QChar(0xf002), "Find");
        QObject::connect(findClientCommand, &Command::executed, commandController, &CommandController::onFindClientExecuted);
        findClientViewContextCommands.append(findClientCommand);
    }
};

CommandController::CommandController(QObject *parent)
    : QObject{parent}
{
    implementation.reset(new Implementation(this));
}

cm::controllers::CommandController::~CommandController()
{
}

QQmlListProperty<Command> CommandController::ui_createClientViewContextCommands()
{
    return QQmlListProperty<Command>(this, &implementation->createClientViewContextCommands);
}

QQmlListProperty<Command> CommandController::ui_findClientViewContextCommands()
{
    return QQmlListProperty<Command>(this, &implementation->findClientViewContextCommands);
}

void CommandController::onCreateClientSaveExecuted()
{
    qDebug()<<"You executed the Save command!";
}

void CommandController::onFindClientExecuted()
{
    qDebug()<<"You executed the Find command!";
}

}}
