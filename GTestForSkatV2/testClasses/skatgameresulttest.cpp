#include "skatgameresulttest.h"

#include "../../SkatV2/Engine/include/skatgameresult.h"
#include "../../SkatV2/Engine/include/trick.h"


using namespace std;
using namespace cardGame;

TEST_F(SkatGameResultTest, repoints) {
  
skat::GameResult* result = new skat::GameResult(12);

Card* card1 = new Card(ColorType::DIAMONDS, ValueType::KING);
Card* card2 = new Card(ColorType::SPADES, ValueType::JACK);
Card* card3 = new Card(ColorType::HEARTS, ValueType::EIGHT);
Trick t1(3);t1.addCard(card1, 12);t1.addCard(card2, 24);t1.addCard(card3, 36);

result->addTrick(t1, 12);

int repoints = result->getPointsRePlayer();
ASSERT_EQ(repoints, 6);

int kontrapoints = result->getPointsKontraPlayers();
ASSERT_EQ(kontrapoints, 0);


Trick t2(3);t2.addCard(card1, 12);t2.addCard(card2, 24);t2.addCard(card3, 36);

result->addTrick(t2, 24);
repoints = result->getPointsRePlayer();
ASSERT_EQ(repoints, 6);

kontrapoints = result->getPointsKontraPlayers();
ASSERT_EQ(kontrapoints, 6);

Trick t3(3);t3.addCard(card1, 12);t3.addCard(card2, 24);t3.addCard(card3, 36);

result->addTrick(t3, 24);
repoints = result->getPointsRePlayer();
ASSERT_EQ(repoints, 6);

kontrapoints = result->getPointsKontraPlayers();
ASSERT_EQ(kontrapoints, 12);

Trick t4(3);t4.addCard(card1, 12);t4.addCard(card2, 24);t4.addCard(card3, 36);

result->addTrick(t3, 12);
repoints = result->getPointsRePlayer();
ASSERT_EQ(repoints, 12);

kontrapoints = result->getPointsKontraPlayers();
ASSERT_EQ(kontrapoints, 12);



delete card1;
delete card2;
delete card3;

delete result;
}
