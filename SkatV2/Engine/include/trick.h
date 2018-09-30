#ifndef TRICK_H
#define TRICK_H

#include "Engine/include/card.h"
#include <vector>


namespace cardGame{

    class Trick
    {

        int numberOfPlayers;
        std::vector<Card*> cardsPlayed;
        std::vector<int> playerIds;

    public:
        explicit Trick(int s_numberOfPlayers);
        ~Trick();
        void addCard(Card* card, int playerId);
        int getNumberOfPlayedCards() const;
        int getPoints() const;
        Card* getCard(int index) const;
        int getPlayerId(int index) const;
    };

    }
#endif // TRICK_H

