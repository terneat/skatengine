#include "Player/include/stub.h"

using namespace cardGame::skat;

StubPlayer::StubPlayer(int s_Id, std::string s_name):cardGame::IPlayer(s_Id, s_name)
{
}

StubPlayer::~StubPlayer()
{

}

cardGame::Card* StubPlayer::playCard(GameSetup setup, GameResult result)
{
 return cards.at(0);
}

bool StubPlayer::makeBid(int lastBid, GameSetup setup)
{
 if(lastBid<24) return true;
 return false;
}
