#include "dekpoczkonzera.h"
#include "KomponentKonkretny.h"
//dekpoczkonzera::dekpoczkonzera(KomponentWizualny* _komponent):Dekorator(_komponent)
//{
    //ctor
//}

dekpoczkonzera::~dekpoczkonzera()
{
    //dtor
}
float dekpoczkonzera::Wygrano(){
    if (this->_komponent){
    return this->_komponent->Wygrano()+100;
    }
    else return 100;
}
