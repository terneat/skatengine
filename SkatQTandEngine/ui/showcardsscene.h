#ifndef SHOWCARDSSCENE_H
#define SHOWCARDSSCENE_H

#include "ui/carditem.h"
#include "skatEngine/skatenums.h"

#include <QGraphicsScene>

#include <utility>
#include <vector>

class showCardsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit showCardsScene(int width ,QObject *parent = 0);
    virtual ~showCardsScene();
protected:
    std::vector<CardItem*> cardPics;
    int width;
    int coffset;
    std::vector<skatEngine::Icard> cards;
    std::pair<int,int> skatPos;
    std::vector<int> trickPos;
    showCardsScene* otherScene;
public :
    void setPlayerCards(std::vector<skatEngine::Icard>);
    void setSkatCards(std::pair<skatEngine::Icard,skatEngine::Icard>);
    int getPosFromEnum(skatEngine::Icard);
public slots:
    void setCard(const QString& cardname, int pos , bool Inlower);
    void setEnumAtPos(skatEngine::Icard card, int pos);

    void swapCards(int pos1, int pos2);
    void exchangeCards(int posLower, int posUpper);

    void removeCard(int pos);
    skatEngine::Icard getEnumFromPos(int pos);
    void setItemAtPos(CardItem *cardPic, int pos);
    CardItem *getItemFromPos(int pos);

    void setOtherScene(showCardsScene* oscene){this->otherScene = oscene;}
    showCardsScene*  getOtherScene() const{return this->otherScene;}
};

#endif // SHOWCARDSSCENE_H

