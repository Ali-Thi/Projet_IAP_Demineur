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
    grille->cases = new Case*[nbLignes];
    for (int i = 0 ; i < nbLignes ; i++)
        grille->cases[i] = new Case[nbColonnes];
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
            grille->cases[i*grille->nbColonnes+j].estMine = false;
            grille->cases[i*grille->nbColonnes+j].estDecouvert = false;
            grille->cases[i*grille->nbColonnes+j].estMarquee = false;
            grille->cases[i*grille->nbColonnes+j].nbMinesEnvironnantes = 0;
        }
    }

    //initialisation des cases contenant des mines
    for (int i = 0 ; i < nbMines ; i++)
        grille->cases[indexMines[i]].estMine = true;

    //initialisations des cases autour des mines
    for (int i = 0 ; i < grille->nbLignes*grille->nbColonnes ; i++){
        if (grille->cases[i].estMine){
            if (i >= grille->nbColonnes)
                grille->cases[i-grille->nbColonnes-1].nbMinesEnvironnantes++;
                grille->cases[i-grille->nbColonnes].nbMinesEnvironnantes++;
                grille->cases[i-grille->nbColonnes+1].nbMinesEnvironnantes++;
            if (i < grille->nbColonnes*(grille->nbLignes-1)-1)
                grille->cases[i+grille->nbColonnes-1].nbMinesEnvironnantes++;
                grille->cases[i+grille->nbColonnes].nbMinesEnvironnantes++;
                grille->cases[i+grille->nbColonnes+1].nbMinesEnvironnantes++;
            if (i % grille->nbColonnes != 0)
                grille->cases[i-1].nbMinesEnvironnantes++;

            if (i % (grille->nbColonnes-1) != 0 && i != 0)
                grille->cases[i+1].nbMinesEnvironnantes++;

            if (i >= grille->nbColonnes && (i % grille->nbColonnes != 0)
        }
    }

}

int main(){
    Grille grille;
    int nbLignes = 4, nbColonnes = 6;
    int indexMines[] = {1, 5, 12, 7, 19};
    init_grille(&grille, nbLignes, nbColonnes);
    /*init_cases(&grille, indexMines, 4);
    for (int i = 0 ; i < nbLignes ; i++){
        for(int k = 0 ; k < nbColonnes ; k++)
            cout << " ___";
        cout << '\n';
        for(int j = 0 ; j < nbColonnes ; j++){
            cout << "| ";
            if (grille.cases[i*nbColonnes+j].estMine)
                cout << "M ";
            else if (grille.cases[i*nbColonnes+j].nbMinesEnvironnantes == 0)
                cout << "  ";
            else
                cout << grille.cases[i*nbColonnes+j].nbMinesEnvironnantes << " ";
        }
        cout << "|\n";
    }
    for(int k = 0 ; k < nbColonnes ; k++)
        cout << " ___";*/
}