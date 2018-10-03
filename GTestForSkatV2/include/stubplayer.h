#ifndef STUB_H
#define STUB_H

#include <string>
#include <vector>
#include <Engine/include/card.h>
#include <Engine/include/skatgamesetup.h>
#include <Engine/include/skatgameresult.h>

#include <Engine/include/iplayer.h>

        class StubPlayer : public cardGame::IPlayer
        {

        public:
            StubPlayer(int s_Id, std::string s_name);
            virtual ~StubPlayer();

            virtual cardGame::Card* playCard(cardGame::skat::GameSetup setup, cardGame::skat::GameResult result);
            virtual bool makeBid(int lastBid, cardGame::skat::GameSetup setup);
        };


#endif // STUB_H

