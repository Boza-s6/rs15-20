#ifndef BUTTON_H
#define BUTTON_H
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QString>
#include <QObject>
#include <QMouseEvent>
#include "constants.h"

class Button : public QGraphicsObject
{
    Q_OBJECT
public:
    Button(const char *text, qreal x, qreal y);
    ~Button();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) Q_DECL_OVERRIDE;

protected:
    void advance(int phase) Q_DECL_OVERRIDE;

signals:
    void clicked();

private:
    QString mText;          // text koji ce se prikazivati na dugmetu
                            // qreal mX, mY;
    qreal mWidth, mHeight;  // sirina i visina dugmeta
    QPixmap mImage;         // slika dugmeta
    QPixmap mImagePressed;  // slika pritisnutog dugmeta
    bool pressed;
};

#endif // BUTTON_H
