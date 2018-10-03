#ifndef IDECK_H
#define IDECK_H

#include <Engine/include/card.h>
#include <Engine/include/random_numbers.h>
#include <vector>

namespace cardGame{


class IDeck{

protected:
    std::vector<cardGame::Card*> cards;
    randgen* randomNumberGenerator;

public:

    IDeck():cards(0), randomNumberGenerator(new randgen){}
    virtual ~IDeck(){delete randomNumberGenerator;}
    virtual void shuffle()=0;
    virtual std::vector<cardGame::Card*> getCards(int from, int to) const = 0;

};

}

#endif // IDECK_H

