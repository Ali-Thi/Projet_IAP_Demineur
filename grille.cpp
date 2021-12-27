#include<iostream>
#include"grille.h"

/**
@brief : alloue dynamiquement la matrice représentant la grille
@param [in, out] grille : la grille
@param [in] nbLignes : le nombre de lignes de la matrice
@param [in] nbColonnes : le nombre de colonnes de la matrice
*/
void init_grille(Grille* grille, const int nbLignes, const int nbColonnes){
    grille->nbLignes = nbLignes;
    grille->nbColonnes = nbColonnes;
    grille = new Case[nbColonnes*nbLignes];
}

/**
@brief : initialise les valeursdes cases d'une grille
@param [in, out] grille : la grille
@param [in] indexMines : tableau contenant les index des mines
@param [in] nbMines : le nombre de mines
*/
void init_cases(Grille* grille, int indexMines[], int nbMines){
    //initialisation des valeurs par défauts des cases
    for (int i = 0 ; i < grille->nbLignes ; i++){
        for (int j = 0 ; j < grille->nbColonnes ; j++){
            grille[i*grille->nbColonnes+j].estMine = false;
            grille[i*grille->nbColonnes+j].estDecouvert = false;
            grille[i*grille->nbColonnes+j].estMarquee = false;
            grille[i*grille->nbColonnes+j].nbMinesEnvironnantes = 0;
    }

    //initialisation des cases contenant des mines
    for (int i = 0 ; i < nbMines ; i++)
        grille[indexMines[i]]->estMine = true;

    //initialisations des cases autour des mines
    for (int i = 0 ; i < grille->nbLignes*grille->nbColonnes ; i++){
        if (grille[i].estMine){
            if (i > 0){
                grille[i-grille->nbColonnes-1].nbMinesEnvironnantes++;
                grille[i-grille->nbColonnes].nbMinesEnvironnantes++;
                grille[i-grille->nbColonnes+1].nbMinesEnvironnantes++;
            }
            if (i < grille->nbLignes-1){
                grille[i+grille->nbColonnes-1].nbMinesEnvironnantes++;
                grille[i+grille->nbColonnes].nbMinesEnvironnantes++;
                grille[i+grille->nbColonnes+1].nbMinesEnvironnantes++;
            }
            if (j > 0)
                grille[i-1].nbMinesEnvironnantes++;

            if (j < grille->nbColonnes-1)
                grille[i+1].nbMinesEnvironnantes++;
        }
    }

}


int main(){
    Grille* grille;
    init_grille(grille, 4, 6);
    init_cases(grille, {1, 5, 4, 6, 7}, 5); 
}