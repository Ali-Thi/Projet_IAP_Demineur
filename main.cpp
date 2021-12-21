#include<iostream>
#include"commandes.h"

int main(){
    int commande;

    while (1){
        cin >> commande;
        switch(commande){
            case 0 : 
                exit(0); break;
            case 3 : 
                if (game_won()) 
                    cout << "game won"; 
                else
                    cout << "game not won";
                break;
            case 4 :
                if (game_lost()) 
                    cout << "game lost"; 
                else
                    cout << "game not lost";
                break;
        }
    }
}