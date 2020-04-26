// Created by Abhijeet_19370773

#ifndef FOCUS_TURNS_H
#define FOCUS_TURNS_H

#include "game_init.h"

void turns(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE], int turn);
void mergeStacks(square* origin, square* new);
void removePieces(square* square1);

#endif //FOCUS_TURNS_H
