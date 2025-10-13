#include "GameConfig.h"
#include <stdlib.h>
#include <iostream>

int main()
{
    std::cout<<"main"<<std::endl;
    GameConfig * g_gc1 = GameConfig::getInstance();
    g_gc1->m_test = 5;
    std::cout<<"g_gc1->m_test "<<g_gc1->m_test<<std::endl;
    GameConfig * g_gc2 = GameConfig::getInstance();
    std::cout<<"g_gc1->m_test "<<g_gc2->m_test<<std::endl;
    return 0;
}