#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "commonlistmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    CommonListModel model;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("mymodel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
