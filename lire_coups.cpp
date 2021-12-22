#include<iostream>
#include"commandes.h"
#include"lire_coups.h"

/**
@brief : permet d'interpréter un coups entre par l'utilsateur et d'affecter les valeurs correspondante à une variable de type Coups
@param [in, out] coups : la variable de type Coups
*/
void lireCoups(Coups& coups){
    cin.get(coups.typeCoup);
    cin >> coups.index;
}