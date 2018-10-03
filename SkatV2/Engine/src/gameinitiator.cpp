#include <Engine/include/gameinitiator.h>

using namespace cardGame;

skat::GameInitiator::GameInitiator(IPlayer* player1, IPlayer* player2, IPlayer* player3, int s_dealer, IDeck* s_deck):
    players(0), dealer(s_dealer), deck(s_deck)
{
    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);
    deck->shuffle();
}

skat::GameInitiator::~GameInitiator()
{

}
