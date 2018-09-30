#include "skatEngine/include/player.h"

using namespace skatEngine;

Player::Player(int s_number, std::string s_name)
    :blatt(std::vector<skatEngine::Card*>(10)), number(s_number), points(0), name(s_name)
{

}

Player::~Player()
{

}

void Player::setBlatt(std::vector<Card*>::const_iterator it1, std::vector<Card*>::const_iterator it2)
{
    std::vector<skatEngine::Card*>::iterator itfill = blatt.begin();
    while(it1!=it2)
    {
        *itfill = *it1;
        ++it1;
        ++itfill;
    }
    *itfill = *it1;
}


std::string Player::getName() const
{
    return this->name;
}

void Player::setName(std::string s_name)
{
    this-> name = s_name;
}

Card* Player::getSingleCard(int cardn)
{
    if( cardn >= 0 && cardn <= 9) return blatt.at(cardn);
    return nullptr;
}
