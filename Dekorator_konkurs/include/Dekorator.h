#ifndef DEKORATOR_H
#define DEKORATOR_H
#include "KomponentWizualny.h"

class Dekorator : public KomponentWizualny
{
    public:
        Dekorator(KomponentWizualny*);
        virtual ~Dekorator();
        virtual float Wygrano();
    protected:
KomponentWizualny* _komponent;
    private:

};

#endif // DEKORATOR_H
