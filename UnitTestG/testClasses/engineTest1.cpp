#include "engineTest1.h"

#include "../../SkatQTandEngine/skatEngine/skatengine.h"

#include <string>

TEST_F(engineTest1, testEnums) {

  ASSERT_EQ((int)skatEngine::ColorType::NO, (int)0);
  ASSERT_EQ((int)skatEngine::ValueType::NO, (int)0);

}

TEST_F(engineTest1, testNames) {

   skatEngine::Controller &ctrl =  skatEngine::Controller::getController();

   std::string inv = "<invalid>";

   std::string res_ = ctrl.getPlayerName(1);
   ASSERT_EQ(inv, res_);

   res_ = ctrl.getPlayerName(3);
   ASSERT_EQ(inv, res_);


   std::string p1 = "you";
   std::string p2 = "cpu1";
   std::string p3 = "cpu2";
   ctrl.setPlayers(skatEngine::PlayerType::HUMAN, p1, skatEngine::PlayerType::CPU, p2,skatEngine::PlayerType::CPU, p3);

   res_ = ctrl.getPlayerName(0);
   ASSERT_EQ(inv, res_);
   res_ = ctrl.getPlayerName(1);
   ASSERT_EQ(p1, res_);
   res_ = ctrl.getPlayerName(2);
   ASSERT_EQ(p2, res_);
   res_ = ctrl.getPlayerName(3);
   ASSERT_EQ(p3, res_);
   res_ = ctrl.getPlayerName(4);
   ASSERT_EQ(inv, res_);

   skatEngine::Controller::destroyController();
}
