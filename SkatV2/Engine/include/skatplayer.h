#ifndef SKATPLAYER_H
#define SKATPLAYER_H

#include <vector>
#include <Engine/include/card.h>
#include <Engine/include/iplayer.h>

namespace cardGame{
    namespace skat{

        class SkatPlayer : public cardGame::IPlayer{

        protected:


        public:
            SkatPlayer(int s_Id, string s_name);
            ~SkatPlayer();

        };
        }
    }
#endif // ISKATPLAYER_H

