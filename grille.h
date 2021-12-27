#ifndef GRILLE
#define GRILLE

using namespace std;

struct Case{
    bool estMine;
    bool estDecouvert;
    bool estMarquee;
    int nbMinesEnvironnantes;
};

struct Grille{
    int nbLignes;
    int nbColonnes;
};

/**
@brief : alloue dynamiquement la matrice représentant la grille
@param [in, out] grille : la grille
@param [in] nbLignes : le nombre de lignes de la matrice
@param [in] nbColonnes : le nombre de colonnes de la matrice
*/
void init_grille(Grille* grille, const int nbLignes, const int nbColonnes);

/**
@brief : initialise les valeursdes cases d'une grille
@param [in, out] grille : la grille
@param [in] indexMines : tableau contenant les index des mines
@param [in] nbMines : le nombre de mines
*/
void init_cases(Grille* grille, int indexMines[], int nbMines);

#endif