#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

#include "situation_node_view_item.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;

    qmlRegisterType<presentation::SituationNodeViewItem>("Situation", 1, 0, "SituationNodeView");

    view.setSource(QUrl("qrc:/qml/Main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setMinimumSize(QSize(1280, 800));
    view.show();
    return app.exec();
}
