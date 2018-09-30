#include "skatdecktest.h"

#include "../../SkatV2/Engine/include/skatdeck.h"


using namespace std;
using namespace cardGame;

TEST_F(SkatDeckTest, numberIs32) {


    skat::Deck* testdeck = new skat::Deck;

    vector<Card*> firstCard = testdeck->getCards(1,1);
    ASSERT_TRUE(firstCard.size() == 1);

    vector<Card*> allCards = testdeck->getCards(1,32);
    ASSERT_TRUE(allCards.size() == 32);

    delete testdeck;

}

TEST_F(SkatDeckTest, faultIndex) {


    skat::Deck* testdeck = new skat::Deck;
    vector<Card*> faultCards;


    faultCards = testdeck->getCards(0,1);
    ASSERT_TRUE(faultCards.size() == 0);

    faultCards = testdeck->getCards(1,34);
    ASSERT_TRUE(faultCards.size() == 0);

    faultCards = testdeck->getCards(12,8);
    ASSERT_TRUE(faultCards.size() == 0);


    delete testdeck;

}


TEST_F(SkatDeckTest, alldifferent) {


    skat::Deck* testdeck = new skat::Deck;

    vector<Card*> allCards = testdeck->getCards(1,32);

    for(vector<Card*>::const_iterator cardA=allCards.cbegin();cardA != allCards.cend()-1;++cardA)
    {
        for(vector<Card*>::const_iterator cardB=cardA+1;cardB != allCards.cend();++cardB)
        {
            ASSERT_FALSE((*cardA)->color == (*cardB)->color && (*cardA)->value == (*cardB)->value);
        }
    }

    delete testdeck;

}

TEST_F(SkatDeckTest, shuffle) {

    skat::Deck* testdeck = new skat::Deck;

    vector<Card*> cardsBeforeShuffle = testdeck->getCards(1,32);

    testdeck->shuffle();
    vector<Card*> cardsAfterShuffle = testdeck->getCards(1,32);
    ASSERT_FALSE(cardsBeforeShuffle == cardsAfterShuffle);

    testdeck->shuffle();
    vector<Card*> cardsAfterAnotherShuffle = testdeck->getCards(1,32);
    ASSERT_FALSE(cardsAfterAnotherShuffle == cardsAfterShuffle);
    ASSERT_FALSE(cardsAfterAnotherShuffle == cardsBeforeShuffle);

    delete testdeck;
}

TEST_F(SkatDeckTest, alldifferentAfterShuffle) {


    skat::Deck* testdeck = new skat::Deck;
    testdeck->shuffle();

    vector<Card*> allCards = testdeck->getCards(1,32);

    for(vector<Card*>::const_iterator cardA=allCards.cbegin();cardA != allCards.cend()-1;++cardA)
    {
        for(vector<Card*>::const_iterator cardB=cardA+1;cardB != allCards.cend();++cardB)
        {
            ASSERT_FALSE((*cardA)->color == (*cardB)->color && (*cardA)->value == (*cardB)->value);
        }
    }

    testdeck->shuffle();
    testdeck->shuffle();
    testdeck->shuffle();
    testdeck->shuffle();
    testdeck->shuffle();

    allCards = testdeck->getCards(1,32);

    for(vector<Card*>::const_iterator cardA=allCards.cbegin();cardA != allCards.cend()-1;++cardA)
    {
        for(vector<Card*>::const_iterator cardB=cardA+1;cardB != allCards.cend();++cardB)
        {
            ASSERT_FALSE((*cardA)->color == (*cardB)->color && (*cardA)->value == (*cardB)->value);
        }
    }

    delete testdeck;

}
