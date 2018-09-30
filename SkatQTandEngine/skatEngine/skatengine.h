#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "skatEngine/skatenums.h"
#include "skatEngine/include/game.h"

#include <string>
#include <utility>
#include <vector>
namespace skatEngine{

class Controller
{
    static Controller ctrl;
    static bool isInitialized;
    Controller();
    Controller( const Controller& );
    const Controller& operator=( const Controller& );
    ~Controller();

    skatEngine::Game* theGame;

public:
    std::string toString() const;
    static Controller& getController();
    static void destroyController();

    void setPlayers(skatEngine::PlayerType, std::string, skatEngine::PlayerType, std::string,skatEngine::PlayerType, std::string);
    std::string getPlayerName(int playern /*1, 2 or 3*/);
    Icard getSkatCard(int cardn /* 1 or 2*/);
    Icard getPlayerCard(int playern/*1, 2 or 3*/, int cardn /*0-9*/);
    std::vector<Icard> getPlayerCards(int playern/*1, 2 or 3*/);

    void initNewRound();
    int biddenTo() const;
};
}
#endif // CONTROLLER_H
