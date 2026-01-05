#include <stdio.h>
#include <iostream>
using namespace std;

class Item {
    public:
        Item *source;
        Item(Item* src){source=src;}
        virtual int out() { return 0;}
};

class Counter: public Item{
    int value;
    public:
        int out() {return value++;}
        Counter(int v):Item(0){value=v;}
};
class Filter:public Item{
    int factor;
    public:
    int out(){
        while(1)
        {
            int n=source->out();
            if(n%factor) return n;
        }
    }
    Filter(Item *src, int f):Item(src){factor=f;}
};
class Sieve:public Item{
    public:
    int out(){
        int n=source->out();
        source = new Filter(source, n);
        return n;
    }
    Sieve(Item *src):Item(src){}
};
int main()
{
    Counter c(2);
    Sieve s(&c);
    int next,n;
    cin>>n;
    while(1){
        next=s.out();
        if(next>n) break;
        cout<<next<<" ";
    }
    cout<<endl;
    return 0;
}
