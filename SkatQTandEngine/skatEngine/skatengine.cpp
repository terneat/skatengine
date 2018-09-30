#include "skatEngine/skatengine.h"

#include <string>

skatEngine::Controller skatEngine::Controller::ctrl;
bool skatEngine::Controller::isInitialized = false;
skatEngine::Controller::Controller() : theGame(nullptr)
{

}

skatEngine::Controller::~Controller()
{

}

std::string skatEngine::Controller::toString() const
{

    std::string ctrlString = " Player1 is ";
    ctrlString.append( theGame->getName(1) );
    ctrlString.append( "\n Player2 is " );
    ctrlString.append( theGame->getName(2) );
    ctrlString.append( "\n Player3 is " );
    ctrlString.append( theGame->getName(3) );
    ctrlString.append( "\n" );


    return ctrlString;
}

skatEngine::Controller& skatEngine::Controller::getController()
{
    if( skatEngine::Controller::isInitialized == false )
    {
        skatEngine::Controller::isInitialized = true;
        skatEngine::Controller::ctrl.theGame = new skatEngine::Game;
    }

    return skatEngine::Controller::ctrl;

}

void skatEngine::Controller::destroyController()
{
    if( skatEngine::Controller::isInitialized == true )
    {
        delete skatEngine::Controller::ctrl.theGame;
        skatEngine::Controller::ctrl.~Controller();
        skatEngine::Controller::isInitialized = false;

    }
}

void skatEngine::Controller::setPlayers(skatEngine::PlayerType pt1, std::string name1, skatEngine::PlayerType pt2, std::string name2, skatEngine::PlayerType pt3, std::string name3)
{
    skatEngine::Controller::ctrl.theGame->addPlayer(pt1, name1);
    skatEngine::Controller::ctrl.theGame->addPlayer(pt2, name2);
    skatEngine::Controller::ctrl.theGame->addPlayer(pt3, name3);
}

std::string skatEngine::Controller::getPlayerName(int playern)
{
    if(playern<1 || playern > 3 || theGame->getNumberOfPlayers() != (int)3) return "<invalid>";
    else return theGame->getName(playern);

}


skatEngine::Icard skatEngine::Controller::getSkatCard(int cardn)
{
    if(theGame->getStage() == skatEngine::GameStage::PLAYING_ROUND)
    {

        return theGame->getRound()->getSkatCard_Enum(cardn);
    }

    return std::make_pair(skatEngine::ColorType::NO, skatEngine::ValueType::NO);
}

skatEngine::Icard skatEngine::Controller::getPlayerCard(int playern, int cardn)
{
    if(theGame->getStage() == skatEngine::GameStage::PLAYING_ROUND)
    {

        return theGame->getRound()->getPlayerCard_Enum(playern, cardn);
    }

    return std::make_pair(skatEngine::ColorType::NO, skatEngine::ValueType::NO);
}


std::vector<skatEngine::Icard> skatEngine::Controller::getPlayerCards(int playern/*1, 2 or 3*/)
{
    if(theGame->getStage() == skatEngine::GameStage::PLAYING_ROUND)
    {
      return theGame->getRound()->getPlayerCards_Enum(playern);
    }

    std::vector<skatEngine::Icard> ret(10,std::make_pair(skatEngine::ColorType::NO, skatEngine::ValueType::NO));
    return ret;
}

void skatEngine::Controller::initNewRound()
{
    theGame->startNewRound();
}

int skatEngine::Controller::biddenTo() const
{
    return theGame->biddenTo();
}
