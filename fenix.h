#ifndef FENIX_H
#define FENIX_H

#include "specialqgraphicspixmapitem.h"
#include <QObject>

class Fenix : public SpecialQGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fenix();
    Fenix(qreal x, qreal y);
    ~Fenix();
    virtual void hitted(int damage) Q_DECL_OVERRIDE;

signals:
    void fenixDestroyed();

private:
    int mHealth;
};

#endif // FENIX_H
