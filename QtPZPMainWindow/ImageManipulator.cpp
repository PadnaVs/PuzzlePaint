#include "ImageManipulator.h"
#include <QGraphicsPixmapItem>

ImageManipulator::ImageManipulator(QWidget* parent)
	: m_pGraphicsView(nullptr), m_pScene(nullptr), m_pp(nullptr)
{

}

void ImageManipulator::SetGraphicsView(QGraphicsView* pGraphicsView)
{
	if (!pGraphicsView)
		return;

	m_pGraphicsView = pGraphicsView;

	QGraphicsScene* pScene = new QGraphicsScene(m_pGraphicsView);
	m_pScene = pScene;

	m_pScene->addItem(&m_ImageItem);

	m_pGraphicsView->setScene(pScene);
	
	m_pGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	m_pGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	m_pGraphicsView->show();
}

void ImageManipulator::CreateNewImage(int width, int height)
{
	if (!m_pGraphicsView)
		return;

	m_ImageItem.SetNewImage(width, height);

	m_pScene->setSceneRect(0, 0, width, height);

	m_pGraphicsView->invalidateScene();
	m_pGraphicsView->update();
}

void ImageManipulator::ChangeImage(int x, int y, int height, int width, std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
{
	if (!pArrPixelMap)
		return;

	if (!m_pGraphicsView)
		return;

	for (int i = x; i < height; ++i)
	{
		for (int j = y; j < width; ++j)
		{
			m_ImageItem.SetPixel(i, j, qRgb(pArrPixelMap->at(i)[j][0], pArrPixelMap->at(i)[j][1], pArrPixelMap->at(i)[j][2]));
		}
	}

	m_pScene->setSceneRect(0, 0, width, height);

	m_pGraphicsView->invalidateScene();
	m_pGraphicsView->update();
}

void ImageManipulator::Update()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			m_ImageItem.SetPixel(i, j, qRgb(0, 0, 0));
		}
	}

	m_pGraphicsView->invalidateScene();
	m_pGraphicsView->update();
}

QRectF ImageItem::boundingRect() const
{
	return QRectF(0, 0, m_pImage->width(), m_pImage->height());
}

void ImageItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
	painter->drawImage(0, 0, *m_pImage);
}

ImageItem::ImageItem() : m_pImage(std::make_unique<QImage>())
{

}

ImageItem::ImageItem(ImageItem& othr)
{

}

ImageItem::ImageItem(ImageItem&& othr)
{

}

ImageItem::ImageItem(ImageItem* othr)
{

}

void ImageItem::operator=(ImageItem* other)
{

}

void ImageItem::operator=(ImageItem& other)
{

}

ImageItem::~ImageItem()
{

}

void ImageItem::SetNewImage(int widht, int height)
{
	m_pImage = std::make_unique<QImage>(widht, height, QImage::Format::Format_RGB32);
}

void ImageItem::SetPixel(int x, int y, QRgb rgbColor)
{
	QRgb rgb(rgbColor);
	QColor color(rgb);
	m_pImage->setPixel(x, y, rgb);
}
