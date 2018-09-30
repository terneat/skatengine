#include "tricktest.h"

#include "../../SkatV2/Engine/include/trick.h"


using namespace std;
using namespace cardGame;

TEST_F(TrickTest, addCards) {
	
    Trick* firstTrick = new Trick(3);
    Card* card1 = new Card(ColorType::CLUBS, ValueType::NINE);
    Card* card2 = new Card(ColorType::CLUBS, ValueType::TEN);
    Card* card3 = new Card(ColorType::CLUBS, ValueType::ACE);

    int cardsPlayed;

    cardsPlayed = firstTrick->getNumberOfPlayedCards();
    ASSERT_EQ(cardsPlayed, 0);

    firstTrick->addCard(card1, 1);
    cardsPlayed = firstTrick->getNumberOfPlayedCards();
    ASSERT_EQ(cardsPlayed, 1);

    firstTrick->addCard(card2, 2);
    cardsPlayed = firstTrick->getNumberOfPlayedCards();
    ASSERT_EQ(cardsPlayed, 2);

    firstTrick->addCard(card3, 3);
    cardsPlayed = firstTrick->getNumberOfPlayedCards();
    ASSERT_EQ(cardsPlayed, 3);

    delete card1;
    delete card2;
    delete card3;
	delete firstTrick;


}


TEST_F(TrickTest, getCards) {

    Trick* firstTrick = new Trick(3);
    Card* card1 = new Card(ColorType::DIAMONDS, ValueType::KING);
    Card* card2 = new Card(ColorType::SPADES, ValueType::JACK);
    Card* card3 = new Card(ColorType::HEARTS, ValueType::EIGHT);

    Card* returnedCard;
    int playerId;

    firstTrick->addCard(card1, 12);
    returnedCard = firstTrick->getCard(1);
    playerId = firstTrick->getPlayerId(1);
    ASSERT_EQ(returnedCard, card1);
    ASSERT_EQ(playerId, 12);

    firstTrick->addCard(card2, 27);
    returnedCard = firstTrick->getCard(1);
    playerId = firstTrick->getPlayerId(1);
    ASSERT_EQ(returnedCard, card1);
    ASSERT_EQ(playerId, 12);
    returnedCard = firstTrick->getCard(2);
    playerId = firstTrick->getPlayerId(2);
    ASSERT_EQ(returnedCard, card2);
    ASSERT_EQ(playerId, 27);


    firstTrick->addCard(card3, 3);
    returnedCard = firstTrick->getCard(1);
    playerId = firstTrick->getPlayerId(1);
    ASSERT_EQ(returnedCard, card1);
    ASSERT_EQ(playerId, 12);
    returnedCard = firstTrick->getCard(2);
    playerId = firstTrick->getPlayerId(2);
    ASSERT_EQ(returnedCard, card2);
    ASSERT_EQ(playerId, 27);
    returnedCard = firstTrick->getCard(3);
    playerId = firstTrick->getPlayerId(3);
    ASSERT_EQ(returnedCard, card3);
    ASSERT_EQ(playerId, 3);

    returnedCard = firstTrick->getCard(4);
    playerId = firstTrick->getPlayerId(4);
    ASSERT_EQ(returnedCard, nullptr);
    ASSERT_EQ(playerId, -1);

    returnedCard = firstTrick->getCard(0);
    playerId = firstTrick->getPlayerId(0);
    ASSERT_EQ(returnedCard, nullptr);
    ASSERT_EQ(playerId, -1);

    delete card1;
    delete card2;
    delete card3;
    delete firstTrick;


}


TEST_F(TrickTest, getPoints) {

    int points = 0;

    Trick* trick = new Trick(3);
    Card* card1 = new Card(ColorType::DIAMONDS, ValueType::KING);
    Card* card2 = new Card(ColorType::SPADES, ValueType::JACK);
    Card* card3 = new Card(ColorType::HEARTS, ValueType::EIGHT);


    trick->addCard(card1, 12);
    trick->addCard(card2, 13);
    trick->addCard(card3, 14);

    points = trick->getPoints();
    ASSERT_EQ(points, 6);

    card1->value = ValueType::ACE;
    points = trick->getPoints();
    ASSERT_EQ(points, 13);

    card1->value = ValueType::SEVEN;
    points = trick->getPoints();
    ASSERT_EQ(points, 2);

    card2->value = ValueType::NINE;
    points = trick->getPoints();
    ASSERT_EQ(points, 0);

    card1->value = ValueType::ACE;
    card2->value = ValueType::TEN;
    card3->value = ValueType::TEN;
    points = trick->getPoints();
    ASSERT_EQ(points, 31);

    delete card1;
    delete card2;
    delete card3;
    delete trick;
}
