#include "skatEngine/include/decisionmaker.h"

#include "skatEngine/include/card.h"
#include "skatEngine/include/trick.h"

skatEngine::DecisionMaker::DecisionMaker(int level, RoundInfo* s_roundInfo):level(level),playedTricks(nullptr), blatt(nullptr), roundInfo(s_roundInfo)
{

}

skatEngine::DecisionMaker::~DecisionMaker()
{

}


skatEngine::Card* skatEngine::DecisionMaker::decide(skatEngine::Trick* currentTrick, std::vector<skatEngine::Trick*> playedTricks, std::vector<skatEngine::Card*> blatt)
{
    Card *firstPlayedCard, *secondPlayedCard, *thirdPlayedCard = nullptr;

    this->playedTricks = &playedTricks;
    this->blatt = &blatt;

    currentTrick->getPlayedCards(firstPlayedCard, secondPlayedCard, thirdPlayedCard);

    if(firstPlayedCard==nullptr)
        return decideOnFirstCard();

    else if(secondPlayedCard==nullptr)
        return decideOnSecondCard(firstPlayedCard);

    else
        return decideOnThirdCard(firstPlayedCard, secondPlayedCard);


}

skatEngine::Card* skatEngine::DecisionMaker::decideOnFirstCard()
{
    return nullptr;
}

skatEngine::Card* skatEngine::DecisionMaker::decideOnSecondCard(Card* firstPlayedCard)
{
    return nullptr;
}

skatEngine::Card* skatEngine::DecisionMaker::decideOnThirdCard(Card* firstPlayedCard, Card* secondPlayedCard)
{
    return nullptr;
}
