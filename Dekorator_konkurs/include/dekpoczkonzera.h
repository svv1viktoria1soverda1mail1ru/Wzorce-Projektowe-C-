#ifndef DEKPOCZKONZERA_H
#define DEKPOCZKONZERA_H
#include "Dekorator.h"
#include "KomponentWizualny.h"
class dekpoczkonzera : public Dekorator
{
    public:
        dekpoczkonzera(KomponentWizualny* _komponent):Dekorator(_komponent){};
        virtual ~dekpoczkonzera();
        virtual float Wygrano();
    protected:

    private:
};

#endif // DEKPOCZKONZERA_H
