#include "skatEngine/include/humanplayer.h"

using namespace skatEngine;


HumanPlayer::HumanPlayer(int s_number, std::string s_name):Player(s_number, s_name)
{

}

HumanPlayer::~HumanPlayer()
{

}

PlayerType HumanPlayer::getType()
{
    return PlayerType::HUMAN;
}
