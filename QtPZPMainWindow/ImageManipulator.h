#pragma once
#include "ui_QtMainWindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QRectF>

class ImageItem : public QGraphicsItem {
public:
	ImageItem() : image(nullptr) {}

	QRectF boundingRect() const override {
		return QRectF(0, 0, image->width(), image->height());
	}

	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override {
		painter->drawImage(0, 0, *image);
	}

	QImage* image;  // ”казатель на оригинал!
};

class ImageManipulator
{
public:
	ImageManipulator(QWidget* parent);

	void SetGraphicsView(QGraphicsView* pGraphicsView);

	void DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap);
	
	void Update() 
	{
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 100; ++j)
			{
				QRgb rgb(qRgb(255, 255, 255));
				QColor color(rgb);
				m_Image->setPixel(i, j, rgb);
			}
		}

	/*	m_pixMap.convertFromImage(*m_Image);

		m_pp->setPixmap(m_pixMap);*/

		m_pGraphicsView->update();
	}
private:

	QGraphicsPixmapItem* m_pp;

	ImageItem m_i;

	std::unique_ptr<QImage> m_Image;
	QPixmap m_pixMap;

	std::unique_ptr<QGraphicsScene> m_pScene;
	QGraphicsView* m_pGraphicsView;
};

