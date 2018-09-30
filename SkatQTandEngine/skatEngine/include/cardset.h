#ifndef CARDSET_H
#define CARDSET_H

#include "skatEngine/skatenums.h"
#include "skatEngine/include/random_numbers.h"
#include "skatEngine/include/card.h"

#include <vector>
namespace skatEngine {

class CardSet{

    std::vector<skatEngine::Card*> *cards;
    randgen* rgen;
public:
    CardSet();
    ~CardSet();

    void mixCards();
    std::vector<skatEngine::Card*>::const_iterator getSingleCard(int) const;

};

}
#endif // CARDSET_H

