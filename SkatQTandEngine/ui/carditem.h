#ifndef CARDITEM_H
#define CARDITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneDragDropEvent>

class showCardsScene;

class CardItem:public QGraphicsPixmapItem{
private:
    int offset;
    int spos;
    showCardsScene* lowerscene;
    showCardsScene* upperscene;
    bool dragOver;

public:

    CardItem(const QPixmap & pixmap, int s_coffset, int s_spos, showCardsScene* s_lowerscene, showCardsScene* s_upperscene, bool s_acceptDrops = true, QGraphicsItem * parent = 0);
    virtual ~CardItem();

    int findPos()const;
    void shiftToPos(int pos);
    void changeScene(showCardsScene*);

    // QGraphicsItem interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);

    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);

    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);


};

#endif // CARDITEM_H

