

#include "stdio.h"
#include "string.h"
#include <iostream>

using namespace std;

#if 0
class Monster
{
    public:
        virtual ~Monster(){}
        void Assemble(string strmodelno)
        {
            LoadTrunkModel(strmodelno.substr(4,3));
            LoadHeadModel(strmodelno.substr(7,3));
            LoadLimbsModel(strmodelno.substr(10,3));
        }

        virtual void LoadTrunkModel(string strno) = 0;
        virtual void LoadHeadModel(string strno) = 0;
        virtual void LoadLimbsModel(string strno) = 0;
};

class M_Undead:public Monster
{
public:
    virtual void LoadTrunkModel(string strno)
    {
        cout<<"load dead monster trunk model...."<<strno<<"... "<<endl;
    }
    virtual void LoadHeadModel(string strno)
    {
        cout<<"load dead monster head model...."<<strno<<"... "<<endl;
    }
    virtual void LoadLimbsModel(string strno)
    {
        cout<<"load dead monster limbs model...."<<strno<<"... "<<endl;
    }
};

class M_Element:public Monster
{
public:
    virtual void LoadTrunkModel(string strno)
    {
        cout<<"load Element monster trunk model...."<<strno<<"... "<<endl;
    }
    virtual void LoadHeadModel(string strno)
    {
        cout<<"load Element monster head model...."<<strno<<"... "<<endl;
    }
    virtual void LoadLimbsModel(string strno)
    {
        cout<<"load Element monster limbs model...."<<strno<<"... "<<endl;
    }
};

class M_Mechanic:public Monster
{
public:
    virtual void LoadTrunkModel(string strno)
    {
        cout<<"load Mechanic monster trunk model...."<<strno<<"... "<<endl;
    }
    virtual void LoadHeadModel(string strno)
    {
        cout<<"load Mechanic monster head model...."<<strno<<"... "<<endl;
    }
    virtual void LoadLimbsModel(string strno)
    {
        cout<<"load Mechanic monster libs model...."<<strno<<"... "<<endl;
    }
};
#endif 

class Monster
{
    public:
        virtual ~Monster(){}
};

class M_Undead:public Monster
{

};

class M_Element:public Monster
{

};

class M_Mechanic:public Monster
{

};

class MonsterBuilder
{
public: 
    virtual ~MonsterBuilder(){}
    void Assemble(string strmodelno)
    {
        LoadTrunkModel(strmodelno.substr(4,3));
        LoadHeadModel(strmodelno.substr(7,3));
        LoadLimbsModel(strmodelno.substr(10,3));
    }
    Monster* GetResult()
    {
        return m_pMonster;
    }
    virtual void LoadTrunkModel(string strno) = 0;
    virtual void LoadHeadModel(string strno) = 0;
    virtual void LoadLimbsModel(string strno) = 0;
protected:
    Monster* m_pMonster;
};

class M_UndeadBuilder:public MonsterBuilder
{
    public:
        M_UndeadBuilder()
        {
            m_pMonster = new M_Undead();
        }
        virtual void LoadTrunkModel(string strno)
        {
            cout<<"load Undead monster trunk model need m_pMonster call M_Undead"<<endl;
        }
        virtual void LoadHeadModel(string strno)
        {
            cout<<"load Undead monster Head model need m_pMonster call M_Undead"<<endl;
        }
        virtual void LoadLimbsModel(string strno)
        {
            cout<<"load Undead monster Limbs model need m_pMonster call M_Undead"<<endl;
        }
};

class M_ElementBuilder:public MonsterBuilder
{
    public:
        M_ElementBuilder()
        {
            m_pMonster = new M_Element();
        }
        virtual void LoadTrunkModel(string strno)
        {
            cout<<"load Element monster trunk model need m_pMonster call M_Element"<<endl;
        }
        virtual void LoadHeadModel(string strno)
        {
            cout<<"load Element monster Head model need m_pMonster call M_Element"<<endl;
        }
        virtual void LoadLimbsModel(string strno)
        {
            cout<<"load Element monster Limbs model need m_pMonster call M_Element"<<endl;
        }
};

class M_MechanicBuilder:public MonsterBuilder
{
    public:
        M_MechanicBuilder()
        {
            m_pMonster = new M_Mechanic();
        }
        virtual void LoadTrunkModel(string strno)
        {
            cout<<"load Mechanic monster trunk model need m_pMonster call M_Mechanic"<<endl;
        }
        virtual void LoadHeadModel(string strno)
        {
            cout<<"load Mechanic monster Head model need m_pMonster call M_Mechanicd"<<endl;
        }
        virtual void LoadLimbsModel(string strno)
        {
            cout<<"load Mechanic monster Limbs model need m_pMonster call M_Mechanic"<<endl;
        }
};

class MonsterDirector
{
    public:
        MonsterDirector(MonsterBuilder* ptmpBuilder)
        {
            m_pMonsterBuilder = ptmpBuilder;
        }
        void SetBuilder(MonsterBuilder* ptmpBuilder)
        {
            m_pMonsterBuilder = ptmpBuilder;
        }

        Monster* Construct(string strmodelno)
        {
            m_pMonsterBuilder->LoadTrunkModel(strmodelno.substr(4,3));
            m_pMonsterBuilder->LoadHeadModel(strmodelno.substr(7,3));
            m_pMonsterBuilder->LoadLimbsModel(strmodelno.substr(10,3));
            return m_pMonsterBuilder->GetResult();
        }

        private:
        MonsterBuilder* m_pMonsterBuilder;
};

int main()
{
    //Monster* pmonster = new M_Element();

    //pmonster->Assemble("1253679201245");

    //delete pmonster;

    MonsterBuilder* pMonsterBuilder = new M_UndeadBuilder();
    MonsterDirector* pDirector = new MonsterDirector(pMonsterBuilder);
    Monster* pMonster = pDirector->Construct("1253679201245");

    delete pMonster;
    delete pDirector;
    delete pMonsterBuilder;
}