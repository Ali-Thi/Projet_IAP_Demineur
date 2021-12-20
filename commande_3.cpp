#include<iostream>
#include<string>
#include"commandes.h"
#include"lire_coups.h"

bool game_won(){
    bool is_won = true;
    //saisi du nombre de lignes, de colonnes et de mines
    int nbLignes, nbColonnes, nbMines;
    cin >> nbLignes >> nbColonnes >> nbMines;

    //saisi des emplacement des mines
    int indexMines[nbMines];
    for (int i = 0 ; i < nbMines ; i++)
        cin >> indexMines[i];
    
    //saisi de l'historique des coups
    int nbCoups;
    cin >> nbCoups;
    Coups coups;
    for (int i = 0 ; i < nbCoups ; i++){
        lireCoups(coups, nbColonnes*nbLignes);
        if (coups.typeCoup == 'M')
            for (int j = 0 ; j < nbMines ; j++){
                if (coups.index == indexMines[j])
                    indexMines[j] = -1;
            }
    }
    
    for (int i = 0 ; i < nbMines ; i++)
        if (indexMines[i] != -1)
            return false;
    return true;

}