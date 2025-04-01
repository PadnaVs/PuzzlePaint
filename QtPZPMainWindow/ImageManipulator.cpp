#include "ImageManipulator.h"
#include <QGraphicsPixmapItem>

ImageManipulator::ImageManipulator(QWidget* parent)
	: m_pGraphicsView(nullptr), m_pScene(std::make_unique<QGraphicsScene>(parent)), m_pp(nullptr)
{

}

void ImageManipulator::SetGraphicsView(QGraphicsView* pGraphicsView)
{
	if (!pGraphicsView)
		return;

	m_pGraphicsView = pGraphicsView;

	m_pGraphicsView->setScene(m_pScene.get());
	m_pGraphicsView->show();
}

void ImageManipulator::DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
{
	if (!pArrPixelMap)
		return;

	if (!m_pGraphicsView)
		return;

	int w = pArrPixelMap->size();
	int h = pArrPixelMap->at(0).size();

	m_pScene->clear();

	m_Image = std::make_unique<QImage>(w, h, QImage::Format::Format_RGB32);

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			QRgb rgb(qRgb(pArrPixelMap->at(i)[j][0], pArrPixelMap->at(i)[j][1], pArrPixelMap->at(i)[j][2]));
			QColor color(rgb);
			m_Image->setPixel(i, j, rgb);
		}
	}

	m_i.image = m_Image.get();
	m_pScene->addItem(&m_i);

	/*QGraphicsPixmapItem* pp = m_pScene->addPixmap(m_pixMap);

	m_pp = pp;

	m_pixMap.convertFromImage(*m_Image);

	m_pp->setPixmap(m_pixMap);*/

	m_pGraphicsView->update();
}
