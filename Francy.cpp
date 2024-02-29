
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class FrancyVec
{
    vector<int>* vecNom;
    vector<int>* vecDenom;
    int smallNum;
public:
    FrancyVec()
    {
        vecNom=new vector<int>;
        vecDenom=new vector<int>;
    }
    ~FrancyVec()
    {
        delete(vecNom);
        delete(vecDenom);
    }
    void addElement(int a, int b)
    {
        if(a%b==0)
            a/=b, b=1;
        else
        {
            smallNum=0;
            int i=0;
            a<b ? smallNum=a : smallNum=b;
            while(i<(smallNum/2))
            {
                if(a%i==0 && b%i==0)
                {
                    a/=i;
                    b/=i;
                }
            }
        }
        vecNom->push_back(a);
        vecDenom->push_back(b);
    }

    void showElements()
    {
       for(vector<int>::iterator it=vecNom->begin(); it!=vecNom->end();++it)
                    cout<<' '<<*it;
    }
    friend class Francy;


};



class Francy
{
    int nom;
    int denom;
    FrancyVec* container;
public:
    Francy(int Nom,int Denom):nom(Nom),denom(Denom)
    {
        container=new FrancyVec();
        container->addElement(nom, denom);
    }
    ~Francy()
    {
        delete(container);
    }

    void addParameter(int a, int b)
    {
        container->addElement(a,b);
    }
    void rangeVector()
    {
        container->showElements();

    }

};


int main()
{
    Francy deneme(5,7);
    deneme.addParameter(8,10);
    deneme.addParameter(3,5);


}
