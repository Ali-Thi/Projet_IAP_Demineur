/**
@file : commandes.h
Projet : minesweeper
@author : TALHAOUI Ali 
@version : 1 21/12/21
@brief : fonctions de creation ou d'interpretation d'une partie de demineur
*/
#ifndef COMMANDES
#define COMMANDES

using namespace std;

/**
@brief : renvoie un booleen pour indiquer si la partie est gagné ou toujours en cours
@return : un booleen
*/
bool game_won();

/**
@brief : indique si la partie est parti ou encore en cours
@return : un booléen
*/
bool game_lost();

/**
@brief : trouve une case a demasquer ou affiche une erreur si elle n'en troupe pas
@return : l'index d'une case
*/
int find_move();

#endif