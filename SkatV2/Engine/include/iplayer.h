#ifndef IPLAYER_H
#define IPLAYER_H

#include <string>
#include <vector>
#include <Engine/include/card.h>

namespace cardGame{
    class IPlayer{
    private:
        //#ifdef UNIT_TEST
        friend class IPlayerTest_protectedmethods_Test;

        //#endif

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

    };

    }
#endif // IPLAYER_H

