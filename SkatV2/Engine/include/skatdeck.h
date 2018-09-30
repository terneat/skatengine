#ifndef SKAT_DECK_H
#define SKAT_DECK_H

#include <Engine/include/card.h>
#include <Engine/include/ideck.h>

namespace cardGame{

    namespace skat{

        class Deck : public IDeck
        {

            cardGame::Card* sevenOfDiamonds;
            cardGame::Card* eightOfDiamonds;
            cardGame::Card* nineOfDiamonds;
            cardGame::Card* tenOfDiamonds;
            cardGame::Card* jackOfDiamonds;
            cardGame::Card* queenOfDiamonds;
            cardGame::Card* kingOfDiamonds;
            cardGame::Card* aceOfDiamonds;

            cardGame::Card* sevenOfHearts;
            cardGame::Card* eightOfHearts;
            cardGame::Card* nineOfHearts;
            cardGame::Card* tenOfHearts;
            cardGame::Card* jackOfHearts;
            cardGame::Card* queenOfHearts;
            cardGame::Card* kingOfHearts;
            cardGame::Card* aceOfHearts;

            cardGame::Card* sevenOfSpades;
            cardGame::Card* eightOfSpades;
            cardGame::Card* nineOfSpades;
            cardGame::Card* tenOfSpades;
            cardGame::Card* jackOfSpades;
            cardGame::Card* queenOfSpades;
            cardGame::Card* kingOfSpades;
            cardGame::Card* aceOfSpades;

            cardGame::Card* sevenOfClubs;
            cardGame::Card* eightOfClubs;
            cardGame::Card* nineOfClubs;
            cardGame::Card* tenOfClubs;
            cardGame::Card* jackOfClubs;
            cardGame::Card* queenOfClubs;
            cardGame::Card* kingOfClubs;
            cardGame::Card* aceOfClubs;
        public:
            Deck();
            ~Deck();
            void shuffle();
            std::vector<cardGame::Card*> getCards(int, int) const;
        };

        }
    }

#endif

