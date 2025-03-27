#include "ImageManipulator.h"

ImageManipulator::ImageManipulator(QWidget* parent)
	: m_pGraphicsView(nullptr), m_pScene(std::make_unique<QGraphicsScene>(parent))
{

}
