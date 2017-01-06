#ifndef DEKNIEP_H
#define DEKNIEP_H
#include "Dekorator.h"
#include "KomponentWizualny.h"

class dekniep: public Dekorator
{
    public:
        dekniep(KomponentWizualny* _komponent):Dekorator(_komponent){};
        virtual ~dekniep();
        virtual float Wygrano();
    protected:

    private:
};

#endif // DEKNIEP_H
