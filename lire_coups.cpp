#include<iostream>
#include"commandes.h"

void lireCoups(Coups& coups, const int tailleGrille){
    cin.get(coups.typeCoup);
    cin >> coups.index;
}