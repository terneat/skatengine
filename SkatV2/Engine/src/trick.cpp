#include "Engine/include/trick.h"

cardGame::Trick::Trick(int s_numberOfPlayers):numberOfPlayers(s_numberOfPlayers)
{

}

cardGame::Trick::~Trick()
{

}

void cardGame::Trick::addCard(Card* card, int playerId)
{

    cardsPlayed.push_back(card);
    playerIds.push_back(playerId);

}

int cardGame::Trick::getNumberOfPlayedCards() const
{

    return cardsPlayed.size();

}

cardGame::Card* cardGame::Trick::getCard(int index) const
{
    Card* card = nullptr;
    if(index>0 && index<=cardsPlayed.size())
        card = cardsPlayed.at(index-1);

    return card;
}

int cardGame::Trick::getPlayerId(int index) const
{
    int playerId = -1;
    if(index>0 && index<=playerIds.size())
        playerId = playerIds.at(index-1);

    return playerId;

}

int cardGame::Trick::getPoints() const
{
    int points = 0;
    for(std::vector<cardGame::Card*>::const_iterator card = cardsPlayed.cbegin();card!=cardsPlayed.cend();++card)
        points += cardGame::Card::getPoints(*card);

    return points;
}
