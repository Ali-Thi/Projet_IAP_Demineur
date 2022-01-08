#include<iostream>
#include"commandes.h"

bool is_contain_in_tab(int element, int tab[], int sizeTab){
    for (int i = 0 ; i < sizeTab ; i++)
        if (tab[i] == element)
            return true;
    return false;
}

void make_problem(){
    //saisi du nombre de lignes, de colonnes et de mines
    int nbLignes, nbColonnes, nbMines;
    cin >> nbLignes >> nbColonnes >> nbMines;
    cout << nbLignes << ' ' << nbColonnes << ' ' << nbMines << ' ';

    int indexMines[nbMines];
    int indexMinesSave;

    for (int i = 0 ; i < nbMines ; i++){
        indexMinesSave = rand()%(nbColonnes*nbLignes);
        if (!is_contain_in_tab(indexMinesSave, indexMines, nbMines))
            indexMines[i] = indexMinesSave;
        else
            i--;
    }

    for (int i = 0 ; i < nbMines ; i++)
        cout << indexMines[i] << ' ';
    cout << endl;
}
