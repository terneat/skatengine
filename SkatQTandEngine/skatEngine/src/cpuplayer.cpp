#include "skatEngine/include/cpuplayer.h"

using namespace skatEngine;

CpuPlayer::CpuPlayer(int s_number, std::string s_name):Player(s_number, s_name)
{

}

CpuPlayer::~CpuPlayer()
{
}

PlayerType CpuPlayer::getType()
{
    return PlayerType::CPU;
}
