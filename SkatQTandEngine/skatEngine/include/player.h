#ifndef PLAYER_H
#define PLAYER_H

#include "skatEngine/include/card.h"

#include <string>
#include <vector>

namespace skatEngine
{

class Player
{
protected:
    std::vector<skatEngine::Card*> blatt;
    int number;
    int points;
    std::string name;

public:
    Player(int, std::string);
    virtual ~Player();
    virtual skatEngine::PlayerType getType() =0;

    void setBlatt(std::vector<Card*>::const_iterator, std::vector<Card*>::const_iterator);
    std::string getName() const;
    void setName(std::string);
    skatEngine::Card* getSingleCard(int);

};

}


#endif // PLAYER_H

