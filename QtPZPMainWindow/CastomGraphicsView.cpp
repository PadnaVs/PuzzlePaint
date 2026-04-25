#include "CastomGraphicsView.h"

namespace PzpUI
{
    CastomGraphicsView::CastomGraphicsView(QWidget* parent /*= nullptr*/) : QGraphicsView(parent)
    {

    }

    CastomGraphicsView::CastomGraphicsView(QGraphicsScene* scene, QWidget* parent /*= nullptr*/) : QGraphicsView(scene, parent)
    {
    }

    void CastomGraphicsView::wheelEvent(QWheelEvent* event)
    {
        // Получаем дельту прокрутки (обычно 120 за один шаг)
        double delta = event->angleDelta().y();

        // Коэффициент масштабирования (регулируйте чувствительность)
        double scaleFactor = 1.1;

        if (delta > 0) {
            // Увеличение
            scale(scaleFactor, scaleFactor);
        }
        else if (delta < 0) {
            // Уменьшение
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }

        // Центрируем масштабирование относительно позиции мыши (опционально)
        QPointF cursorPos = mapToScene(event->position().toPoint());
        centerOn(cursorPos);

        event->accept();
    }
}