#include <iostream>
#include <vector>
#include "KomponentWizualny.h"
#include "KomponentKonkretny.h"
#include "dekpoczkonzera.h"
#include "dekniep.h"
using namespace std;
int main()
{
    vector < int > tab;
    //zapis
    int x = 3;
    for( int i = 0; i < 10; i++ )
    {
        tab.push_back( x );
        x =  3;
    }
    tab.push_back(3);
    //odczyt
    for( int i = 0; i < tab.size(); i++ )
    {
        cout << tab[ i ] <<" ";
    }
    cout<<endl;
    bool niep=true;
    for (int i=0;i<tab.size();i++){
        if(tab[i]%2==0){
            niep=false;
            cout<<"jest parzysta liczba";
            break;
        }
    }
    KomponentWizualny *komponent=NULL;
    komponent=new KomponentKonkretny();
    if (tab[0] == 3 && tab[tab.size()-1] == 3){
            cout<<"pierwszy i ost el 3 +100 "<<endl;
       komponent=new dekpoczkonzera(komponent);
    }
    if (niep==1){
        cout<<"wszystkie el sa nieparzyste +50 "<<endl;
       komponent=new dekniep(komponent);

    }
cout<<"\nwygrano tyle "<<komponent->Wygrano()<<endl;
        delete komponent;
    return 0;
}
