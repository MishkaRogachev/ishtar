#ifndef SITUATION_NODE_H
#define SITUATION_NODE_H

#include "situation_traits.h"

#include "bounding_box.h"
#include "geometry.h"

#include <QVariant>

namespace situation
{
    class Node
    {
    public:
        Node(const QString& id = QString(),
             const GeometryPtr& geometry = GeometryPtr(),
             const BoundingBox& boundingBox = BoundingBox(),
             const QVariant& properties = QVariant(),
             const NodePtrList& childNodes = NodePtrList());

        QString id() const;
        void setId(const QString& id);

        GeometryPtr geometry() const;
        void setGeometry(const GeometryPtr& geometry);

        BoundingBox boundingBox() const;
        BoundingBox& rBoundingBox();

        QVariant properties() const;
        QVariant& rProperties();

        NodePtrList childNodes() const;
        NodePtrList& rChildNodes();

    private:
        QString m_id;
        GeometryPtr m_geometry;
        BoundingBox m_boundingBox;
        QVariant m_properties;
        NodePtrList m_childNodes;
    };
}

#endif // SITUATION_NODE_H
