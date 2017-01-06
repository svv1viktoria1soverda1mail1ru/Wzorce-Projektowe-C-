#ifndef KOMPONENTKONKRETNY_H
#define KOMPONENTKONKRETNY_H
#include "KomponentWizualny.h"
#include <vector>
class KomponentKonkretny :public KomponentWizualny
{
    public:
       // std::vector<int> tablica;
        KomponentKonkretny();
        virtual ~KomponentKonkretny();
        virtual float Wygrano();
    protected:

    private:
};

#endif // KOMPONENTKONKRETNY_H
