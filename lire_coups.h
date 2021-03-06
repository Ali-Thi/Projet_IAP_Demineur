/**
@file : lire_coups.h
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonction d'interpretation d'un coup entré par l'utilisateur
*/
#ifndef LIRE_COUPS
#define LIRE_COUPS

using namespace std;

struct Coups{
    char typeCoup;
    int index;
};

/**
@brief : permet d'interpréter un coup entré par l'utilsateur et d'affecter les valeurs correspondantes à une variable de type Coups
@param [in, out] coups : la variable de type Coups
*/
void lireCoups(Coups& coups);

#endif
