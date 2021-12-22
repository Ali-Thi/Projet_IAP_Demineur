/**
@file : lire_coups.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonction d'interpretation d'un coups entre par l'utilisateur
*/
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