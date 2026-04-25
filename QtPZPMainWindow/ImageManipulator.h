#pragma once
#include "ui_QtMainWindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QRectF>

class ImageItem : public QGraphicsItem 
{
public:
	ImageItem();

	~ImageItem();

	void SetNewImage(int widht, int height);

	void SetPixel(int x, int y, QRgb rgbColor);

private:
	QRectF boundingRect() const override;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
	ImageItem(ImageItem& othr);
	
	ImageItem(ImageItem&& othr);
	
	ImageItem(ImageItem* othr);

	void operator=(ImageItem& other);
	void operator=(ImageItem* other);

private:
	std::unique_ptr<QImage> m_pImage;
};

class ImageManipulator
{
public:
	ImageManipulator(QWidget* parent);

	void SetGraphicsView(QGraphicsView* pGraphicsView);

	void CreateNewImage(int width, int height);

	void ChangeImage(int x, int y, int width, int height, std::vector<std::vector<std::vector<int>>>* pArrPixelMap);
	
	void Update();
private:

	QGraphicsPixmapItem* m_pp;

	ImageItem m_ImageItem;

	QPixmap m_pixMap;

	QGraphicsScene* m_pScene;
	QGraphicsView* m_pGraphicsView;
};

