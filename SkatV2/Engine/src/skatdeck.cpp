#include <Engine/include/skatdeck.h>


cardGame::skat::Deck::Deck():IDeck()
{

    sevenOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::SEVEN);
    cards.push_back(sevenOfDiamonds);

    eightOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::EIGHT);
    cards.push_back(eightOfDiamonds);

    nineOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::NINE);
    cards.push_back(nineOfDiamonds);

    tenOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::TEN);
    cards.push_back(tenOfDiamonds);

    jackOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::JACK);
    cards.push_back(jackOfDiamonds);

    queenOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::QUEEN);
    cards.push_back(queenOfDiamonds);

    kingOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::KING);
    cards.push_back(kingOfDiamonds);

    aceOfDiamonds = new cardGame::Card(cardGame::ColorType::DIAMONDS, cardGame::ValueType::ACE);
    cards.push_back(aceOfDiamonds);

    sevenOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::SEVEN);
    cards.push_back(sevenOfHearts);

    eightOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::EIGHT);
    cards.push_back(eightOfHearts);

    nineOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::NINE);
    cards.push_back(nineOfHearts);

    tenOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::TEN);
    cards.push_back(tenOfHearts);

    jackOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::JACK);
    cards.push_back(jackOfHearts);

    queenOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::QUEEN);
    cards.push_back(queenOfHearts);

    kingOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::KING);
    cards.push_back(kingOfHearts);

    aceOfHearts = new cardGame::Card(cardGame::ColorType::HEARTS, cardGame::ValueType::ACE);
    cards.push_back(aceOfHearts);



    sevenOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::SEVEN);
    cards.push_back(sevenOfSpades);

    eightOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::EIGHT);
    cards.push_back(eightOfSpades);

    nineOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::NINE);
    cards.push_back(nineOfSpades);

    tenOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::TEN);
    cards.push_back(tenOfSpades);

    jackOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::JACK);
    cards.push_back(jackOfSpades);

    queenOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::QUEEN);
    cards.push_back(queenOfSpades);

    kingOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::KING);
    cards.push_back(kingOfSpades);

    aceOfSpades = new cardGame::Card(cardGame::ColorType::SPADES, cardGame::ValueType::ACE);
    cards.push_back(aceOfSpades);



    sevenOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::SEVEN);
    cards.push_back(sevenOfClubs);

    eightOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::EIGHT);
    cards.push_back(eightOfClubs);

    nineOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::NINE);
    cards.push_back(nineOfClubs);

    tenOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::TEN);
    cards.push_back(tenOfClubs);

    jackOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::JACK);
    cards.push_back(jackOfClubs);

    queenOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::QUEEN);
    cards.push_back(queenOfClubs);

    kingOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::KING);
    cards.push_back(kingOfClubs);

    aceOfClubs = new cardGame::Card(cardGame::ColorType::CLUBS, cardGame::ValueType::ACE);
    cards.push_back(aceOfClubs);
}

cardGame::skat::Deck::~Deck()
{
    delete sevenOfDiamonds;
    delete eightOfDiamonds;
    delete nineOfDiamonds;
    delete tenOfDiamonds;
    delete jackOfDiamonds;
    delete queenOfDiamonds;
    delete kingOfDiamonds;
    delete aceOfDiamonds;

    delete sevenOfHearts;
    delete eightOfHearts;
    delete nineOfHearts;
    delete tenOfHearts;
    delete jackOfHearts;
    delete queenOfHearts;
    delete kingOfHearts;
    delete aceOfHearts;

    delete sevenOfSpades;
    delete eightOfSpades;
    delete nineOfSpades;
    delete tenOfSpades;
    delete jackOfSpades;
    delete queenOfSpades;
    delete kingOfSpades;
    delete aceOfSpades;

    delete sevenOfClubs;
    delete eightOfClubs;
    delete nineOfClubs;
    delete tenOfClubs;
    delete jackOfClubs;
    delete queenOfClubs;
    delete kingOfClubs;
    delete aceOfClubs;
}

void cardGame::skat::Deck::shuffle()
{
    int r1, r2, r3;
    cardGame::Card* forSwap = nullptr;

    r3 = randomNumberGenerator->rand_int(200,500);

    for(int j=1;j<r3;++j)
    {
        r1 = randomNumberGenerator->rand_int(0,31);
        r2 = randomNumberGenerator->rand_int(0,31);
        if(r1!=r2)
        {

            forSwap = cards.at(r1);
            cards.at(r1) = cards.at(r2);
            cards.at(r2) = forSwap;

        }
    }
}

std::vector<cardGame::Card*> cardGame::skat::Deck::getCards(int firstCard, int lastCard) const
{
    std::vector<cardGame::Card*> partOfCards;
    if( firstCard > lastCard || firstCard < 1 || lastCard > cards.size())
        return partOfCards;

    for(int cardIndex=firstCard-1;cardIndex < lastCard; ++cardIndex)
        partOfCards.push_back(cards.at(cardIndex));


    return partOfCards;

}
