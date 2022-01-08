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
            grille->cases[i][j].estMine = false;
            grille->cases[i][j].estDecouvert = false;
            grille->cases[i][j].estMarquee = false;
            grille->cases[i][j].nbMinesEnvironnantes = 0;
        }
    }
    cout << "1\n";
    //initialisation des cases contenant des mines
    for (int i = 0 ; i < nbMines ; i++)
        cout << indexMines[i]/grille->nbLignes;
        grille->cases[indexMines[i]/grille->nbLignes][indexMines[i]%grille->nbLignes].estMine = true;
    cout << "1\n";
    //initialisations des cases autour des mines
    for (int i = 0 ; i < grille->nbLignes ; i++){
        for (int j = 0 ; j < grille->nbColonnes ; j++){
            if (grille->cases[i][j].estMine){
                if (i > 0)
                    grille->cases[i-1][j].nbMinesEnvironnantes++;
                
                if (i < grille->nbLignes)
                    grille->cases[i+1][j].nbMinesEnvironnantes++;
                
                if (j > 0){
                    grille->cases[i-1][j-1].nbMinesEnvironnantes++;
                    grille->cases[i][j-1].nbMinesEnvironnantes++;
                    grille->cases[i+1][j-1].nbMinesEnvironnantes++;
                }

                if (j < grille->nbColonnes){
                    grille->cases[i-1][j+1].nbMinesEnvironnantes++;
                    grille->cases[i][j+1].nbMinesEnvironnantes++;
                    grille->cases[i+1][j+1].nbMinesEnvironnantes++;
                }
            }
        }
    }

}

int main(){
    Grille grille;
    int nbLignes = 4, nbColonnes = 6;
    int indexMines[] = {1, 5, 12, 7, 19};
    init_grille(&grille, nbLignes, nbColonnes);
    cout << "1\n";
    init_cases(&grille, indexMines, 5);
    cout << "1\n";
    for (int i = 0 ; i < nbLignes ; i++){
        for (int j = 0 ; j < nbColonnes ; j++){
            for(int k = 0 ; k < nbColonnes ; k++)
                cout << " ___";
            cout << '\n';
            for(int l = 0 ; l < nbColonnes ; l++){
                cout << "| ";
                if (grille.cases[i][j].estMine)
                    cout << "M ";
                else if (grille.cases[i][j].nbMinesEnvironnantes == 0)
                    cout << "  ";
                else
                    cout << grille.cases[i][j].nbMinesEnvironnantes << " ";
            }
            cout << "|\n";
        }
    }
    for(int i = 0 ; i < nbColonnes ; i++)
        cout << " ___";
}