#include "skatEngine/include/trick.h"

skatEngine::Trick::Trick():firstCard(nullptr), secondCard(nullptr), thirdCard(nullptr), cardsPlayed(0)
{

}

skatEngine::Trick::~Trick()
{

}


void skatEngine::Trick::addCard(Card* nextCard)
{

    if(cardsPlayed==0)
    {

        firstCard = nextCard;

    }
    else if(cardsPlayed==1)
    {

        secondCard = nextCard;

    }
    else if(cardsPlayed==2)
    {

        thirdCard = nextCard;

    }

    cardsPlayed++;
}

void skatEngine::Trick::getPlayedCards(Card* firstPlayedCard, Card* secondPlayedCard, Card* thirdPlayedCard)
{

    firstPlayedCard = firstCard;
    secondPlayedCard = secondCard;
    thirdPlayedCard = thirdCard;
}
