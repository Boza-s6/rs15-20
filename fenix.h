#ifndef FENIX_H
#define FENIX_H
#include "specialgraphicsitem.h"
#include <QPainter>
#include <QGraphicsScene>
class Fenix : public SpecialGraphicsItem
{
public:
    Fenix(qreal x, qreal y);
    ~Fenix();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)  Q_DECL_OVERRIDE;

public slots:
    void hitted(int damage)Q_DECL_OVERRIDE;
private:
    QPixmap mImage;

};

#endif // FENIX_H
