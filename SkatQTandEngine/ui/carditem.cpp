#include "ui/carditem.h"

#include "ui/showcardsscene.h"

#include <QCursor>
#include <QDrag>
#include <QMimeData>

CardItem::CardItem(const QPixmap & pixmap, int s_coffset, int s_spos, showCardsScene* s_lowerscene, showCardsScene* s_upperscene, bool s_acceptDrops, QGraphicsItem * parent)
    :QGraphicsPixmapItem(pixmap,parent),offset(s_coffset),spos(s_spos), lowerscene(s_lowerscene), upperscene(s_upperscene), dragOver(false)
{
    this->setCursor(QCursor(Qt::PointingHandCursor));
    this->setAcceptedMouseButtons(Qt::LeftButton);
    this->setAcceptDrops(s_acceptDrops);
}

CardItem::~CardItem()
{

}

int CardItem::findPos() const
{

    return spos;
}

void CardItem::shiftToPos(int pos)
{

    if(pos>= 0 && pos < 10)
    {
        spos = pos;
        setOffset(10+pos*offset,0);
    }

}

void CardItem::changeScene(showCardsScene* newScene)
{
    if(this->lowerscene == nullptr)
    {
        this->lowerscene = newScene;
        this->upperscene = nullptr;
    }
    else
    {
        this->upperscene = newScene;
        this->lowerscene = nullptr;
    }
}


void CardItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(QCursor(Qt::ClosedHandCursor));
}

void CardItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(QCursor(Qt::PointingHandCursor));
}

void CardItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if( this->lowerscene != nullptr )
    {
        QDrag *drag = new QDrag(event->widget());
        QMimeData *mime = new QMimeData;
        int apos = this->findPos();
        mime->setText(QString::number(apos));
        drag->setMimeData(mime);

        drag->exec();
        setCursor(Qt::PointingHandCursor);
    }

}

void CardItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        QString posText = event->mimeData()->text();
        int pos1 = posText.toInt();
        if(pos1>= 0 && pos1 < 10)
        {
            event->setAccepted(true);
            dragOver = true;
            update();
        }
    }
    else
    {
        event->setAccepted(false);
    }
}

void CardItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{

    dragOver = false;
    if (event->mimeData()->hasText() && this->lowerscene != nullptr)
    {

           QString posText = event->mimeData()->text();
           int pos1 = posText.toInt();
           int pos2 = this->findPos();

           lowerscene->swapCards(pos1,pos2);

    }
    else if (event->mimeData()->hasText() && this->upperscene != nullptr)
    {

           QString posText = event->mimeData()->text();
           int posLower = posText.toInt();
           int posUpper = this->findPos();

           this->upperscene->exchangeCards(posLower,posUpper);

    }
    update();
}

void CardItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

