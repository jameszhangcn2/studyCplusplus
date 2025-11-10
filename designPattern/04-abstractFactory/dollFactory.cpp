
#include <iostream>
#include "stdio.h"

using namespace  std;

class Body
{
    public:
    virtual void getName()=0;
    virtual ~Body(){}
};

class Clothes
{
    public:
    virtual void getName()=0;
    virtual ~Clothes(){}
};

class Shoes
{
    public:
    virtual void getName()=0;
    virtual ~Shoes(){}
};

class AbstractFactory
{
public:
    virtual Body* createBody()=0;
    virtual Clothes* createClothes()=0;
    virtual Shoes* createShoes()=0;
    virtual ~AbstractFactory(){};
};

class BarbieDoll
{
    public:
        BarbieDoll(Body* tmpbody, Clothes* tmpclothes, Shoes* tmpshoes)
        {
            body = tmpbody;
            clothes = tmpclothes;
            shoes = tmpshoes;
        }
        void Assemble()
        {
            cout<<"success assemble a Barbie Doll:"<<endl;
            body->getName();
            clothes->getName();
            shoes->getName();
        }

    private:
        Body* body;
        Clothes* clothes;
        Shoes* shoes;
};

class China_Body:public Body
{
    public:
        virtual void getName()
        {
            cout<<"China made body"<<endl;
        }
};

class China_Shoes:public Shoes
{
    public:
        virtual void getName()
        {
            cout<<"China made shoes"<<endl;
        }
};

class China_Clohes:public Clothes
{
    public:
        virtual void getName()
        {
            cout<<"China made Clothes"<<endl;
        }
};

class ChinaFactory:public AbstractFactory
{
    public:
        virtual Body* createBody()
        {
            return new China_Body;
        }
        virtual Clothes* createClothes()
        {
            return new China_Clohes;
        }
        virtual Shoes* createShoes()
        {
            return new China_Shoes;
        }
};

class Japan_Body:public Body
{
    public:
        virtual void getName()
        {
            cout<<"Japan made body"<<endl;
        }
};

class Japan_Shoes:public Shoes
{
    public:
        virtual void getName()
        {
            cout<<"Japan made shoes"<<endl;
        }
};

class Japan_Clohes:public Clothes
{
    public:
        virtual void getName()
        {
            cout<<"Japan made Clothes"<<endl;
        }
};

class JapanFactory:public AbstractFactory
{
    public:
        virtual Body* createBody()
        {
            return new Japan_Body;
        }
        virtual Clothes* createClothes()
        {
            return new Japan_Clohes;
        }
        virtual Shoes* createShoes()
        {
            return new Japan_Shoes;
        }
};


class America_Body:public Body
{
    public:
        virtual void getName()
        {
            cout<<"America made body"<<endl;
        }
};

class America_Shoes:public Shoes
{
    public:
        virtual void getName()
        {
            cout<<"America made shoes"<<endl;
        }
};

class America_Clohes:public Clothes
{
    public:
        virtual void getName()
        {
            cout<<"America made Clothes"<<endl;
        }
};

class AmericaFactory:public AbstractFactory
{
    public:
        virtual Body* createBody()
        {
            return new America_Body;
        }
        virtual Clothes* createClothes()
        {
            return new America_Clohes;
        }
        virtual Shoes* createShoes()
        {
            return new America_Shoes;
        }
};


int main()
{
    AbstractFactory* pChinaFactory = new ChinaFactory();
    Body* pChinaBody = pChinaFactory->createBody();
    Clothes* pChinaClothes = pChinaFactory->createClothes();
    Shoes* pChinaShoes = pChinaFactory->createShoes();
    BarbieDoll* pbdlobj = new BarbieDoll(pChinaBody, pChinaClothes, pChinaShoes);
    pbdlobj->Assemble();

    //create the second Barbie
    AbstractFactory* pJapanFactory = new JapanFactory();
    AbstractFactory* pAmericaFactory = new AmericaFactory();

    Body* pChinaBody2 = pChinaFactory->createBody();
    Clothes* pJapanClothes2 = pJapanFactory->createClothes();
    Shoes* pAmericaShoes2 = pAmericaFactory->createShoes();

    BarbieDoll* pbd2obj = new BarbieDoll(pChinaBody2, pJapanClothes2, pAmericaShoes2);
    pbd2obj->Assemble();

    delete pbdlobj;
    delete pbd2obj;
    delete pChinaBody;
    delete pChinaClothes;
    delete pChinaShoes;

    delete pbd2obj;
    delete pAmericaShoes2;
    delete pJapanClothes2;
    delete pChinaBody2;
    delete pChinaFactory;
    delete pJapanFactory;
    delete pAmericaFactory;

    return 0;
}