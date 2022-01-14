#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <controllers/master_controller.h>
#include <controllers/command_controller.h>
#include <data/int_decorator.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0, "NavigationController");
    qmlRegisterType<cm::controllers::CommandController>("CM", 1, 0, "CommandController");
    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");

    qmlRegisterType<cm::data::DateTimeDecorator>("CM", 1, 0, "DateTimeDecorator");
    qmlRegisterType<cm::data::EnumeratorDecorator>("CM", 1, 0, "EnumeratorDecorator");
    qmlRegisterType<cm::data::IntDecorator>("CM", 1, 0, "IntDecorator");
    qmlRegisterType<cm::data::StringDecorator>("CM", 1, 0, "StringDecorator");
    qmlRegisterType<cm::models::Address>("CM", 1, 0, "Address");
    qmlRegisterType<cm::models::Appointment>("CM", 1, 0, "Appointment");
    qmlRegisterType<cm::models::Client>("CM", 1, 0, "Client");
    qmlRegisterType<cm::models::Contact>("CM", 1, 0, "Contact");

    cm::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("masterController",&masterController);
    const QUrl url(QStringLiteral("qrc:/views/MasterView"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
