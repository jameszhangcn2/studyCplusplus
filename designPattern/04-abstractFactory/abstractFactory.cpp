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

class M_ParFactory
{
    public:
        virtual Monster* createMonster()=0;
        virtual ~M_ParFactory(){}
};

class M_UndeadFactory:public M_ParFactory
{
    public:
        virtual Monster* createMonster()
        {
            //return new M_Undead(300,50,80);
            Monster *ptmp = new M_Undead(300, 50, 80);
            //here can add some logic, exp: set the position
            return ptmp;
        }
};

class M_ElementFactory:public M_ParFactory
{
    public:
        virtual Monster* createMonster()
        {
            return new M_Element(200,80,100);
        }
};

class M_MechanicFactory:public M_ParFactory
{
    public:
        virtual Monster* createMonster()
        {
            return new M_Mechanic(400,0,110);
        }
};

template <typename T>
class M_ChildFactory:public M_ParFactory
{
    public:
        virtual Monster* createMonster()
        {
            return new T(300, 50, 80);
        }
};

Monster* Gbl_CreateMonster(M_ParFactory* factory)
{
    return factory->createMonster();
}

int main()
{
    M_ParFactory* p_ud_fy = new M_UndeadFactory();
    Monster* pM1 = Gbl_CreateMonster(p_ud_fy);

    M_ParFactory* p_elm_fy = new M_ElementFactory();
    Monster* pM2 = Gbl_CreateMonster(p_elm_fy);

    M_ParFactory* p_mec_fy = new M_MechanicFactory();
    Monster* pM3 = Gbl_CreateMonster(p_mec_fy);

    delete p_ud_fy;
    delete p_elm_fy;
    delete p_mec_fy;

    delete pM1;
    delete pM2;
    delete pM3;

    M_ChildFactory<M_Undead> myFactory;
    Monster *pM10=myFactory.createMonster();

    delete pM10;

    return 0;
}