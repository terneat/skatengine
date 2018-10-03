#ifndef RESULTCOLLECTOR_H
#define RESULTCOLLECTOR_H

#include <vector>

#include <Engine/include/iplayer.h>
#include <Engine/include/skatgamesetup.h>
#include <Engine/include/skatgameresult.h>

namespace cardGame{

    namespace skat{

        class ResultCollector
        {
            cardGame::IPlayer* player1;
            cardGame::IPlayer* player2;
            cardGame::IPlayer* player3;
            std::vector<GameResult> results;
            std::vector<GameSetup> setups;

        public:
            ResultCollector(cardGame::IPlayer* s_player1, cardGame::IPlayer* s_player2, cardGame::IPlayer* s_player3);
            ~ResultCollector();

            void addResult(GameResult result);
            void addSetup(GameSetup setup);

        };

        }
    }

#endif // RESULTCOLLECTOR_H

