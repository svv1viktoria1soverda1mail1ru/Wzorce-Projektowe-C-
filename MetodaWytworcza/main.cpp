#include <iostream>
#include <vector>
using namespace std;
enum TypPracownika {SZEF,ADMIN};
class Pracownik
{
public:
    virtual ~Pracownik() {};
    virtual vector<int> dostepne_pomieszczenia()=0;
    virtual string get_typ()=0;
protected:

};
class PSzef: public Pracownik
{
protected:
    vector <int> tab;
    string nazwa="szef";
public:
    PSzef() {};
    ~PSzef() {};
    virtual vector<int> dostepne_pomieszczenia()
    {
        tab.push_back(20);
        tab.push_back(2);
        tab.push_back(40);
        tab.push_back(1);
        return tab;
    }
    virtual string get_typ()
    {
        return nazwa;
    }
};
class PAdministrator: public Pracownik
{
protected:
    vector <int> tab;
    string nazwa="administrator";
public:
    PAdministrator() {};
    ~PAdministrator() {};
    virtual vector<int> dostepne_pomieszczenia()
    {
        for(int i=0; i<40;i++){
            tab.push_back(i+1);
        }
        return tab;
    }
    virtual string get_typ()
    {
        return nazwa;
    }
};
class Stworca
{
public:
    Stworca() {};
    virtual ~Stworca() {};
    virtual Pracownik * create_pracownik(TypPracownika typ)=0;
};
class MyStworca: public Stworca
{
public:
    MyStworca() {};
    virtual ~MyStworca() {};
    virtual Pracownik * create_pracownik(TypPracownika typ)
    {
        switch(typ)
        {
        case SZEF:
            return new PSzef();
        case ADMIN:
            return new PAdministrator();
        default:
            return NULL;
        }
    }
};
int main()
{
    Stworca* s=new MyStworca();
    Pracownik* pracownik1=s->create_pracownik(SZEF);
    vector<int> tab=pracownik1->dostepne_pomieszczenia();
    cout<<" Dostepnie pomieszczenia dla "<<pracownik1->get_typ()<<"a"<<endl;
    for (int i=0;i<tab.size();i++){
        cout<<tab[i]<<endl;

    }
    Pracownik* pracownik2=s->create_pracownik(ADMIN);
    vector<int> tab1=pracownik2->dostepne_pomieszczenia();
    cout<<" Dostepnie pomieszczenia dla "<<pracownik2->get_typ()<<"a"<<endl;
    for (int i=0;i<tab1.size();i++){
        cout<<tab1[i]<<endl;

    }
    return 0;
}
