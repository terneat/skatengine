#ifndef STUB_H
#define STUB_H

#include <string>
#include <vector>
#include <Engine/include/card.h>
#include <Engine/include/skatgamesetup.h>
#include <Engine/include/skatgameresult.h>

#include <Engine/include/iplayer.h>

namespace cardGame{

    namespace skat{

        class StubPlayer : public IPlayer
        {

        public:
            StubPlayer(int s_Id, std::string s_name);
            virtual ~StubPlayer();

            virtual cardGame::Card* playCard(skat::GameSetup setup, skat::GameResult result);
            virtual bool makeBid(int lastBid, skat::GameSetup setup);
        };

        }
    }

#endif // STUB_H

