#include "../include/stubplayer.h"

StubPlayer::StubPlayer(int s_Id, std::string s_name): cardGame::IPlayer(s_Id, s_name)
{
}

StubPlayer::~StubPlayer()
{

}

cardGame::Card* StubPlayer::playCard(cardGame::skat::GameSetup setup, cardGame::skat::GameResult result)
{
 return cards.at(0);
}

bool StubPlayer::makeBid(int lastBid, cardGame::skat::GameSetup setup)
{
 if(lastBid<24) return true;
 return false;
}
