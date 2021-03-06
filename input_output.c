// Created by Abhijeet_19370773

#include <stdio.h>
#include "input_output.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n              -----~~ The Board ~~-----            \n");
    printf("     0     1     2     3     4     5     6     7       ");                  /* This prints the co-ordinates of the squares along the top row. */
    printf("\n  <-----x-----x-----x-----x-----x-----x-----x----->\n");

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);                                                               /* This print statement prints the co-ordinates of the squares on the side of the board. */

        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j].type == VALID)
            {
                if(board[i][j].stack == NULL)
                {
                    printf("|     ");
                }

                else
                {
                    if (board[i][j].stack->p_color == GREEN)
                    {
                        printf("| G %d ", board[i][j].num_pieces);
                    }

                    else
                    {
                        printf("| R %d ", board[i][j].num_pieces);
                    }
                }
            }

            else
            {
                printf("|  \\  ");
            }
        }

        printf("|\n  <-----x-----x-----x-----x-----x-----x-----x----->\n");
    }
}