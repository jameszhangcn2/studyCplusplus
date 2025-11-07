#include <iostream>
#include <stdio.h>
using namespace std;

class Monster
{
    public:
        Monster(int life, int magic, int attack):m_life(life), m_magic(magic),m_attack(attack) {}
        virtual ~Monster(){}
    protected:
        int m_life;
        int m_magic;
        int m_attack;
};

class M_Undead:public Monster
{
public:
    M_Undead(int life, int magic, int attack):Monster(life, magic, attack)
    {
        cout<<"one undead monster come to this world!!"<<endl;
    }
};

class M_Element:public Monster
{
public:
    M_Element(int life, int magic, int attack):Monster(life, magic, attack)
    {
        cout<<"one element monster come to this world!!"<<endl;
    }
};

class M_Mechanic:public Monster
{
public:
    M_Mechanic(int life, int magic, int attack):Monster(life, magic, attack)
    {
        cout<<"one mechanic monster come to this world!!"<<endl;
    }
};

class MonsterFactory
{
    public:
        static Monster* createMonster(string strmontype)
        {
            Monster* prtnobj = nullptr;
            if(strmontype == "udd")
            {
                prtnobj = new M_Undead(300, 50, 80);
            }
            else if(strmontype == "elm")
            {
                prtnobj = new M_Element(200, 80, 100);
            }
            else if(strmontype == "mec")
            {
                prtnobj = new M_Mechanic(400, 0, 110);
            }
            return prtnobj;
        }

};


int main()
{
    Monster * pM1 = MonsterFactory::createMonster("udd");
    Monster * pM2 = MonsterFactory::createMonster("elm");
    Monster * pM3 = MonsterFactory::createMonster("mec");

    //delete
    delete pM1;
    delete pM2;
    delete pM3;

    return 0;
}