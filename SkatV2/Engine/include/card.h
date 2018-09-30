#ifndef CARD_H
#define CARD_H


namespace cardGame
{

enum class ColorType {NO, DIAMONDS, HEARTS, SPADES, CLUBS};
enum class ValueType  {NO, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, JACK, QUEEN, KING, TEN, ACE};

class Card
{

public:
    Card(ColorType s_color, ValueType s_value):color(s_color), value(s_value){}

    ColorType color;
    ValueType value;

    static int getPoints(Card* card){
        if(card->value == cardGame::ValueType::ACE) return 11;
        if(card->value == cardGame::ValueType::TEN) return 10;
        if(card->value == cardGame::ValueType::KING) return 4;
        if(card->value == cardGame::ValueType::QUEEN) return 3;
        if(card->value == cardGame::ValueType::JACK) return 2;
        return 0;
    }

};

}

#endif // CARD_H

