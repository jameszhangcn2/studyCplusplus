#include "gtest/gtest.h"
#include "GameConfig.h"

TEST(gameConfigTest, test1)
{
    EXPECT_EQ(GameConfig::getInstance()->m_test,0);

    GameConfig::getInstance()->setTestValue(5);

    EXPECT_EQ(GameConfig::getInstance()->m_test,5);

    GameConfig::getInstance()->setTestValue(0);
}

TEST(gameConfigTest, test2)
{
    EXPECT_EQ(GameConfig::getInstance()->m_test,0);

    GameConfig::getInstance()->setTestValue(8);

    EXPECT_EQ(GameConfig::getInstance()->m_test,8);

    GameConfig::getInstance()->setTestValue(115);

    EXPECT_EQ(GameConfig::getInstance()->m_test,115);
}