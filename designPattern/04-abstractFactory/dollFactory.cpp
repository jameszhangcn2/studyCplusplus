
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
int main()
{
    AbstractFactory* pChinaFactory = new ChinaFactory();
    Body* pChinaBody = pChinaFactory->createBody();
    Clothes* pChinaClothes = pChinaFactory->createClothes();
    Shoes* pChinaShoes = pChinaFactory->createShoes();
    BarbieDoll* pbdlobj = new BarbieDoll(pChinaBody, pChinaClothes, pChinaShoes);
    pbdlobj->Assemble();

    delete pChinaFactory;
    delete pChinaBody;
    delete pChinaClothes;
    delete pChinaShoes;
    delete pbdlobj;


    return 0;
}