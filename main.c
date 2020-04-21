//
// Created by Lili on 26/03/2020.
//

#include <stdio.h>

#include "input_output.h"
#include "turns.h"

int main()
{
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    int turn = 0;

    initialize_players(players);

    initialize_board(board);

    print_board(board);

    while (1)
    {
        turns(players, board, turn);
        print_board(board);
    }

    return 0;
}
