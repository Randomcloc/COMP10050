// Created by Abhijeet Suryawanshi on 21/04/2020.

#ifndef FOCUS_TURNS_H
#define FOCUS_TURNS_H

#include "game_init.h"

void turns(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE], int turn);
void mergeStacks(square* origin, square* new);

#endif //FOCUS_TURNS_H
