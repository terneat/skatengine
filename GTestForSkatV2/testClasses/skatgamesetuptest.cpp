#include "skatgamesetuptest.h"

#include "../../SkatV2/Engine/include/skatgamesetup.h"


using namespace std;
using namespace cardGame;

TEST_F(SkatGameSetupTest, bid) {
  
    skat::GameSetup* gamesetup = new skat::GameSetup(1,4,9);

    gamesetup->setBid(1, 18);
    gamesetup->setBid(4, 20);
    gamesetup->setBid(9, 24);

    int Bid1 = gamesetup->getBid(1);
    ASSERT_EQ(Bid1, 18);

    int Bid2 = gamesetup->getBid(4);
    ASSERT_EQ(Bid2, 20);

    int Bid3 = gamesetup->getBid(9);
    ASSERT_EQ(Bid3, 24);

    int Bid4 = gamesetup->getBid(323);
    ASSERT_EQ(Bid4, 0);

    delete gamesetup;

}

TEST_F(SkatGameSetupTest, idreplayer) {

    skat::GameSetup* gamesetup = new skat::GameSetup(1,4,9);

    gamesetup->setIdRePlayer(34);
    int idre = gamesetup->getIdRePlayer();

    ASSERT_EQ(34, idre);

    delete gamesetup;
}

TEST_F(SkatGameSetupTest, gamechoice) {

    skat::GameSetup* gamesetup = new skat::GameSetup(1,4,9);

    gamesetup->setGameChoice(cardGame::skat::GameType::GRAND);

    skat::GameType gametype = gamesetup->getGameType();
    ASSERT_EQ(skat::GameType::GRAND, gametype);
    ASSERT_FALSE(gamesetup->isHand());
    ASSERT_FALSE(gamesetup->isSchneider());
    ASSERT_FALSE(gamesetup->isSchwarz());
    ASSERT_FALSE(gamesetup->isOuvert());

    gamesetup->setGameChoice(cardGame::skat::GameType::NULLG, true);

    gametype = gamesetup->getGameType();
    ASSERT_EQ(skat::GameType::NULLG, gametype);
    ASSERT_TRUE(gamesetup->isHand());
    ASSERT_FALSE(gamesetup->isSchneider());
    ASSERT_FALSE(gamesetup->isSchwarz());
    ASSERT_FALSE(gamesetup->isOuvert());

    gamesetup->setGameChoice(cardGame::skat::GameType::SPADES, true, true);

    gametype = gamesetup->getGameType();
    ASSERT_EQ(skat::GameType::SPADES, gametype);
    ASSERT_TRUE(gamesetup->isHand());
    ASSERT_TRUE(gamesetup->isSchneider());
    ASSERT_FALSE(gamesetup->isSchwarz());
    ASSERT_FALSE(gamesetup->isOuvert());

    gamesetup->setGameChoice(cardGame::skat::GameType::GRAND, true, true, true);

    gametype = gamesetup->getGameType();
    ASSERT_EQ(skat::GameType::GRAND, gametype);
    ASSERT_TRUE(gamesetup->isHand());
    ASSERT_TRUE(gamesetup->isSchneider());
    ASSERT_TRUE(gamesetup->isSchwarz());
    ASSERT_FALSE(gamesetup->isOuvert());

    gamesetup->setGameChoice(cardGame::skat::GameType::CLUBS, true, true, true, true);

    gametype = gamesetup->getGameType();
    ASSERT_EQ(skat::GameType::CLUBS, gametype);
    ASSERT_TRUE(gamesetup->isHand());
    ASSERT_TRUE(gamesetup->isSchneider());
    ASSERT_TRUE(gamesetup->isSchwarz());
    ASSERT_TRUE(gamesetup->isOuvert());

    delete gamesetup;
}
