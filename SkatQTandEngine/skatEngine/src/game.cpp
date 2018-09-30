#include "skatEngine/include/game.h"

#include "skatEngine/include/cardset.h"
#include "skatEngine/include/humanplayer.h"
#include "skatEngine/include/cpuplayer.h"

using namespace skatEngine;

Game::Game() :
    player1(nullptr),player2(nullptr), player3(nullptr),
    cards(new skatEngine::CardSet),round(nullptr),
    playedRounds(std::vector<Round*>(0)), numberOfPlayers(0), stage(skatEngine::GameStage::INITIALIZED),
    nextGeber(nullptr)
{

}

Game::~Game()
{
    delete cards;
    if (player1 != nullptr) { delete player1; player1 = nullptr;}
    if (player2 != nullptr) { delete player2; player2 = nullptr;}
    if (player3 != nullptr) { delete player3; player3 = nullptr;}
    if (round != nullptr)   { delete round; round = nullptr;}
    for(std::vector<Round*>::iterator rit = playedRounds.begin();rit!=playedRounds.end();++rit)
    {
        delete *rit;
    }
}

void Game::addPlayer(skatEngine::PlayerType type, std::string name)
{
    if(numberOfPlayers < 3)
    {

      numberOfPlayers++;
      if(numberOfPlayers == 1) {player1 = createPlayer(numberOfPlayers, name, type );nextGeber = player1;}
      else if(numberOfPlayers == 2)player2 = createPlayer(numberOfPlayers, name, type );
      else if(numberOfPlayers == 3)player3 = createPlayer(numberOfPlayers, name, type );

    }
}

skatEngine::Player* Game::createPlayer(int pNumber, std::string name, skatEngine::PlayerType type)
{
    Player* newPlayer = nullptr;

    if(type == skatEngine::PlayerType::HUMAN) newPlayer = new HumanPlayer(pNumber, name);
    else if(type == skatEngine::PlayerType::CPU) newPlayer = new CpuPlayer(pNumber, name);

    return newPlayer;
}

void Game::startNewRound()
{
    if(round!=nullptr)
    {
        round->setStage(skatEngine::RoundStage::FINSISHED);
        playedRounds.push_back(round);
    }

    round = new Round(player1, player2, player3, cards, getNextGeber());
    stage = skatEngine::GameStage::PLAYING_ROUND;
}

std::vector<Icard> Game::getPlayerCards(int playern)
{

    if(stage == skatEngine::GameStage::PLAYING_ROUND)
        return round->getPlayerCards_Enum(playern);
    else
        return std::vector<Icard>(0);
}

int Game::biddenTo() const
{
    int bid = 0;
    if(round!=nullptr)
    {
        bid = round->lastBid();
    }
    return bid;
}

Player* Game::getNextGeber()
{
    Player* nextG = nextGeber;
    if (nextG == player1) nextGeber = player2;
    else if (nextG == player2) nextGeber = player3;
    else if (nextG == player3) nextGeber = player1;
    return nextG;
}

std::string Game::getName(int pln)
{
    std::string name ="";

    if (pln == 1) name = player1->getName();
    else if (pln == 2) name = player2->getName();
    else if (pln == 3) name = player3->getName();

    return name;
}

