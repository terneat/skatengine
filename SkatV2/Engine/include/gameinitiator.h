#ifndef GAMEINITIATOR_H
#define GAMEINITIATOR_H

#include <vector>
#include <Engine/include/iplayer.h>
#include <Engine/include/ideck.h>
#include <Engine/include/random_numbers.h>

namespace cardGame{

    namespace skat{

        class GameInitiator
        {
            std::vector<cardGame::IPlayer* const> players;
            int dealer;
            cardGame::IDeck* deck;

        public:

            GameInitiator(IPlayer* player1, IPlayer* player2, IPlayer* player3, int_dealer, IDeck* s_deck);
            ~GameInitiator();
        };

        }
    }

#endif // GAMEINITIATOR_H

