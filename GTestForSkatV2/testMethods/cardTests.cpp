
#include "../SkatV2/Engine/include/card.h"

#include <gtest/gtest.h>

using namespace cardGame;
TEST (cardTest, points) {

    int points;

    Card king(ColorType::CLUBS, ValueType::KING);
    points = Card::getPoints(&king);
    ASSERT_EQ(points, 4);

    king.color = ColorType::HEARTS;
    points = Card::getPoints(&king);
    ASSERT_EQ(points, 4);

    Card queen(ColorType::DIAMONDS, ValueType::QUEEN);
    points = Card::getPoints(&queen);
    ASSERT_EQ(points, 3);

    Card jack(ColorType::HEARTS, ValueType::JACK);
    points = Card::getPoints(&jack);
    ASSERT_EQ(points, 2);

    Card ten(ColorType::HEARTS, ValueType::TEN);
    points = Card::getPoints(&ten);
    ASSERT_EQ(points, 10);

    Card ace(ColorType::CLUBS, ValueType::ACE);
    points = Card::getPoints(&ace);
    ASSERT_EQ(points, 11);

    Card seven(ColorType::SPADES, ValueType::SEVEN);
    points = Card::getPoints(&seven);
    ASSERT_EQ(points, 0);

    Card eight(ColorType::CLUBS, ValueType::EIGHT);
    points = Card::getPoints(&eight);
    ASSERT_EQ(points, 0);

    Card nine(ColorType::DIAMONDS, ValueType::NINE);
    points = Card::getPoints(&nine);
    ASSERT_EQ(points, 0);


}
