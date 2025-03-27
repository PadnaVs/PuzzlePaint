#pragma once
#include "ui_QtMainWindow.h"

class ImageManipulator
{
public:
	ImageManipulator(QWidget* parent);

	void SetGraphicsView(QGraphicsView* pGraphicsView)
	{
		if (!pGraphicsView)
			return;

		m_pGraphicsView = pGraphicsView;

		m_pGraphicsView->setScene(m_pScene.get());
		m_pGraphicsView->show();
	}

	void DrawImage(std::vector<std::vector<std::vector<int>>>* pArrPixelMap)
	{
		if (!pArrPixelMap)
			return;

		if (!m_pGraphicsView)
			return;

		int w = pArrPixelMap->size();
		int h = pArrPixelMap->at(0).size();

		m_pScene->clear();

		QImage img(w, h, QImage::Format::Format_RGB32);

		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < pArrPixelMap->at(i).size(); ++j)
			{
				QRgb rgb(qRgb(pArrPixelMap->at(i)[j][0], pArrPixelMap->at(i)[j][1], pArrPixelMap->at(i)[j][2]));
				QColor color(rgb);
				img.setPixel(i, j, rgb);
			}
		}

		m_pScene->addPixmap(QPixmap::fromImage(img));

		m_pGraphicsView->update();
	}

private:
	std::unique_ptr<QGraphicsScene> m_pScene;
	QGraphicsView* m_pGraphicsView;
};

