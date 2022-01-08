#include<iostream>
#include"commandes.h"
#include"grille.h"
#include"lire_coups.h"

void print_grille(){
    Grille grille;
    //saisi du nombre de lignes, de colonnes et de mines
    int nbLignes, nbColonnes, nbMines;
    cin >> nbLignes >> nbColonnes >> nbMines;

    init_grille(&grille, nbLignes, nbColonnes);

    //saisi des emplacement des mines
    int indexMines[nbMines];
    for (int i = 0 ; i < nbMines ; i++)
        cin >> indexMines[i];

    init_cases(&grille, indexMines, nbMines);    
    
    for (int i = 0 ; i < nbLignes ; i++){
        for(int k = 0 ; k < nbColonnes ; k++)
            cout << " ___";
        cout << '\n';
        for(int j = 0 ; j < nbColonnes ; j++){
            cout << "| ";
            if (grille.cases[i*nbColonnes+j].estMine)
                cout << 'M';
            else if (grille.cases[i*nbColonnes+j].nbMinesEnvironnantes == 0)
                cout << " ";
            else
                cout << grille.cases[i*nbColonnes+j].nbMinesEnvironnantes;
        }
    }
}