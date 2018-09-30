#include "Engine/include/skatgameresult.h"

cardGame::skat::GameResult::GameResult(int s_RePlayerId):RePlayerId(s_RePlayerId)
{

}

cardGame::skat::GameResult::~GameResult()
{

}

void cardGame::skat::GameResult::addTrick(cardGame::Trick trick, int IdWinnerOfTrick)
{

    tricks.push_back(trick);
    playerIdsOfTrickWinner.push_back(IdWinnerOfTrick);

}

int cardGame::skat::GameResult::getPointsRePlayer() const
{

    int points = 0;

    std::vector<cardGame::Trick>::const_iterator trick = tricks.cbegin();
    for(std::vector<int>::const_iterator trickWinnerId = playerIdsOfTrickWinner.cbegin();trickWinnerId != playerIdsOfTrickWinner.cend();++trick, ++trickWinnerId)
    {
        if(*trickWinnerId == RePlayerId)
        {
            points+=trick->getPoints();
        }
    }

    return points;
}

int cardGame::skat::GameResult::getPointsKontraPlayers() const
{
    int points = 0;

    std::vector<cardGame::Trick>::const_iterator trick = tricks.cbegin();
    for(std::vector<int>::const_iterator trickWinnerId = playerIdsOfTrickWinner.cbegin();trickWinnerId != playerIdsOfTrickWinner.cend();++trick, ++trickWinnerId)
    {
        if(*trickWinnerId != RePlayerId)
        {
            points+=trick->getPoints();
        }
    }

    return points;
}
