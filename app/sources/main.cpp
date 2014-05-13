#include <QtGui/QGuiApplication>
#include <QQuickView>

#include "situation_map.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.setSource(QUrl("qrc:/qml/Main.qml"));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setMinimumSize(QSize(1280, 800));
    view.show();

    core::SituationMap map;
    map.debug();

    return app.exec();
}
