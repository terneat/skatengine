#ifndef IPLAYER_H
#define IPLAYER_H

#include <string>
#include <vector>
#include <Engine/include/card.h>
#include <Engine/include/skatgamesetup.h>
#include <Engine/include/skatgameresult.h>

namespace cardGame{
    class IPlayer{

    protected:
        int Id;
        std::string name;
        std::vector<cardGame::Card*> cards;
        std::vector<bool> cardsPlayed;

        std::vector<cardGame::Card*> getAvailableCards();
        std::vector<cardGame::Card*> getPlayedCards();
    public:
        IPlayer(int s_Id, std::string s_name);
        virtual ~IPlayer();

        void receiveNewCards(std::vector<cardGame::Card*>);

        virtual cardGame::Card* playCard(skat::GameSetup setup, skat::GameResult result) = 0;
        virtual bool makeBid(int lastBid, skat::GameSetup setup) = 0;

    };

    }
#endif // IPLAYER_H

