#ifndef SITUATION_NODE_H
#define SITUATION_NODE_H

#include "situation_traits.h"

#include <QVariant>

namespace situation
{
    class Node
    {
    public:
        Node(const QString& id = QString(),
             const GeometryPtr& geometry = GeometryPtr(),
             const BoundingBoxPtr& boundingBox = BoundingBoxPtr(),
             const QVariantMap& properties = QVariantMap(),
             const NodePtrList& childNodes = NodePtrList());

        QString id() const;
        void setId(const QString& id);

        GeometryPtr geometry() const;
        void setGeometry(const GeometryPtr& geometry);

        BoundingBoxPtr boundingBox() const;
        void setBoundingBox(const BoundingBoxPtr& boundingBox);

        QVariantMap properties() const;
        void setProperties(const QVariantMap& properties);

        NodePtrList childNodes() const;
        NodePtrList& rChildNodes();
        void setChildNodes(const NodePtrList& childNodes);

        bool isEqual(const Node& other) const;
        inline friend bool operator==(const Node& left, const Node& right)
        {
            return left.isEqual(right);
        }
        inline friend bool operator!=(const Node& left, const Node& right)
        {
            return !left.isEqual(right);
        }

    private:
        QString m_id;
        GeometryPtr m_geometry;
        BoundingBoxPtr m_boundingBox;
        QVariantMap m_properties;
        NodePtrList m_childNodes;
    };
}

#endif // SITUATION_NODE_H
