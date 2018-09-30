#include "skatEngine/include/cardset.h"

using namespace skatEngine;

CardSet::CardSet():rgen(new randgen)
{
    cards = new std::vector<Card*>(0);
    std::vector<ColorType> possibleCols = {ColorType::KARO, ColorType::HERZ, ColorType::PIK, ColorType::KREUZ};
    std::vector<ValueType> possibleVals = {ValueType::SIEBEN, ValueType::ACHT, ValueType::NEUN, ValueType::ZEHN, ValueType::BUBE, ValueType::DAME, ValueType::KOENIG, ValueType::ASS};

    for (auto const &col: possibleCols)
    {
        for (auto const &val :possibleVals)
        {
            cards->push_back(new Card(col, val));
        }
    }
    this->mixCards();
}

CardSet::~CardSet()
{
    delete rgen;
    for(auto card=cards->begin();card != cards->end(); ++card){ delete *card; }
    delete cards;
}

void CardSet::mixCards()
{

    int r1, r2, r3;
    Card* forSwap = nullptr;

    r3 = rgen->rand_int(200,500);

    for(int j=1;j<r3;++j)
    {
        r1 = rgen->rand_int(0,31);
        r2 = rgen->rand_int(0,31);
        if(r1!=r2)
        {

            forSwap = cards->at(r1);
            cards->at(r1) = cards->at(r2);
            cards->at(r2) = forSwap;

        }
    }
}

std::vector<Card*>::const_iterator CardSet::getSingleCard(int cn) const
{
    return cards->cbegin()+cn;
}
