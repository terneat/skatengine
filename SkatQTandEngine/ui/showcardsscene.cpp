#include "ui/showcardsscene.h"

#include "skatEngine/skatenums.h"
#include "interface/qskatengine.h"

#include <QString>

#include <utility>
#include <algorithm>

showCardsScene::showCardsScene(int s_width, QObject* parent): QGraphicsScene(0,0,s_width,230,parent),
    cardPics(10,nullptr), width(s_width), coffset(s_width/10), cards(10),
    skatPos(std::make_pair(4,5)), trickPos({3,5,7}), otherScene(nullptr)
{

}

showCardsScene::~showCardsScene()
{
    for(std::vector<CardItem*>::iterator cit = cardPics.begin();cit!=cardPics.end();++cit)
    {
        if(*cit != nullptr) delete *cit;
    }
}

void showCardsScene::setCard(const QString& cardname, int pos, bool inLower )
{

    if(pos >= 0 && pos < 10)
    {

    CardItem* oldcard = this->cardPics.at(pos);

    if(oldcard != nullptr)
    {
        removeItem(oldcard);
        delete oldcard;
    }

    QPixmap newCard = QPixmap(cardname);
    newCard = newCard.scaledToWidth(coffset-10,Qt::SmoothTransformation);

    if (inLower) cardPics[pos] = new CardItem(newCard, coffset, pos, this, nullptr);
    else cardPics[pos] = new CardItem(newCard, coffset, pos, nullptr, this);
    cardPics[pos]->setOffset(10+pos*coffset,0);
    this->addItem(cardPics[pos]);

    }
}

void showCardsScene::setEnumAtPos(skatEngine::Icard card, int pos)
{
    this->cards.at(pos) = card;
}

void showCardsScene::setItemAtPos(CardItem* cardPic, int pos)
{

    cardPic->shiftToPos(pos);
    this->cardPics.at(pos) = cardPic;
    update();
}

CardItem* showCardsScene::getItemFromPos(int pos)
{
    return cardPics.at(pos);
}


void showCardsScene::setPlayerCards(std::vector<skatEngine::Icard> playerCards)
{
    QString cardname;
    int pos=0;
    for(std::vector<skatEngine::Icard>::iterator cit = playerCards.begin();cit!=playerCards.end();++cit)
    {
        cardname = QSkatEngine::getNameFromEnum(*cit);
        setCard(cardname, pos, true);
        ++pos;
    }
    cards = playerCards;

}

void showCardsScene::setSkatCards(std::pair<skatEngine::Icard, skatEngine::Icard> theSkat)
{
    QString cardname;

    cardname = QSkatEngine::getNameFromEnum(theSkat.first);
    setCard(cardname, skatPos.first, false );

    cardname = QSkatEngine::getNameFromEnum(theSkat.second);
    setCard(cardname, skatPos.second, false );

    cards.at(skatPos.first) = theSkat.first;
    cards.at(skatPos.second) = theSkat.second;

}

int showCardsScene::getPosFromEnum(skatEngine::Icard card)
{
    int pos = 0;
    for(std::vector<skatEngine::Icard>::iterator cit = cards.begin();cit!=cards.end();++cit, ++pos)
    {
        if( card.first == cit->first && card.second == cit->second ) break;
    }

    return pos;
}


skatEngine::Icard showCardsScene::getEnumFromPos(int pos)
{

    return cards.at(pos);

}




void showCardsScene::swapCards(int pos1, int pos2)
{
    if(pos1>=0 && pos1 <10 && pos2>=0 && pos2 <10)
    {

        cardPics[pos1]->shiftToPos(pos2);
        cardPics[pos2]->shiftToPos(pos1);

        std::iter_swap(cardPics.begin()+pos1, cardPics.begin()+pos2);
        std::iter_swap(cards.begin()+pos1, cards.begin()+pos2);

        update();

    }
}

void showCardsScene::exchangeCards(int posLower, int posUpper)
{
    if(this->otherScene != nullptr && posLower>=0 && posLower <10 && posUpper>=0 && posUpper <10)
    {

        showCardsScene* lowerScene = this->otherScene;

        skatEngine::Icard toLower = getEnumFromPos(posUpper);
        skatEngine::Icard toUpper = lowerScene->getEnumFromPos(posLower);

        setEnumAtPos(toUpper, posUpper);
        lowerScene->setEnumAtPos(toLower, posLower);

        CardItem* cToLower = getItemFromPos(posUpper);
        this->removeItem(cToLower);
        CardItem* cToUpper = lowerScene->getItemFromPos(posLower);
        lowerScene->removeItem(cToUpper);

        cToLower->changeScene(lowerScene);
        cToUpper->changeScene(this);

        this->addItem(cToUpper);
        setItemAtPos(cToUpper, posUpper);

        lowerScene->addItem(cToLower);
        lowerScene->setItemAtPos(cToLower, posLower);

        update();
        lowerScene->update();

    }
}


void showCardsScene::removeCard(int pos)
{
    removeItem(cardPics[pos]);
    delete cardPics[pos];
    cardPics[pos] = nullptr;
    cards.at(pos) = std::make_pair(skatEngine::ColorType::NO, skatEngine::ValueType::NO);
}
