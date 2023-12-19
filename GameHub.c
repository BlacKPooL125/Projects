#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct game_database {

    char name[100];
    float price;
    int code;

} game;

typedef struct customer_database {

    char name[100];
    char phone[12];
    char email[50];
    char password[7];
    char gamepal[7];

} customer;

typedef struct admin_database {

    char name[100];
    int passcode;

} admin;

void real_time(char time_string[30]) {

    time_t current_time;
    struct tm *time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    strcpy(time_string, asctime(time_info));

}

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

void display_main_menu() {

    blue_text();
    printf("\n-------------------\nWelcome to GameHub\n-------------------\n");
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

void exit_program() {

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

void main_menu_or_exit(int *option) {

    while (1)
    {
        printf("\n1. Main Menu\n2. Exit\n\nEnter an Option: ");
        scanf("%d", option);

        if (*option == 1)
        {
            clear_screen();
            break;
        }
        else if (*option == 2)
        {
            exit_program();
            break;
        }
        else
        {
            invalid_choice();
            continue;
        }
    }
}

int main(void) {

    game item[20];
    item[0] = (game){"Assassin's_Creed_IV:_Black_Flag", 29.99, 1};
    item[1] = (game){"Baldur's_Gate_3", 49.99, 2};
    item[2] = (game){"Call_of_Duty:_Black_Ops_2", 39.99, 3};
    item[3] = (game){"Cyberpunk_2077", 59.99, 4};
    item[4] = (game){"DOOM_Eternal", 44.99, 5};
    item[5] = (game){"EA_Sports_FC_24", 34.99, 6};
    item[6] = (game){"Elden_Ring", 54.99, 7};
    item[7] = (game){"Far_Cry_6", 49.99, 8};
    item[8] = (game){"Forza_Horizon_5", 59.99, 9};
    item[9] = (game){"God_of_War", 39.99, 10};
    item[10] = (game){"Grand_Theft_Auto_V", 29.99, 11};
    item[11] = (game){"Hades", 24.99, 12};
    item[12] = (game){"Marvel's_Spider-Man", 49.99, 13};
    item[13] = (game){"Max_Payne_3", 19.99, 14};
    item[14] = (game){"Red_Dead_Redemption_2", 54.99, 15};
    item[15] = (game){"Resident_Evil_4", 29.99, 16};
    item[16] = (game){"Starfield", 59.99, 17};
    item[17] = (game){"The_Elder_Scrolls_V:_Skyrim", 39.99, 18};
    item[18] = (game){"The_Last_of_Us", 49.99, 19};
    item[19] = (game){"The_Witcher_3", 39.99, 20};
   
    int main_action;
    int option1_action1;
    int selected_game_code;
    char selected_game_name[100];
    customer customer_access;
    admin admin_access;
    admin fixed_admin;
    strcpy(fixed_admin.name, "GameHub");
    fixed_admin.passcode = 232526;
    float collected_amount;
    float price;
    char time_string[30];
    int otp;
    int requested_otp;
    int option2_action1;
    int option2_action2;
    int option2_action3;
    int option3_action1;
    int admin_index;

    srand(time(NULL));

    while (1)
    {
        clear_screen();
        display_main_menu();

        printf("\nEnter an Option (1 - 4): ");
        scanf("%d", &main_action);

        if (main_action == 1)
        {
            clear_screen();
            printf("Available items Are:\n\n");
            display_item(item);
            
            main_menu_or_exit(&option1_action1);

            if (option1_action1 == 1)
            {
                clear_screen();
                continue;
            }
            else
            {
                return 0;
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

            printf("Enter New Username (Use '_' Instead of White Spaces): ");
            scanf("%s", customer_access.name);
            printf("Enter Phone Number: ");
            scanf("%s", customer_access.phone);
            printf("Enter Email: ");
            scanf("%s", customer_access.email);
            printf("Enter a Password (Maximum 6 Characters): ");
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
                printf("\nEnter Your OTP Code (6 Digits): ");
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
                scanf("%d", &option2_action1);

                if (option2_action1 == 1)
                {
                    clear_screen();

                    green_text();
                    printf("Order Confirmed!\n");
                    printf("Transaction Successful!\n");
                    reset_text();

                    real_time(time_string);

                    printf("\nGame: %s\n", selected_game_name);
                    printf("Customer: %s\n", customer_access.name);
                    printf("Customer Phone: %s\n", customer_access.phone);
                    printf("Customer Email: %s\n", customer_access.email);
                    printf("Customer GamePal Account Number: %s\n", customer_access.gamepal);
                    printf("Collected Amount: $%.2f\n", collected_amount);
                    printf("Paid Amount Including 10%% VAT: $%.2f\n", final_amount);
                    printf("Returned Amount: $%.2f\n", (collected_amount - final_amount));
                    printf("Time of Purchase: %s\n", time_string);

                    blue_text();
                    printf("\nThank You for Your Purchase!\n");
                    reset_text();

                    main_menu_or_exit(&option2_action2);

                    if (option2_action2 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else
                    {
                        return 0;
                    }
                    
                }
                else if (option2_action1 == 2)
                {
                    red_text();
                    printf("Order Cancelled!\n");
                    reset_text();

                    main_menu_or_exit(&option2_action3);
                    
                    if (option2_action3 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else
                    {
                        return 0;
                    }
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

            while (1)
            {
                printf("\nEnter Admin Username (No White Spaces): ");
                scanf("%s", admin_access.name);
                printf("Enter Passcode (Fixed 6 Digits): ");
                scanf("%d", &admin_access.passcode);
                 
                if (strcmp(admin_access.name, fixed_admin.name) == 0 && admin_access.passcode == fixed_admin.passcode)
                {
                    break;
                }
                else
                {
                    red_text();
                    printf("\n\nInvalid Username or Password!\nPlease Try Again!\n");
                    reset_text();
                    continue;
                }
            }

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
                            printf("\nEnter Name of New Game (Use '_' Instead of White Spaces): ");
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

                    main_menu_or_exit(&option3_action1);

                    if (option3_action1 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (admin_choice == 2)
                {
                    exit_program();
                    return 0;
                }
                else
                {
                    invalid_choice();
                    continue;
                }
            }

            if (option3_action1 == 1)
            {
                continue;
            }
        }

        else if (main_action == 4)
        {
            exit_program();
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
