#ifndef ROUNDINFO
#define ROUNDINFO

#include "skatEngine/skatenums.h"

namespace skatEngine
{

class RoundInfo
{

    RoundInfo();
    ~RoundInfo();

    void setBids(int playernr, int bid1, int bid2, int bid3);
    void setGame(GameType s_typeOfGame, ColorType s_colorOfGame, bool isHand = false,  bool isOuvert = false);

private:
    int player;
    bool handGame;
    bool ouvertGame;
    skatEngine::GameType typeOfGame;
    skatEngine::ColorType colorOfGame;
    int player1bid;
    int player2bid;
    int player3bid;

};

}
#endif // ROUNDINFO

