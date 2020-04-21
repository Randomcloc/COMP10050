// Created by Abhijeet_19370773

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM])
{
    char color;
                                                                // implement here the functionality to initialize the players
    for (int i = 0; i < PLAYERS_NUM; i++)
    {
        printf("Player %d, enter your name: ", (i + 1));
        scanf("%s", players[i].name);

        if (i == 0)
        {
            printf("Enter which color you would like, Red(R) or Green(G)?: ");
            scanf("\n%c", &color);

            while (color != 'G' && color != 'R')
            {
                printf("Enter which color you would like, Red(R) or Green(G)?: ");
                scanf("\n%c", &color);

            }

            if (color == 'G')
            {
                players[i].player_color = GREEN;
                color = 'R';

                printf("\nPlayer 2 is Red(R). ");
            }

            else if (color == 'R')
            {
                players[i].player_color = RED;
                color = 'G';

                printf("\nPlayer 2 is Green(G). ");
            }
        }
    }
}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }
    }
}

void turns(player players[PLAYERS_NUM], square board [BOARD_SIZE][BOARD_SIZE])
{
    int x, y;
    char direc[5];

    printf("Select which stack you would like to move by entering the coordinates(x and y).\n ");

    printf("Enter the x-coordinates of the stack: ");
    scanf("%d", &x);

    printf("\nEnter the y-coordinates of the stack: ");
    scanf("%d", &y);

    if(board[y][x].type == VALID)
    {
        printf("\nInput your moves in sequence, eg. UP(u), DOWN(d), LEFT(l), RIGHT(r) based on the number of pieced in your stack: ");
        scanf("%s", direc);

        for (int i = 0; i < strlen(direc), i++)
        {
            if(direc[i] == 'u')
            {
                y--;
            }

            else if(direc[i] == 'd')
            {
                y++;
            }

            else if(direc[i] == 'l')
            {
                x--;
            }

            else if(direc[i] == 'r')
            {
                x++;
            }
        }
    }

}

