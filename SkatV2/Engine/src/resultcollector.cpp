#include <Engine/include/resultcollector.h>

cardGame::skat::ResultCollector::ResultCollector(cardGame::IPlayer* s_player1, cardGame::IPlayer* s_player2, cardGame::IPlayer* s_player3)
    : player1(s_player1), player2(s_player2), player3(s_player3), results(0), setups(0)
{

}

cardGame::skat::ResultCollector::~ResultCollector()
{

}

void cardGame::skat::ResultCollector::addResult(cardGame::skat::GameResult result)
{
    results.push_back(result);
}

void cardGame::skat::ResultCollector::addSetup(cardGame::skat::GameSetup setup)
{
 setups.push_back(setup);
}
