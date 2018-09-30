#ifndef CPUPLAYER_H
#define CPUPLAYER_H

#include "skatEngine/include/player.h"

namespace skatEngine {

class CpuPlayer:public skatEngine::Player
{
public:
    CpuPlayer(int, std::string);
    ~CpuPlayer();
    skatEngine::PlayerType getType() final;
};

}
#endif // CPUPLAYER_H

