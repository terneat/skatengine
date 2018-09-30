#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "skatEngine/include/player.h"

namespace skatEngine {

class HumanPlayer:public skatEngine::Player
{
public:
    HumanPlayer(int, std::string);
    ~HumanPlayer();
    skatEngine::PlayerType getType() final;
};

}
#endif // HUMANPLAYER_H

