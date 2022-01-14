#include "master_controller_tests.h"

namespace cm {
namespace controllers {
static MasterControllerTests instance;
MasterControllerTests::MasterControllerTests() : TestSuite("MasterControllerTests")
{
}

MasterControllerTests::~MasterControllerTests()
{
}
}

namespace controllers { // Scaffolding

void MasterControllerTests::initTestCase()
{
}

void MasterControllerTests::cleanupTestCase()
{
}

void MasterControllerTests::init()
{
}

void MasterControllerTests::cleanup()
{
}

}

namespace controllers { // Tests
void MasterControllerTests::welcomeMessage_returnsCorrectMessage()
{
    QCOMPARE( masterController.welcomeMessage(), QString("Welcome to the Client Management system!") );
}

}
}
