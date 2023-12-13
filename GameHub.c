#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct database {

    char name[100];
    float price;
    int code;

} game;

struct customer {

    char name[100];
    char phone[20];
    char email[100];
    char password[12];
    char gamepal[6];

};

struct admin {

    char name[100];
    char email[100];
    char password[12];

};

void clear_screen() {

    printf("\033[2J");
    printf("\033[H");

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

void display_main_menu() {

    blue_text();
    printf("\nWelcome to GameHub\n");
    reset_text();
    printf("\n1. Display Available Games\n");
    printf("2. Place an Order\n");
    printf("3. Admin Access\n");
    printf("4. Exit\n");

}

void display_item(game array[]) {

    blue_text();
    printf("%-5s  %-35s%-10s\n", "Code", "Game Name", "Price");
    reset_text();

    for (int index = 0; index < 20; index++)
    {
        printf("%-5d  %-35s$%-10.2f\n", array[index].code, array[index].name, array[index].price);
    }

}

void display_info(game array[], int index) {

    printf("Game Name: %s\n", array[index].name);
    printf("Price: $%.2f\n", array[index].price);

}

void exit_program () {

    clear_screen();
    red_text();
    printf("Exited!\n");
    reset_text();

}

void invalid_choice() {

    red_text();
    printf("Invalid Choice!\n");
    reset_text();

}

int main(void) {

    game item[20];
    item[0] = (game){"Assassin's Creed IV: Black Flag", 29.99, 1};
    item[1] = (game){"Baldur's Gate 3", 49.99, 2};
    item[2] = (game){"Call of Duty: Black Ops 2", 39.99, 3};
    item[3] = (game){"Cyberpunk 2077", 59.99, 4};
    item[4] = (game){"DOOM Eternal", 44.99, 5};
    item[5] = (game){"EA Sports FC 24", 34.99, 6};
    item[6] = (game){"Elden Ring", 54.99, 7};
    item[7] = (game){"Far Cry 6", 49.99, 8};
    item[8] = (game){"Forza Horizon 5", 59.99, 9};
    item[9] = (game){"God of War", 39.99, 10};
    item[10] = (game){"Grand Theft Auto V", 29.99, 11};
    item[11] = (game){"Hades", 24.99, 12};
    item[12] = (game){"Marvel's Spider-Man", 49.99, 13};
    item[13] = (game){"Max Payne 3", 19.99, 14};
    item[14] = (game){"Red Dead Redemption 2", 54.99, 15};
    item[15] = (game){"Resident Evil 4", 29.99, 16};
    item[16] = (game){"Starfield", 59.99, 17};
    item[17] = (game){"The Elder Scrolls V: Skyrim", 39.99, 18};
    item[18] = (game){"The Last of Us", 49.99, 19};
    item[19] = (game){"The Witcher 3", 39.99, 20};
   
    int main_action;
    int option1_action1;
    int selected_game_code;
    char selected_game_name[100];
    struct customer customer_access;
    struct admin admin_access;
    float collected_amount;
    float price;
    int otp;
    int requested_otp;
    int option2_action1;
    int option2_action2;
    int action3;
    int option;
    int admin_index;

    srand(time(NULL));

    while (1)
    {
        display_main_menu();

        printf("\nEnter an Option (1 - 4): ");
        scanf("%d", &main_action);

        if (main_action == 1)
        {
            clear_screen();
            printf("Available item Are:\n\n");
            display_item(item);
            
            while (1)
            {
                printf("\n1. Main Menu\n2. Exit\n\nEnter an Option: ");
                scanf("%d", &option1_action1);

                if (option1_action1 == 1)
                {
                    clear_screen();
                    break;
                }
                else if (option1_action1 == 2)
                {
                    exit_program ();
                    return 0;
                }
                else
                {
                    invalid_choice();
                    continue;
                }
            }
        }

        else if (main_action == 2)
        {
            clear_screen();

            while (1)
            {
                printf("Enter Game Code from Displayed item (1 - 20): ");
                scanf("%d", &selected_game_code);

                int game_found = 0;

                printf("\n\n");

                for (int index = 0; index < 20; index++)
                {
                    if (selected_game_code == item[index].code)
                    {
                        display_info(item, index);
                        strcpy(selected_game_name, item[index].name);
                        price = item[index].price;
                        game_found = 1;
                        break;
                    }
                }

                if (game_found != 1)
                {
                    red_text();
                    printf("\n\nInvalid Code!\nPlease try Again!");
                    reset_text();
                    printf("\n\n");
                    continue;
                }
                else
                {
                    break;
                }
                
            }

            printf("\n\n");

            printf("Enter New Username: ");
            scanf("%s", customer_access.name);
            printf("Enter Phone Number: ");
            scanf("%s", customer_access.phone);
            printf("Enter Email: ");
            scanf("%s", customer_access.email);
            printf("Enter a Password (Maximum 12 Characters): ");
            scanf("%s", customer_access.password);
            printf("Enter Your GamePal Account Number (6 Digits): ");
            scanf("%s", customer_access.gamepal);

            clear_screen();
            float final_amount = price + (price * 0.10);
            printf("Total Amount to be Paid Including 10%% VAT: $%.2f\n", final_amount);
            
            while (1)
            {
                printf("Enter Amount to Collect From Your GamePal: ");
                scanf("%f", &collected_amount);

                if (collected_amount < final_amount)
                {
                    red_text();
                    printf("\nInsufficient Funds!\nPlease Try Again!\n\n");
                    reset_text();
                    continue;
                }
                else
                {
                    break;
                }
            }

            printf("\n\n");

            printf("An OTP Code Has Been Sent to You\n");

            otp = rand() % 90001 + 510000;
            
            blue_text();
            printf("\nYour OTP Code is: %d\n", otp);
            reset_text();

            while (1)
            {
                printf("\nEnter Your OTP Code: ");
                scanf("%d", &requested_otp);

                if (requested_otp != otp)
                {
                    red_text();
                    printf("\nOTP did not Match!\nPlease Try Again!\n");
                    reset_text();
                    continue;
                }

                printf("\n\n");
            
                printf("1. Confirm Order\n2. Cancel Order\n\nEnter an Option: ");
                scanf("%d", &option);

                if (option == 1)
                {
                    clear_screen();

                    green_text();
                    printf("Order Confirmed!\n");
                    printf("Transaction Successful!\n");
                    reset_text();

                    printf("\nGame: %s\n", selected_game_name);
                    printf("Customer: %s\n", customer_access.name);
                    printf("Customer Phone: %s\n", customer_access.phone);
                    printf("Customer Email: %s\n", customer_access.email);
                    printf("Customer GamePal Account Number: %s\n", customer_access.gamepal);
                    printf("Collected collected_amount: $%.2f\n", collected_amount);
                    printf("Paid collected_amount Including 10%% VAT: $%.2f\n", final_amount);
                    printf("Returned collected_amount: $%.2f\n", (collected_amount - final_amount));

                    blue_text();
                    printf("\nThank You for Your Purchase!\n");
                    reset_text();

                    printf("\n1. Main Menu\n2. Exit\n\nEnter an Option: ");
                    scanf("%d", &option2_action1);

                    if (option2_action1 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else if (option2_action1 == 2)
                    {
                        exit_program ();
                        return 0;
                    }
                    else
                    {
                        invalid_choice();
                        continue;
                    }
                }
                else if (option == 2)
                {
                    red_text();
                    printf("Order Cancelled!\n");
                    reset_text();

                    while (1)
                    {
                        printf("\n1. Main Menu\n2. Exit\n\nEnter an Option: ");
                        scanf("%d", &option2_action2);

                        if (option2_action2 == 1)
                        {
                            clear_screen();
                            break;
                        }
                        else if (option2_action2 == 2)
                        {
                            exit_program ();
                            return 0;
                        }
                        else
                        {
                            invalid_choice();
                            continue;
                        }
                    }
                    if (option2_action2 == 1)
                    {
                        clear_screen();
                        break;
                    }
                }
                else
                {
                    invalid_choice();
                }
            }
        }

        else if (main_action == 3)
        {
            int admin_choice;

            clear_screen();

            blue_text();
            printf("Welcome to Admin Access!\n");
            reset_text();

            printf("\nEnter Admin Username: ");
            scanf("%s", admin_access.name);
            printf("Enter Admin Email: ");
            scanf("%s", admin_access.email);
            printf("Enter Password (Maximum 12 Characters): ");
            scanf("%s", admin_access.password);

            while (1)
            {
                clear_screen();

                printf("1. Add a New Game to Replace one\n2. Exit\n\nEnter an Option: ");
                scanf("%d", &admin_choice);

                if (admin_choice == 1)
                {
                    clear_screen();

                    printf("Enter Code of the Game You Want to Replace: ");
                    scanf("%d", &admin_index);

                    if (admin_index < 1 || admin_index > 20)
                    {
                        invalid_choice();
                        continue;
                    }

                    for (int index = 0; index < 20; index++)
                    {
                        if (admin_index == item[index].code)
                        {
                            blue_text();
                            printf("\nThe Game You Want to Replace is:");
                            reset_text();
                            printf("\n\n");
                            display_info(item, index);
                            printf("\nEnter Name of New Game: ");
                            scanf("%s", item[index].name);
                            printf("Enter Price of New Game: ");
                            scanf("%f", &item[index].price);
                            green_text();
                            printf("\n\nNew Game Added Successfully!");
                            reset_text();
                            printf("\n\n");
                            blue_text();
                            printf("The New Game is:");
                            reset_text();
                            printf("\n\n");
                            display_info(item, index);
                        }
                    }

                    printf("\n\n1. Admin Menu\n2. Exit\n\nEnter an Option: ");
                    scanf("%d", &action3);

                    if (action3 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else if (action3 == 2)
                    {
                        exit_program ();
                        return 0;
                    }
                    else
                    {
                        invalid_choice();
                        continue;
                    }
                }
                else if (admin_choice == 2)
                {
                    clear_screen();
                    break;
                }
                else
                {
                    invalid_choice();
                    continue;
                }
            }
        }

        else if (main_action == 4)
        {
            exit_program ();
            break;
        }

        else
        {
            invalid_choice();
            clear_screen();
            continue;
        }
    }

    return 0;
}
