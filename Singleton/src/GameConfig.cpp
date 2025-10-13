#include "GameConfig.h"

GameConfig* GameConfig::m_instance = nullptr;

int GameConfig::setTestValue(int value)
{
    m_test = value;
    return 0;
}