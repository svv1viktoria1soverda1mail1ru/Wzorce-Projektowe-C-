#include "Dekorator.h"

Dekorator::Dekorator(KomponentWizualny* _komponent)
{
    this->_komponent=_komponent;
}

Dekorator::~Dekorator()
{
    //dtor
}
float Dekorator::Wygrano(){
_komponent->Wygrano();
}
