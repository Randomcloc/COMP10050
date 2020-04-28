// Created by Abhijeet_19370773

#include<stdio.h>
#include<stdlib.h>
#include "turns.h"

void turns(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE], int turn)                            //This function implements all the movement logic required for the game.
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;                                                                             /* These variables are the co-ordinate holders. */
    char choice = '\0';
    char* colors[2] = {"RED", "GREEN"};

    printf("\n%s's (%s) TURN:\n", players[turn].name, colors[turn]);
    printf("Pieces reserved: %d. Pieces captured: %d.\n", players[turn].pieces_res, players[turn].pieces_cap);

    if(players[turn].pieces_res > 0)
    {
        printf("\nDo you want to place a reserved piece?(y/n): ");
        scanf("\n%c", &choice);

        if(choice == 'y')
        {
            while(board[y1][x1].type == INVALID || board[y1][x1].stack != NULL)                                     //This loop runs until the player selects a VALID stack to move.
            {
                printf("\nSelect where you want to place your piece by entering the coordinates(x and y).\n ");

                printf("Enter the x-coordinates of the square: ");                                                  /* x1 and y1 are the co-ordinate holders for the original stacks. */
                scanf("%d", &x1);

                printf("Enter the y-coordinates of the square: ");
                scanf("%d", &y1);
            }

            if(players[turn].player_color == RED)
            {
                set_red(&board[y1][x1]);
                players[turn].pieces_res--;
            }

            if(players[turn].player_color == GREEN)
            {
                set_green(&board[y1][x1]);
                players[turn].pieces_res--;
            }
        }
    }

    if (choice == '\0' || choice == 'n')
    {
        while(board[y1][x1].type == INVALID)                                                                        //This loop runs until the player selects a VALID stack to move.
        {
                printf("\nSelect WHICH STACK you would like to move by entering the coordinates(x and y).\n ");

                printf("Enter the x-coordinates of the stack: ");                                                   /* x1 and y1 are the co-ordinate holders for the original stacks. */
                scanf("%d", &x1);

                printf("Enter the y-coordinates of the stack: ");
                scanf("%d", &y1);

                if(players[turn].player_color != board[y1][x1].stack->p_color)                                      //If the stack selected is not of the player's own color, then they cannot move it.
                {

                    printf("\nError: Please pick a stack with your piece as the top piece on the stack.\n");        /* An error is printed and the loop restarts because y1 and x1 are set to 0 again. */

                    y1 = 0;
                    x1 = 0;
                }

        }

        while (board[y2][x2].type == INVALID || board[y1][x1].num_pieces < (abs(x2 - x1) + abs(y2 - y1)))            //This loop will run until the selected square that the player wants to move to is VALID.
        {                                                                                                           //The player should only be allowed to move as many steps (or less) as the number of pieces on the stack.
            printf("\nInput the co-ordinates of WHICH SQUARE you would like to move to:\n ");

            printf("Enter the x-coordinates of the place: ");                                                       /* x2 and y2 are co-ordinate holders for the square that the player would like to move to. */
            scanf("%d", &x2);

            printf("Enter the y-coordinates of the place: ");
            scanf("%d", &y2);

        }

        if (board[y1][x1].num_pieces >= (abs(x2 - x1) + abs(y2 - y1)))                                              //If the number of pieces in the stack are greater than the difference in x and y co-ordinates
        {                                                                                                           //Merge the stacks in the two squares.
            mergeStacks(&board[y1][x1], &board[y2][x2]);

            if (board[y2][x2].num_pieces > 5)                                                                       //If the number of pieces on the square that the player moved to are more than 5, remove some pieces.
            {
                removePieces(&board[y2][x2], &players[turn]);
            }
        }
    }


}

void mergeStacks(square* origin, square* new)                                                                       //This function adds two stacks to each other after a movement from the player.
{
    piece* temp = origin->stack;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new->stack;
    new->stack = origin->stack;
    new->num_pieces += origin->num_pieces;
    origin->num_pieces = 0;
    origin->stack = NULL;

}

void removePieces(square* square1, player* player1)
{
    piece* temp = NULL;
    piece* last = NULL;

    while (square1->num_pieces > 5)
    {
        temp = square1->stack;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        last = temp->next;
        square1->num_pieces--;

        if(last->p_color == player1->player_color)
        {
            player1->pieces_res++;
        }

        else
        {
            player1->pieces_cap++;
        }

        temp->next = NULL;
        free(last);

    }
}
