#ifndef SKATGAMERESULT_H
#define SKATGAMERESULT_H

#include "Engine/include/trick.h"
#include <vector>

namespace cardGame{

    namespace skat{

        class GameResult
        {

            int RePlayerId;

            std::vector<cardGame::Trick> tricks;
            std::vector<int> playerIdsOfTrickWinner;

        public:
            explicit GameResult(int s_RePlayerId);
            ~GameResult();
            void addTrick(cardGame::Trick trick, int IdWinnerOfTrick);
            int getPointsRePlayer() const;
            int getPointsKontraPlayers() const;

        };

        }
    }
#endif // SKATGAMERESULT_H

