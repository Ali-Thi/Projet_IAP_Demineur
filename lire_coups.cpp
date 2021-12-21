#include<iostream>
#include"commandes.h"
#include"lire_coups.h"

void lireCoups(Coups& coups){
    cin.get(coups.typeCoup);
    cin >> coups.index;
}