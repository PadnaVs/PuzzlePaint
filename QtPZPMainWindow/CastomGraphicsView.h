#pragma once
#include "..\..\..\sdk\qt\include\QtWidgets\qgraphicsview.h"
#include "..\..\..\sdk\qt\include\QtGui\qevent.h"

namespace PzpUI
{
    class CastomGraphicsView :
        public QGraphicsView
    {
    public:
        CastomGraphicsView(QWidget* parent = nullptr);
        CastomGraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);

    protected:

        void wheelEvent(QWheelEvent* event) override;
    };
}
