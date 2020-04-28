// Created by Abhijeet_19370773

#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM])                                                //This function asks the players for their details and assigns a color to them.
{
    printf("\nPlayer 1 is Red, Player 2 is Green.\n");

    for (int i = 0; i < PLAYERS_NUM; i++)                                                           //The for() loop runs twice for each player's documentation of details.
    {
        printf("Player %d, enter your name: ", (i + 1));                                            /* The name of the player is asked and stored in the player struct. */
        scanf("%s", players[i].name);

        players[i].player_color = (enum color)i;                                                    //The rest of the player's details are initialized.
        players[i].pieces_res = 0;
        players[i].pieces_cap = 0;

    }
}

//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square *s) {
    s->type = INVALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square *s) {
    s->type = VALID;
    s->stack = NULL;
    s->num_pieces = 0;

}

//Set squares  with a GREEN piece
void set_green(square *s) {
    s->type = VALID;
    s->stack = (piece *) malloc(sizeof(piece));
    s->stack->p_color = GREEN;
    s->stack->next = NULL;
    s->num_pieces = 1;

}

//Set squares with a RED piece
void set_red(square *s) {
    s->type = VALID;
    s->stack = (piece *) malloc(sizeof(piece));
    s->stack->p_color = RED;
    s->stack->next = NULL;
    s->num_pieces = 1;

}

//initializes the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //invalid squares
            if ((i == 0 && (j == 0 || j == 1 || j == 6 || j == 7)) ||
                (i == 1 && (j == 0 || j == 7)) ||
                (i == 6 && (j == 0 || j == 7)) ||
                (i == 7 && (j == 0 || j == 1 || j == 6 || j == 7)))
                set_invalid(&board[i][j]);

            else {
                //squares with no pieces
                if (i == 0 || i == 7 || j == 0 || j == 7)
                    set_empty(&board[i][j]);
                else {
                    //squares with red pieces
                    if ((i % 2 == 1 && (j < 3 || j > 4)) ||
                        (i % 2 == 0 && (j == 3 || j == 4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }
    }
}


