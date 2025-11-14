#include <stdio.h>
#include <iostream>
using namespace std;
class Monster
{
    public:
        Monster(int life, int magic, int attack):m_life(life), m_magic(magic), m_attack(attack){}
        virtual ~Monster(){}

    public:
        virtual Monster* clone() = 0;
    protected:
        int m_life;
        int m_magic;
        int m_attack;

};


class M_Undead: public Monster
{
public:
    M_Undead(int life, int magic, int attack):Monster(life, magic, attack)
    {
        cout<<" An undead Monster come to this world!"<<endl;
    }
    M_Undead(const M_Undead& tmpobj):Monster(tmpobj)
    {
        cout<<"Call M_Undead clone to create an Undead Monster!"<<endl;
    }

    virtual Monster* clone()
    {
        return new M_Undead(*this);
    }
};


class M_Element: public Monster
{
public:
    M_Element(int life, int magic, int attack):Monster(life, magic, attack)
    {
        cout<<" An Element Monster come to this world!"<<endl;
    }
    M_Element(const M_Element& tmpobj):Monster(tmpobj)
    {
        cout<<"Call M_Element clone to create an Element Monster!"<<endl;
    }

    virtual Monster* clone()
    {
        return new M_Element(*this);
    }
};


class M_Mechanic: public Monster
{
public:
    M_Mechanic(int life, int magic, int attack):Monster(life, magic, attack)
    {
        cout<<" An Mechanic Monster come to this world!"<<endl;
    }
    M_Mechanic(const M_Mechanic& tmpobj):Monster(tmpobj)
    {
        cout<<"Call M_Mechanic clone to create an Mechanic Monster!"<<endl;
    }

    virtual Monster* clone()
    {
        return new M_Mechanic(*this);
    }
};

int main()
{
    M_Mechanic myPropMecMonster(400,0,100);

    Monster* pmyPropEleMonster = new M_Element(200, 80, 100);

    Monster* p_CloneObj1 = myPropMecMonster.clone();
    Monster* p_CloneObj2 = pmyPropEleMonster->clone();

    delete p_CloneObj1;
    delete p_CloneObj2;

    delete pmyPropEleMonster;
    
    return 0;
}