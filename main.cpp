#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Graph.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Graph/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);


    Graph graph;


    engine.rootContext()->setContextProperty("Graph",
                                             &graph);

    engine.load(url);

    return app.exec();
}
