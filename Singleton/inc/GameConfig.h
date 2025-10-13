#ifndef __GAME_CONFIG_H__
#define __GAME_CONFIG_H__

class GameConfig
{
    //...
    private:
        GameConfig(){};
        GameConfig(const GameConfig& tmpobj);
        GameConfig& operator = (const GameConfig& tmpobj);
        ~GameConfig() {};

    public:
        static GameConfig * getInstance()
        {
            if(m_instance == nullptr)
            {
                m_instance = new GameConfig();
            }
            return m_instance;
        }

        int setTestValue(int value);
    private:
        static GameConfig * m_instance;
    public:
        int m_test;
};

#endif