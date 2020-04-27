// Created by Abhijeet_19370773

#include<stdio.h>
#include<stdlib.h>
#include "turns.h"

void turns(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE], int turn)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    printf("\n%s'S TURN:\n", players[turn].name);


    while(board[y1][x1].type == INVALID)
    {
            printf("\nSelect WHICH STACK you would like to move by entering the coordinates(x and y).\n ");

            printf("Enter the x-coordinates of the stack: ");
            scanf("%d", &x1);

            printf("Enter the y-coordinates of the stack: ");
            scanf("%d", &y1);

            if(players[turn].player_color != board[y1][x1].stack->p_color)
            {
                printf("\nError: Please pick a stack with your piece as the top piece on the stack.\n");

                y1 = 0;
                x1 = 0;
            }

    }

    while(board[y2][x2].type == INVALID || board[y1][x1].num_pieces < (abs(x2 - x1) + abs(y2 - y1)))
    {
        printf("\nInput the co-ordinates of WHICH SQUARE you would like to move to:\n ");

        printf("Enter the x-coordinates of the place: ");
        scanf("%d", &x2);

        printf("Enter the y-coordinates of the place: ");
        scanf("%d", &y2);

    }

    if (board[y1][x1].num_pieces >= (abs(x2 - x1) + abs(y2 - y1)))
    {
        mergeStacks(&board[y1][x1], &board[y2][x2]);

        if (board[y2][x2].num_pieces > 5)
        {
            removePieces(&board[y2][x2], players);
        }
    }


}

void mergeStacks(square* origin, square* new)
{
    piece* temp_stack = origin->stack;
    piece* temp = temp_stack;

    int i = 0;

    while(temp->next != NULL)
    {
        temp = temp->next;

        i++;
    }

    i++;

    temp->next = new->stack;
    origin->stack = NULL;
    origin->num_pieces = 0;
    new->num_pieces = i + new->num_pieces;
    new->stack = temp_stack;

}

void removePieces(square* square1, player players[PLAYERS_NUM])
{
    piece* temp = square1->stack;

    int i = 0;

    while(temp->next != NULL)
    {
        if(i >= 5)
        {
            if(temp->p_color == players->player_color)
            {
                players->pieces_res++;

            }

            else
            {
                players->pieces_cap++;
            }
        }

        temp = temp->next;

        if(i == 4)
        {
            temp->next = NULL;

            square1->num_pieces = 5;
        }

        i++;

    }
}
