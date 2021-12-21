#include<iostream>
#include"commandes.h"

int main(){
    int commande;
    cin >> commande;

    if (commande == 3){
        if (game_won())
            cout << "game won"; 
        else
            cout << "game not won";
    }

    else if (commande == 4){
        if (game_lost()) 
            cout << "game lost"; 
        else
            cout << "game not lost";
    }

    else if (commande == 5)
        cout << "D" << find_move() << endl;

    return 0;
}