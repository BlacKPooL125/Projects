#include <stdio.h>
#include <stdbool.h>

void clear_screen() {

    printf("\033[2J\033[H");

}

void blue_text() {

    printf("\033[1;34m");

}

void green_text() {

    printf("\033[1;32m");

}

void red_text() {

    printf("\033[1;31m");

}

void reset_text() {

    printf("\033[0m");

}

void exit_message() {

    clear_screen();
    red_text();
    printf("Exited!\n");
    reset_text();

}

void display_main_menu(int *option) {

    clear_screen();
    blue_text();
    printf("////////// Tic Tac Toe \\\\\\\\\\\\\\\\\\\\");

    printf("\n\n");

    printf("RULES:\n");
    reset_text();
    printf("1. Enter row and column serially without\n   any spaces for example - 12, 23, 31.\n");
    printf("2. Only moves (x, o), rows and columns (1 - 3)\n   can be entered as input.\n");
    printf("3. Any invalid input will not work and\n   user will have to provide valid input.");
    printf("4. Player x always gets the first move\n   so you can toss before starting.");
    
    printf("\n\n");

    blue_text();
    printf("Options:");
    reset_text();
    printf("\n1. Start a game\n2. Exit\n\nEnter an option: ");
    scanf("%d", option);

}

void restart_exit(int *inner_option) {

    blue_text();
    printf("Options:");
    reset_text();
    printf("\n1. Restart\n2. Exit\n\nEnter an option: ");
    scanf("%d", inner_option);

}

void display_board(char board[4][4]) {

    board[0][0] = '#';
    board[0][1] = '1';
    board[0][2] = '2';
    board[0][3] = '3';

    board[1][0] = '1';
    board[2][0] = '2';
    board[3][0] = '3';
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0 || j == 0)
            {
                blue_text();
                printf("%c ", board[i][j]);
                reset_text();
            }
            else
            {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void reset_board(char board[4][4]) {

    board[0][0] = '#';
    board[0][1] = '1';
    board[0][2] = '2';
    board[0][3] = '3';

    board[1][0] = '1';
    board[2][0] = '2';
    board[3][0] = '3';

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            board[i][j] = '-';
        }
    }

}

bool check_win(char board[4][4], char player) {

    bool equal = false;

    for (int i = 1; i < 4; i++)
    {
        if (board[i][1] == player && board[i][2] == player && board[i][3] == player)
        {
            equal = true;
            break;
        }
    }
    
    for (int i = 1; i < 4; i++)
    {
        if (board[1][i] == player && board[2][i] == player && board[3][i] == player)
        {
            equal = true;
            break;
        }
    }

    if (board[1][1] == player && board[2][2] == player && board[3][3] == player)
    {
        equal = true;
    }

    if (board[1][3] == player && board[2][2] == player && board[3][1] == player)
    {
        equal = true;
    }

    return equal;
    
}

void post_game(int *inner_option, char player) {

    clear_screen();
    green_text();
    printf("Player %c wins!", player);
    reset_text();

    while (true)
    {
        printf("\n\n");

        restart_exit(inner_option);

        if (*inner_option == 1)
        {
            break;
        }
        else if (*inner_option == 2)
        {
            break;
        }
        else
        {
            continue;
        }           
    }

}

void draw_message(int *inner_option) {

    clear_screen();
    blue_text();
    printf("DRAW!");
    reset_text();

    while (true)
    {
        printf("\n\n");

        restart_exit(inner_option);

        if (*inner_option == 1)
        {
            break;
        }
        else if (*inner_option == 2)
        {
            break;
        }
        else
        {
            continue;
        }           
    }

}

int main(void) {

    int main_menu_option;
    char board[4][4];
    char player_x = 'x';
    char player_o = 'o';
    bool player_x_wins;
    bool player_o_wins;
    bool is_draw;
    int move, row, col;
    int inner_option;
    int move_counter = 0;

    reset_board(board);

    while (true)
    {
        display_main_menu(&main_menu_option);

        if (main_menu_option == 1)
        {
            while (true)
            {
                
                clear_screen();
                display_board(board);

                printf("Enter player x: ");
                scanf("%d", &move);

                if (move / 100 != 0 || move % 10 < 1 || move % 10 > 3 || (move / 10) % 10 < 1 || (move / 10) % 10 > 3)
                {
                    continue;
                }

                row = (move / 10) % 10;
                col = move % 10;

                board[row][col] = 'x';
                move_counter++;

                clear_screen();
                display_board(board);

                player_x_wins = check_win(board, player_x);

                if (player_x_wins)
                {
                    post_game(&inner_option, player_x);

                    if (inner_option == 1)
                    {
                        reset_board(board);
                        move_counter = 0;
                        continue;
                    }
                    else
                    {
                        clear_screen();
                        exit_message();
                        return 0;
                    }
                }

                if (move_counter == 9)
                {
                    draw_message(&inner_option);

                    if (inner_option == 1)
                    {
                        reset_board(board);
                        move_counter = 0;
                        continue;
                    }
                    else
                    {
                        clear_screen();
                        exit_message();
                        return 0;
                    }
                }

                printf("Enter player 0: ");
                scanf("%d", &move);

                if (move / 100 != 0 || move % 10 < 1 || move % 10 > 3 || (move / 10) % 10 < 1 || (move / 10) % 10 > 3)
                {
                    continue;
                }

                row = (move / 10) % 10;
                col = move % 10;

                board[row][col] = 'o';
                move_counter++;

                player_o_wins = check_win(board, player_o);

                if (player_o_wins)
                {
                    post_game(&inner_option, player_o);

                    if (inner_option == 1)
                    {
                        reset_board(board);
                        move_counter = 0;
                        continue;
                    }
                    else
                    {
                        clear_screen();
                        exit_message();
                        return 0;
                    }
                }
            }
        }
        else if (main_menu_option == 2)
        {
            exit_message();
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;

}
