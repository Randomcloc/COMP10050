// Created by Abhijeet_19370773

#include <stdio.h>
#include "input_output.h"
#include "turns.h"
#include "victory.h"

int main(void)
{
    //Declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    //Declaration of the turn counter and the holder for the winner of the game.
    int turn = 0;
    int num_turns;
    player winner;

    //Describes the rules of the game.
    printf("WELCOME TO FOCUS!\n\nRULES: You can move your own pieces to other squares.\nThe distance you move is equal to or less than the size of the stack, indicated by the number on the square\n");
    printf("Once a stack of pieces reach a height more than 5, the pieces from the bottom of the stack are removed.\nYour own pieces removed are the reserved pieces that you can place on an empty square again.\n");
    printf("The opponents pieces removed are your captured pieces.\nThe goal is to make the opponent unable to make a move.\nENJOY!\n");

    //Call the initializing functions.
    initialize_players(players);
    initialize_board(board);
    print_board(board);

    while (turn >= 0)                                       //The loop runs through, each time calling the turns(), print_board() and winConditions() functions, incrementing turns.
    {
        turns(players, board, turn % 2);
        print_board(board);

        winner = winConditions(players, board);

        num_turns = turn;                                  /* The num_turns is just going to be used to print the number of turns at the end. */

        if (winner.player_color != WHITE)                  //If the player color is white, then the empty struct was returned, which meant that the game still continues.
        {
            turn = -1;                                     /* Since we set turn to -1 to end the loop, our turns counter is gone, so we need the num_turns. */
        }

        turn++;
    }

    //Winner declaration...
    printf("\nCONGRATULATIONS %s, you WON!\n", winner.name);
    printf("Extra Stats:\nNumber Of Turns: %d\nPieces Reserved: %d\nPieces Captured: %d\n", (num_turns + 1), winner.pieces_res, winner.pieces_cap);

    return 0;
}
