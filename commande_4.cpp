#include<iostream>
#include"commandes.h"
#include"lire_coups.h"

/**
@brief : indique si la partie est parti ou encore en cours
@return : un booléen
*/
bool game_lost(){
    //saisi du nombre de lignes, de colonnes et de mines
    int nbLignes, nbColonnes, nbMines;
    cin >> nbLignes >> nbColonnes >> nbMines;

    //saisi des emplacement des mines
    int indexMines[nbMines];
    for (int i = 0 ; i < nbMines ; i++)
        cin >> indexMines[i];
    
    //saisi du nombre de coups
    int nbCoups;
    cin >> nbCoups;

    //test d'échec
    Coups coups;
    for (int i = 0 ; i < nbCoups ; i++){
        lireCoups(coups);
        if (coups.typeCoup == 'M')
            for (int j = 0 ; j < nbMines ; j++)
                if (coups.index == indexMines[j])
                    return false;

        else if (coups.typeCoup == 'D')
            for (int j = 0 ; j < nbMines ; j++)
                if (coups.index == indexMines[j])
                    return true;
    }
    return false;
}