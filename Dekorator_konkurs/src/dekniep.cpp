#include "dekniep.h"
#include "KomponentKonkretny.h"


dekniep::~dekniep()
{
    //dtor
}
float dekniep::Wygrano(){
    if (this->_komponent){
    return this->_komponent->Wygrano()+50;
    }
    else return 50;
}
