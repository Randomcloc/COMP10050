// Created by Abhijeet_19370773

#include <stdio.h>
#include <stdbool.h>
#include "victory.h"

bool movement(player player1, square board[BOARD_SIZE][BOARD_SIZE])                                         //This function checks if a player can make a move or not...returns a boolean operator.
{
    for (int i = 0; i < BOARD_SIZE; i++)                                                                    //Every piece of the board is checked if a player can use it for movement...
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j].stack != NULL && board[i][j].stack->p_color == player1.player_color)            //If the stack on the square is not NULL and the stack's color is equal to the player color...
            {
                return true;
            }
        }
    }

    //Otherwise...
    return false;
}

player winConditions(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE])                    //This function checks if the winner exists and returns the player that wins...
{
    for (int p = 0; p < PLAYERS_NUM; p++)                                                                   //This loop iterates over both the players.
    {
        if (players[p].pieces_res == 0 && !movement(players[p], board))                                     //If the player has no pieces reserved and the movement for the player is not possible...
        {
            return players[(p + 1) % 2];                                                                    /* Return the OTHER player. */
        }
    }

    player nullplayer = {WHITE, "", 0, 0};                          /* This is an empty player struct and it is returned only if there is no winner. */

    return nullplayer;                                                                                      /* If nullplayer is returned, the game is supposed to continue. */
}

