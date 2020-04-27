// Created by Abhijeet_19370773

#include <stdio.h>
#include "input_output.h"
#include "turns.h"

int main(void)
{
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    int turn = 0;

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    while (turn >= 0)
    {

        turns(players, board, turn % 2);
        print_board(board);

        turn++;
    }

    return 0;
}
