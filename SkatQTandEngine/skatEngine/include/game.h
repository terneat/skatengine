#ifndef GAME_H
#define GAME_H

#include "skatEngine/include/cardset.h"
#include "skatEngine/include/player.h"
#include "skatEngine/include/round.h"

#include <string>
#include <utility>
#include <vector>

namespace skatEngine
{

class Game
{

Player* player1;
Player* player2;
Player* player3;
CardSet* cards;
Round* round;
std::vector<Round*> playedRounds;

int numberOfPlayers;
skatEngine::GameStage stage;
Player* nextGeber;

public:
    Game();
    ~Game();

public: /* methods */
    void addPlayer(skatEngine::PlayerType, std::string);
    std::string getName(int);
    skatEngine::GameStage getStage() const{ return stage; }
    void setStage(skatEngine::GameStage s_stage) { stage = s_stage; }
    skatEngine::Round* getRound() const{ return round; }
    int getNumberOfPlayers() const{return numberOfPlayers;}
    void startNewRound();
    int biddenTo() const;
    std::vector<Icard> getPlayerCards(int);
private: /* methods */
    skatEngine::Player *createPlayer(int, std::string name, skatEngine::PlayerType);

    Player* getNextGeber();

};

}
#endif // GAME_H

