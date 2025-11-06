

#include <stdio.h>
#include <iostream>

using namespace std;
class Fighter
{
    public:
    Fighter(int life, int magic, int attack):m_life(life),m_magic(magic),m_attack(attack){}
    virtual ~Fighter(){};

    void JN_Burn()
    {
        if(false == canUseJN())
        {
            cout<<"can not use JN!"<<endl;
            return;
        }
        effect_enemy();
        effect_self();
        play_effect();
    };

    private:
        virtual void effect_enemy(){};
        virtual void effect_self(){};
        virtual bool canUseJN()=0;
        void play_effect()
        {
            cout<<"play the effect in Fighter."<<endl;
        }
    protected:
        int m_life;
        int m_magic;
        int m_attack;
};

class F_Warrior:public Fighter
{
    public:
        F_Warrior(int life, int magic, int attack):Fighter(life, magic, attack) {};

    private:
        virtual void effect_enemy()
        {
            cout<<"Warror let all enemy lost 500 life."<<endl;
        }
        virtual void effect_self()
        {
            cout<<"Warror lost 300 self life."<<endl;
            m_life -= 300;
        }
        virtual bool canUseJN()
        {
            if(m_life < 300)
            {
                cout<<"life is not enough "<<m_life<<endl;
                return false;
            }
            return true;
        }
};


class F_Mage:public Fighter
{
    public:
        F_Mage(int life, int magic, int attack):Fighter(life, magic, attack) {};

    private:
        virtual void effect_enemy()
        {
            cout<<"Mage let all enemy lost 650 life."<<endl;
        }
        virtual void effect_self()
        {
            cout<<"Mage lost 100 self magic."<<endl;
            m_magic -= 100;
        }
        virtual bool canUseJN()
        {
            if(m_magic < 100)
            {
                cout<<"magic is not enough "<<m_magic<<endl;
                return false;
            }
            return true;
        }
};

int main()
{
    F_Warrior mroleobj(1000,0,200);
    mroleobj.JN_Burn();

    F_Mage magicobj(800,200,300);
    magicobj.JN_Burn();

    Fighter *prole_warr = new F_Warrior(1000, 0, 200);
    prole_warr->JN_Burn();

    Fighter *prole_mag = new F_Mage(800, 200, 300);

    prole_mag->JN_Burn();

    delete prole_warr;
    delete prole_mag;

    Fighter *prole_warr2 = new F_Warrior(200, 0, 100);
    prole_warr2->JN_Burn();

    Fighter *prole_mag2 = new F_Mage(800, 50, 300);

    prole_mag2->JN_Burn();

    delete prole_warr2;
    delete prole_mag2;

    return 0;
}