#include "skatEngine/include/round.h"
#include "skatEngine/include/trick.h"
#include "skatEngine/include/card.h"
#include "skatEngine/include/cardset.h"
#include "skatEngine/include/player.h"

using namespace skatEngine;

std::vector<int> Round::bidValues = {0, 18, 20, 22, 23, 24, 27, 30, 33, 35, 36, 40, 44, 45, 46, 48, 50, 54, 55, 59, 60, 63, 66, 70, 72, 96};

Round::Round(Player* p1, Player* p2, Player* p3, CardSet* s_cards, Player* s_geber):
    player1(p1), player2(p2), player3(p3), cards(s_cards), geber(s_geber), activePlayer(s_geber),
    stage(skatEngine::RoundStage::REIZEN), tricksPlayed(0), biddenToIndex(0)
{
    this->distributeCards();
}

Round::~Round()
{

}

Card* Round::getSkatCard(int cardn)
{
    if( cardn ==1 ) return theSkat.first;
    if( cardn ==2 ) return theSkat.second;
    return nullptr;
}

Icard Round::getSkatCard_Enum(int cardn)
{
    Card* card = getSkatCard(cardn);
    if(card != nullptr) return card->toEnumPair();
    return std::make_pair(skatEngine::ColorType::NO, skatEngine::ValueType::NO);
}


Card* Round::getPlayerCard(int playern, int cardn)
{
    if( playern ==1 ) return player1->getSingleCard(cardn);
    else if ( playern==2 ) return player2->getSingleCard(cardn);
    else if ( playern==3 ) return player3->getSingleCard(cardn);

    return nullptr;
}

Icard Round::getPlayerCard_Enum(int playern, int cardn)
{
    Card* card = getPlayerCard(playern, cardn);
    if(card != nullptr) return card->toEnumPair();
    return std::make_pair(skatEngine::ColorType::NO, skatEngine::ValueType::NO);

}


std::vector<Icard> Round::getPlayerCards_Enum(int playern)
{
    std::vector<Icard> playerCards(10);
    for(int c = 0;c<10;++c)playerCards.at(c) = this->getPlayerCard_Enum(playern, c);
    return playerCards;
}

void Round::distributeCards()
{
    cards->mixCards();
    Card* card1 = *(cards->getSingleCard(0));
    Card* card2 = *(cards->getSingleCard(1));
    this->setTheSkat(card1, card2);

    player1->setBlatt(cards->getSingleCard(2),cards->getSingleCard(11));
    player2->setBlatt(cards->getSingleCard(12),cards->getSingleCard(21));
    player3->setBlatt(cards->getSingleCard(22),cards->getSingleCard(31));
}

void Round::setTheSkat(Card* card1, Card* card2)
{
    theSkat.first  = card1;
    theSkat.second = card2;
}

void Round::activatePlayer(Player* s_activePlayer)
{
    activePlayer = s_activePlayer;
}

void Round::activateNextPlayer()
{
    if (activePlayer == player1) activePlayer = player2;
    else if (activePlayer == player2) activePlayer = player3;
    else if (activePlayer == player3) activePlayer = player1;
}

void Round::activatePreviousPlayer()
{
    if (activePlayer == player1) activePlayer = player3;
    else if (activePlayer == player2) activePlayer = player1;
    else if (activePlayer == player3) activePlayer = player2;
}

int Round::lastBid() const
{
    return Round::bidValues.at(biddenToIndex);
}
int Round::nextBid() const
{
    return Round::bidValues.at(biddenToIndex+1);
}
void Round::acceptNextBid()
{
    int maxBids = Round::bidValues.size();
    if( biddenToIndex < maxBids) ++biddenToIndex;
}
