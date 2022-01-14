#include <QtTest>

// add necessary includes here

class ClientTests : public QObject
{
    Q_OBJECT

public:
    ClientTests();
    ~ClientTests();

private slots:
    void test_case1();
    void test_case2();

};

ClientTests::ClientTests()
{

}

ClientTests::~ClientTests()
{

}

void ClientTests::test_case1()
{
    QVERIFY2(true, "teste 1");
}

void ClientTests::test_case2()
{
    QVERIFY2(false, "teste 2");
}

//QTEST_APPLESS_MAIN(ClientTests)

#include "tst_clienttests.moc"
