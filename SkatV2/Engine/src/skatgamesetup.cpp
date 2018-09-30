#include "Engine/include/skatgamesetup.h"

cardGame::skat::GameSetup::GameSetup(int idPlayer1, int idPlayer2, int idPlayer3) :
    gameType(cardGame::skat::GameType::NO), hand(false), schneider(false), schwarz(false), ouvert(false), IdRePlayer(-1)
{

    firstPlayerBid  = {idPlayer1, 0};
    secondPlayerBid = {idPlayer2, 0};
    thirdPlayerBid  = {idPlayer3, 0};
}

cardGame::skat::GameSetup::~GameSetup()
{

}

void cardGame::skat::GameSetup::setBid(int s_playerId, int s_biddenTo)
{
if(firstPlayerBid.playerId == s_playerId) firstPlayerBid.biddenTo = s_biddenTo;
if(secondPlayerBid.playerId == s_playerId) secondPlayerBid.biddenTo = s_biddenTo;
if(thirdPlayerBid.playerId == s_playerId) thirdPlayerBid.biddenTo = s_biddenTo;
}

int cardGame::skat::GameSetup::getBid(int s_playerId) const
{
    if(firstPlayerBid.playerId == s_playerId) return firstPlayerBid.biddenTo;
    if(secondPlayerBid.playerId == s_playerId) return secondPlayerBid.biddenTo;
    if(thirdPlayerBid.playerId == s_playerId) return thirdPlayerBid.biddenTo;
    return 0;
}

void cardGame::skat::GameSetup::setGameChoice(GameType s_gametype, bool isHand, bool isSchneider, bool isSchwarz, bool isOuvert)
{

    gameType = s_gametype;
    hand = isHand;
    schneider = isSchneider;
    schwarz = isSchwarz;
    ouvert = isOuvert;

}

void cardGame::skat::GameSetup::setIdRePlayer(int s_IdRePlayer)
{
    IdRePlayer = s_IdRePlayer;
}

int cardGame::skat::GameSetup::getIdRePlayer()const
{
    return IdRePlayer;
}

cardGame::skat::GameType cardGame::skat::GameSetup::getGameType() const
{
    return gameType;
}

bool cardGame::skat::GameSetup::isHand() const
{
    return hand;
}

bool cardGame::skat::GameSetup::isSchneider() const
{
    return schneider;
}

bool cardGame::skat::GameSetup::isSchwarz() const
{
    return schwarz;
}

bool cardGame::skat::GameSetup::isOuvert() const
{
    return ouvert;
}
