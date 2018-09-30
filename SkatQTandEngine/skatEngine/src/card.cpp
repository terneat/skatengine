#include "skatEngine/include/card.h"

using namespace skatEngine;

Card::Card(skatEngine::ColorType s_ccol, skatEngine::ValueType s_ctyp): ccol(s_ccol), ctyp(s_ctyp)
{

}

int Card::getPoints() const
{
    int value = 0;

    if( this->ctyp == ValueType::BUBE) value = 2;
    else if ( this->ctyp == ValueType::DAME) value = 3;
    else if ( this->ctyp == ValueType::KOENIG) value = 4;
    else if ( this->ctyp == ValueType::ZEHN) value = 10;
    else if ( this->ctyp == ValueType::ASS) value = 11;

    return value;
}

ValueType Card::getValue() const
{
    return this->ctyp;
}

ColorType Card::getColor() const
{
    return this->ccol;
}

Icard Card::toEnumPair() const
{
    return std::make_pair(ccol, ctyp);
}


