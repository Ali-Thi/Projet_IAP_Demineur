#ifndef LIRE_COUPS
#define LIRE_COUPS

using namespace std;

struct Coups{
    char typeCoup;
    int index;
};

/**
@brief : permet d'interpréter un coups entre par l'utilsateur et d'affecter les valeurs correspondante à une variable de type Coups
@param [in, out] coups : la variable de type Coups
*/
void lireCoups(Coups& coups);

#endif