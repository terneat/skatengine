#ifndef TRICK_H
#define TRICK_H

namespace skatEngine{

class Card;

class Trick{
public:
    Trick();
    ~Trick();

    void addCard(Card* nextCard);
    void getPlayedCards(Card* firstPlayedCard, Card* secondPlayedCard, Card* thirdPlayedCard);

private:
    int cardsPlayed;
    Card* firstCard;
    Card* secondCard;
    Card* thirdCard;

};

}

#endif // TRICK_H

