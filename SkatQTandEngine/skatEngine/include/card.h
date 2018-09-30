#ifndef CARD_H
#define CARD_H

#include "skatEngine/skatenums.h"

namespace skatEngine {

class Card{

skatEngine::ColorType ccol;
skatEngine::ValueType  ctyp;

public:
    Card(skatEngine::ColorType s_ccol = skatEngine::ColorType::NO, skatEngine::ValueType s_ctyp = skatEngine::ValueType::ASS);

    int getPoints() const;
    skatEngine::ValueType getValue() const;
    skatEngine::ColorType getColor() const;
    Icard toEnumPair() const;


};

}
#endif // CARD_H

