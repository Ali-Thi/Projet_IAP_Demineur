/**
@file : commande_5.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 22/12/21
@brief : fonction de recherche d'une case a demasquer
 */
#include<iostream>
#include"commandes.h"

/**
@brief : trouve une case a demasquer ou affiche une erreur si elle n'en troupe pas
@return : l'index d'une case 
*/
int find_move(){
    //saisi du nombre de lignes et de colonnes
    int nbLignes, nbColonnes;
    cin >> nbLignes >> nbColonnes;
    
    //trouve un case non demasquee
    char cara = ' ';
    int i = 0;
    while (cara != '.'){
        cin >> cara;
        if (cara == '|')
            i++;
    }

    int indexLigne = i/(nbColonnes+1);
    return indexLigne*nbColonnes + i%(nbColonnes+1) - 1;
}