#include "master_controller.h"

namespace cm {
namespace controllers {

class MasterController::Implementation {
public:
    Implementation(MasterController* _masterController) : masterController(_masterController)
    {
        navigationController = new NavigationController(masterController);
        commandController = new CommandController(masterController);
        newClient = new models::Client(masterController);
    }
    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController *commandController{nullptr};
    models::Client *newClient{nullptr};
    QString welcomeMessage = "Welcome to the Client Management system!";
};

MasterController::MasterController(QObject *parent)
    : QObject{parent}
{
    implementation.reset(new Implementation(this));
}

MasterController::~MasterController()
{

}

NavigationController *MasterController::navigationController()
{
    return implementation->navigationController;
}

CommandController *MasterController::commandController()
{
    return implementation->commandController;
}

models::Client *MasterController::newClient()
{
    return implementation->newClient;
}

const QString &MasterController::welcomeMessage() const
{
    return implementation->welcomeMessage;
}

}}
