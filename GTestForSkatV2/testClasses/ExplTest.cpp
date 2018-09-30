#include "ExplTest.h"

TEST_F(ExplTest, demonstration) {
  
  ASSERT_TRUE(1);
  ASSERT_EQ(1,1);

}


/*
 * 
ASSERT_TRUE(condition) 
EXPECT_TRUE(condition) 
ASSERT_FALSE(condition) 
EXPECT_FALSE(condition)

ASSERT_FLOAT_EQ (expected, actual)
ASSERT_DOUBLE_EQ (expected, actual) 
ASSERT_NEAR (expected, actual, absolute_range)
 
EXPECT_FLOAT_EQ (expected, actual)
EXPECT_DOUBLE_EQ (expected, actual) 
EXPECT_NEAR (expected, actual, absolute_range)


ASSERT_EQ(expected, actual) 
ASSERT_NE(expected, actual) 
ASSERT_LT(expected, actual) 
ASSERT_LE(expected, actual) 
ASSERT_GT(expected, actual) 
ASSERT_GE(expected, actual) 

ASSERT_STREQ(expected, actual)
*/
