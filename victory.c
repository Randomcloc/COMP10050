// Created by Abhijeet_19370773

#include <stdio.h>
#include <stdbool.h>
#include "victory.h"

bool movement(player player1, square board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j].stack != NULL && board[i][j].stack->p_color == player1.player_color)
            {
                return true;
            }
        }
    }

    return false;
}

player winConditions(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE])
{
    for (int p = 0; p < PLAYERS_NUM; p++)
    {
        if (players[p].pieces_res == 0 && !movement(players[p], board))
        {
            if (players[p].player_color == GREEN)
            {
                return players[0];
            }

            else
            {
                return players[1];
            }

        }
    }

    player nullplayer = {WHITE, "", 0, 0};

    return nullplayer;
}

