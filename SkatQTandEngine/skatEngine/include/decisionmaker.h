#ifndef DECISIONMAKER_H
#define DECISIONMAKER_H

#include <vector>

/*
 * do different subclasses for null, grand, color!
 */

namespace skatEngine {


    class Card;
    class Trick;
    class RoundInfo;

    class DecisionMaker
    {
        DecisionMaker(int level, RoundInfo* s_roundInfo);
        ~DecisionMaker();

        skatEngine::Card* decide(Trick* currentTrick, std::vector<Trick*> playedTricks, std::vector<skatEngine::Card*> blatt);

    protected:
        int level;
        std::vector<Trick*> *playedTricks;
        std::vector<Card*> *blatt;
        RoundInfo* roundInfo;

        virtual skatEngine::Card* decideOnFirstCard() = 0;

        virtual skatEngine::Card* decideOnSecondCard(Card* firstPlayedCard) = 0;

        virtual skatEngine::Card* decideOnThirdCard(Card* firstPlayedCard, Card* secondPlayedCard) = 0;
    };

}
#endif // DECISIONMAKER_H

