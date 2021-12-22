/**
@file : commande_3.cpp
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonction d'evaluation de la reussite d'une partie
*/
#include<iostream>
#include<string>
#include"commandes.h"
#include"lire_coups.h"

/**
@brief : renvoie un booleen pour indiquer si la partie est gagné ou toujours en cours
@return : un booleen
*/
bool game_won(){
    bool is_won = true;
    //saisi du nombre de lignes, de colonnes et de mines
    int nbLignes, nbColonnes, nbMines;
    cin >> nbLignes >> nbColonnes >> nbMines;

    //saisi des emplacement des mines
    int indexMines[nbMines];
    for (int i = 0 ; i < nbMines ; i++)
        cin >> indexMines[i];
    
    //saisi du nombre de coups des coups
    int nbCoups;
    cin >> nbCoups;

    //saisi des mines marquées
    Coups coups;
    for (int i = 0 ; i < nbCoups ; i++){
        lireCoups(coups);
        if (coups.typeCoup == 'M')
            for (int j = 0 ; j < nbMines ; j++){
                if (coups.index == indexMines[j])
                    indexMines[j] = -1;
            }
    }
    
    //test de victoire
    for (int i = 0 ; i < nbMines ; i++)
        if (indexMines[i] != -1)
            return false;
    return true;

}