#ifndef SKATGAMESETUP_H
#define SKATGAMESETUP_H

namespace cardGame{

    namespace skat{

        enum class GameType {NO, DIAMONDS, HEARTS, SPADES, CLUBS, GRAND, NULLG};

        struct Bid
        {
            int playerId;
            int biddenTo;

        };

        class GameSetup{

            GameType gameType;
            bool hand;
            bool schneider;
            bool schwarz;
            bool ouvert;
            int IdRePlayer;

            Bid firstPlayerBid;
            Bid secondPlayerBid;
            Bid thirdPlayerBid;

        public:

            GameSetup(int idPlayer1, int idPlayer2, int idPlayer3);
            ~GameSetup();

            void setBid(int s_playerId, int s_biddenTo);
            int getBid(int s_playerId) const;
            void setGameChoice(GameType s_gametype, bool isHand=false, bool isSchneider=false, bool isSchwarz=false, bool isOuvert=false);
            void setIdRePlayer(int s_IdRePlayer);
            int getIdRePlayer()const;

            GameType getGameType() const;
            bool isHand() const;
            bool isSchneider() const;
            bool isSchwarz() const;
            bool isOuvert() const;
        };

        }
    }
#endif // SKATGAMESETUP_H

