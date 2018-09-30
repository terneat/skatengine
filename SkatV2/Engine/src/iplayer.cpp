#include <Engine/include/iplayer.h>

cardGame::IPlayer::IPlayer(int s_Id, std::string s_name) : Id(s_Id), name(s_name){}

cardGame::IPlayer::~IPlayer(){}

void cardGame::IPlayer::receiveNewCards(std::vector<cardGame::Card*> s_cards)
{
    cards = s_cards;
    cardsPlayed.resize(cards.size(), false);
}

std::vector<cardGame::Card*> cardGame::IPlayer::getAvailableCards()
{
    std::vector<cardGame::Card*> availableCards;

    std::vector<cardGame::Card*>::iterator cardToCheck = cards.begin();
    for(std::vector<bool>::iterator isplayed =cardsPlayed.begin();isplayed != cardsPlayed.end();++isplayed, ++cardToCheck )
    {
        if(!(*isplayed)) availableCards.push_back(*cardToCheck);
    }


    return availableCards;
}

std::vector<cardGame::Card*> cardGame::IPlayer::getPlayedCards()
{

    std::vector<cardGame::Card*> playedCards;

    std::vector<cardGame::Card*>::iterator cardToCheck = cards.begin();
    for(std::vector<bool>::iterator isplayed =cardsPlayed.begin();isplayed != cardsPlayed.end();++isplayed, ++cardToCheck )
    {
        if(*isplayed) playedCards.push_back(*cardToCheck);
    }

    return playedCards;

}
