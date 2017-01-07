#include <iostream>
#include <string>
using namespace std;

class Strategia
{
public:
    virtual float podatek(float dano)=0;
    virtual float rabatD(float dano, int iloscdzieci)=0;
    virtual float rabatM(float dano, float mieszkanie)=0;
    virtual float dochod(float dano, float koszty)=0;
};
class OPrawna : public Strategia
{
protected:
    float pod=0.2;
public:
    OPrawna() {};
    float dochod(float dano, float koszty)
    {
        if(koszty > 15000)
            return dano-15000;
        else
            return dano-koszty;
    }
    float podatek(float dano)
    {
        cout<<"dochod "<<dano-dano*pod<<endl;
        return dano-dano*pod;
    }
    float rabatM(float dano, float mieszkanie)
    {
        cout<<"rabatM "<<dano-mieszkanie<<endl;
        return dano-mieszkanie;
    }
    float rabatD(float dano, int iloscdzieci)
    {
        cout<<"rabatD "<<dano<<endl;
        return dano;
    }
};
class OFizyczna : public Strategia
{

    float pod1=0.15,pod2=0.3;
public:
    OFizyczna() {};
    float dochod(float dano, float koszty)
    {
        if(koszty > 10000)
            return dano-10000;
        else
            return dano-koszty;
    }
    float podatek(float dano)
    {
        if(dano<100000)
            return dano-pod1*dano;
        else
            return dano-pod2*dano;
    }
    float rabatM(float dano, float mieszkanie)
    {
        return dano-mieszkanie;
    }
    float rabatD(float dano, int iloscdzieci)
    {
        return dano;
    }
};
class OMalz : public Strategia
{
protected:
    float pod1=0.15,pod2=0.3;
public:
    OMalz() {};
    float dochod(float dano, float koszty)
    {
        if(koszty > 20000)
            return dano-20000;
        else
            return dano-koszty;
    }
    float podatek(float dano)
    {
        if(dano<200000)
            return dano-pod1*dano;
        else
            return dano-pod2*dano;
    }
    float rabatM(float dano, float mieszkanie)
    {
        return dano-mieszkanie;
    }
    float rabatD(float dano, int iloscdzieci)
    {
        return dano-iloscdzieci*500;
    }
};
class RozliczeniaPodatkowe
{
//protected:
    float przychod, koszty, czynsz;
    int iloscDzieci;
    Strategia* typ;

public :
    RozliczeniaPodatkowe(string str,float przychod, float koszty, int iloscDzieci, float czynsz)
    {
        this->przychod=przychod;
        this->koszty=koszty;
        this->iloscDzieci=iloscDzieci;
        this->czynsz=czynsz;
        if (str =="fizyczna")
        {
            typ= new OFizyczna();
        }
        else if (str=="prawna")
        {
            typ= new OPrawna();
        }
        else if (str=="malrzenstwo")
        {
            typ= new OMalz();
        }
        else
        {
            throw "nie ma takiego typu!";
        }
    }

    float oblicz()
    {
        float wynik=0;
        wynik=typ->dochod(przychod,koszty);
        wynik=typ->rabatD(wynik,iloscDzieci);
        wynik=typ->rabatM(wynik,czynsz);
        wynik=typ->podatek(wynik);
        return wynik;
    }
};
int main()
{
    RozliczeniaPodatkowe* r=new RozliczeniaPodatkowe("fizyczna",40000, 2344, 4, 600);
    cout<<"Twoj dochod wynosi "<<r->oblicz()<<endl;
    return 0;
}
