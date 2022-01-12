#include "command_controller.h"

using namespace cm::framework;
namespace cm {
namespace controllers {

class CommandController::Implementation {
public:
    CommandController *commandController{nullptr};
    QList<Command*> createClientViewContextCommands{new Command(commandController, QChar(0xf0c7), "Save")};

    Implementation(CommandController *_commandController) : commandController(_commandController) {
//        Command *createClientSaveCommand = new Command(commandController, QChar(0xf0c7), "Save")
        QObject::connect(createClientViewContextCommands[0], &Command::executed, commandController, &CommandController::onCreateClientSaveExecuted);
//        createClientViewContextCommands.append(createClientSaveCommand);
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

void CommandController::onCreateClientSaveExecuted()
{
    qDebug()<<"You executed the Save command!";
}

}}
