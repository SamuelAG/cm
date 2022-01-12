#include "command.h"

namespace cm {
namespace framework {

class cm::framework::Command::Implementation {
public:
    QString iconCharacter;
    QString description;
    std::function<bool()> canExecute;

    Implementation(const QString& _iconCharacter, const QString& _description, std::function<bool ()> _canExecute) :
        iconCharacter(_iconCharacter), description(_description), canExecute(_canExecute) {}
};

cm::framework::Command::Command(QObject *parent, const QString& iconCharacter, const QString& description, std::function<bool ()> canExecute) : QObject(parent)
{
    implementation.reset(new Implementation(iconCharacter, description, canExecute));
}

cm::framework::Command::~Command()
{
}

const QString &cm::framework::Command::iconCharacter() const
{
    return implementation->iconCharacter;
}

const QString &cm::framework::Command::description() const
{
    return implementation->description;
}

bool cm::framework::Command::canExecute() const
{
    return implementation->canExecute();
}

}}
