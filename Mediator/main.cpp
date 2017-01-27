#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
class Mediatorr;

class Walidator
{
  public:
    Walidator(Mediatorr *mediator)
    {
        _mediator = mediator;

    }
    virtual void changed(string tekst);
    virtual void updateWidget(string tekst) = 0;
    //virtual void queryWidget() = 0;
  protected:
  private:
    Mediatorr *_mediator;
};

class WalidatorTXT: public Walidator
{
  public:
    WalidatorTXT(Mediatorr *dir): Walidator(dir){}
    void updateWidget(string tekst)
    {
        cout << "    waliduje sie txt" << endl;
    }
};

class WalidatorEVEN: public Walidator
{
  public:
    WalidatorEVEN(Mediatorr *dir): Walidator(dir){}
    void updateWidget(string tekst)
    {
        cout << "    waliduje sie even" << endl;
    }
};
class WalidatorALFA: public Walidator
{
  public:
    WalidatorALFA(Mediatorr *dir): Walidator(dir){}
    void updateWidget(string tekst)
    {
        cout << "    waliduje sie alfa" << endl;
    }
};
class WalidatorNUM: public Walidator
{
  public:
    WalidatorNUM(Mediatorr *dir): Walidator(dir){}
    void updateWidget(string tekst)
    {
        cout << "    waliduje sie num" << endl;
    }
};
class Mediatorr
{
  public:
    enum Widgets
    {
        TXT, EVEN, ALFA, NUM
    };
    Mediatorr()
    {
        _components[TXT] = new WalidatorTXT(this);
        _components[EVEN] = new WalidatorEVEN(this);
        _components[ALFA] = new WalidatorALFA(this);
        _components[NUM] = new WalidatorNUM(this);
    }
    virtual ~Mediatorr();
    void handleEvent(int which,string tekst)
    {
        _components[which]->changed(tekst);
    }
    virtual void widgetChanged(Walidator *theChangedWidget,string tekst)
    {
        if (theChangedWidget == _components[TXT])
        {

            _components[TXT]->updateWidget(tekst);

        }
        else if (theChangedWidget == _components[EVEN])
        {

            _components[EVEN]->updateWidget(tekst);

        }
        else if (theChangedWidget == _components[ALFA])
        {
           // _components[ALFA]->queryWidget();
            _components[ALFA]->updateWidget(tekst);
        }
        else if (theChangedWidget == _components[NUM])
        {
            _components[NUM]->updateWidget(tekst);
        }
    }
  private:
    Walidator *_components[4];
};

Mediatorr::~Mediatorr()
{
  for (int i = 0; i < 4; i++)
    delete _components[i];
}

void Walidator::changed(string tekst)
{
  _mediator->widgetChanged(this,tekst);
}
vector<string>* wczytaj_plik(string nazwa_pliku) {
    ifstream wejscie(nazwa_pliku.c_str());
    vector<string>* wyjscie = new vector<string>();
    string linia;
    while(getline(wejscie, linia)) {
        wyjscie->push_back(linia);
    }

    wejscie.close();
    return wyjscie;
}
int main()
{
    vector <string>* wejscie = wczytaj_plik("wejscie.txt");
    string s;
    for (std::vector<string>::iterator it = wejscie->begin() ; it != wejscie->end(); ++it) {
        cout << *it<<endl;;
        s=*it;
        vector<string> el;
        stringstream ss(s);
        string item;
        while (getline(ss, item, ';')) {
            el.push_back(item);
        }
         Mediatorr fileDialog;
        for (int j=1; j<el.size();j++){
                if(el[j]=="TXT"){
                    fileDialog.handleEvent(0,el[0]);
                } else if (el[j]=="EVEN"){
                    fileDialog.handleEvent(1,el[0]);
                } else if (el[j]=="ALFA"){
                    fileDialog.handleEvent(2,el[0]);
                } else if (el[j]=="NUM"){
                    fileDialog.handleEvent(3,el[0]);
                }

        }
    }
}
