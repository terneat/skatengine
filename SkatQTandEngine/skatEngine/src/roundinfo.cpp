#include "skatEngine/include/roundinfo.h"

skatEngine::RoundInfo::RoundInfo():player1bid(0), player2bid(0), player3bid(0),
    handGame(false),ouvertGame(false),
    typeOfGame(skatEngine::GameType::UNDEFINED),
    colorOfGame(skatEngine::ColorType::NO)
{

}

skatEngine::RoundInfo::~RoundInfo()
{

}

void skatEngine::RoundInfo::setBids(int playernr, int bid1, int bid2, int bid3)
{
    player = playernr;
    player1bid = bid1;
    player2bid = bid2;
    player3bid = bid3;
}

void skatEngine::RoundInfo::setGame(GameType s_typeOfGame, ColorType s_colorOfGame, bool isHand, bool isOuvert)
{
    colorOfGame = s_colorOfGame;
    typeOfGame = s_typeOfGame;
    handGame = isHand;
    ouvertGame = isOuvert;
}
