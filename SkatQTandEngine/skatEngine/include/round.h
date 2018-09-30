#ifndef ROUND_H
#define ROUND_H

#include "skatEngine/skatenums.h"

#include <vector>

namespace skatEngine{

class Trick;
class Card;
class Player;
class CardSet;
class Round{

    static std::vector<int> bidValues;

    Player* player1;
    Player* player2;
    Player* player3;
    CardSet* cards;
    Player* geber;
    Player* activePlayer;

    skatEngine::RoundStage stage;

    std::pair<Card*, Card*> theSkat;
    Trick* currentTrick;
    std::vector<skatEngine::Trick*> TricksInRound;
    int tricksPlayed;
    int biddenToIndex;

public:
    Round(Player*, Player*, Player*, CardSet*, Player*);
    ~Round();
    void setStage(skatEngine::RoundStage s_stage){ stage = s_stage; }
    skatEngine::RoundStage getStage() const{ return stage; }
    skatEngine::Card* getSkatCard(int);
    Icard getSkatCard_Enum(int);
    skatEngine::Card* getPlayerCard(int, int);
    Icard getPlayerCard_Enum(int, int);
    std::vector<Icard> getPlayerCards_Enum(int);

    int lastBid() const;
    int nextBid() const;
    void acceptNextBid();


private:
    void distributeCards();
    void setTheSkat(Card *card1, Card *card2);
    void activatePlayer(Player*);
    void activateNextPlayer();
    void activatePreviousPlayer();
};

}
#endif // ROUND_H

