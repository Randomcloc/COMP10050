// Created by Abhijeet_19370773

#include <stdio.h>
#include "input_output.h"
#include "turns.h"
#include "victory.h"

int main(void)
{
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    int turn = 0;
    player winner;

    printf("WELCOME TO FOCUS!\n\nRULES: You can move your own pieces to other squares.\nThe distance you move is equal to or less than the size of the stack, indicated by the number on the square\n");
    printf("Once a stack of pieces reach a height more than 5, the pieces from the bottom of the stack are removed.\nYour own pieces removed are the reserved pieces that you can place on an empty square again.\n");
    printf("The opponents pieces removed are your captured pieces.\nThe goal is to make the opponent unable to make a move.\nENJOY!\n");

    initialize_players(players);
    initialize_board(board);
    print_board(board);

    while (turn >= 0)
    {
        turns(players, board, turn % 2);
        print_board(board);

        winner = winConditions(players, board);

        if (winner.player_color != WHITE)
        {
            turn = -1;
        }

        turn++;
    }

    //winner declaration...

    printf("\nCONGRATULATIONS %s, you WON!\n", winner.name);

    return 0;
}
