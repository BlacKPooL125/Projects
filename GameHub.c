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
   

    int action;
    int inner_action;
    int game_choice;
    char new_name[100];
    struct customer new_customer;
    struct admin new_admin;
    float amount;
    float price;
    int otp;
    int new_otp;
    int action2;
    int action2_1;
    int action3;
    int option;
    int admin_index;
    srand(time(NULL));

    while (1)
    {
        blue_text();
        printf("\nWelcome to GameHub\n");
        reset_text();
        printf("\n1. Display Available Games\n");
        printf("2. Place an Order\n");
        printf("3. Admin Access\n");
        printf("4. Exit\n");
        printf("\nEnter a Choice (1 - 4): ");
        scanf("%d", &action);

        if (action == 1)
        {
            clear_screen();
            printf("Available item Are:\n\n");
            display_item(item);
            
            while (1)
            {
                printf("\n1. Main Menu\n2. Exit\n\nEnter: ");
                scanf("%d", &inner_action);
                if (inner_action == 1)
                {
                    clear_screen();
                    break;
                }
                else if (inner_action == 2)
                {
                    clear_screen();
                    red_text();
                    printf("Exited!\n");
                    reset_text();
                    return 0;
                }
                else
                {
                    red_text();
                    printf("Invalid Choice!\n");
                    reset_text();
                    continue;
                }
            }
        }
        else if (action == 2)
        {
            clear_screen();
            printf("Enter Game Code from Displayed item (1 - 20): ");
            scanf("%d", &game_choice);

            printf("\n\n");

            for (int index = 0; index < 20; index++)
            {
                if (game_choice == item[index].code)
                {
                    display_info(item, index);
                    strcpy(new_name, item[index].name);
                    price = item[index].price;
                    break;
                }
            }

            printf("\n\n");

            printf("Enter New Username: ");
            scanf("%s", new_customer.name);
            printf("Enter Phone Number: ");
            scanf("%s", new_customer.phone);
            printf("Enter Email: ");
            scanf("%s", new_customer.email);
            printf("Enter a Password (Maximum 12 Characters): ");
            scanf("%s", new_customer.password);
            printf("Enter Your GamePal Account Number (6 Digits): ");
            scanf("%s", new_customer.gamepal);

            clear_screen();
            float final_amount = price + (price * 0.10);
            printf("Amount to be Paid Including 10%% VAT: $%.2f\n", final_amount);
            printf("Enter Amount to Collect From Your GamePal: ");
            scanf("%f", &amount);

            printf("\n\n");

            printf("An OTP Code Has Been Sent to You\n");

            otp = rand() % 90001 + 510000;
            
            blue_text();
            printf("Your OTP Code is: %d\n", otp);
            reset_text();

            while (1)
            {
                printf("\nEnter Your OTP Code: ");
                scanf("%d", &new_otp);

                if (new_otp != otp)
                {
                    red_text();
                    printf("\nOTP did not Match!\nPlease Try Again!\n");
                    reset_text();
                    continue;
                }

                printf("\n\n");
            
                printf("1. Confirm Order\n2. Cancel Order\nEnter: ");
                scanf("%d", &option);

                if (option == 1)
                {
                    clear_screen();
                    green_text();
                    printf("Order Confirmed!\n");
                    printf("Transaction Successful!\n");
                    reset_text();
                    printf("\nGame: %s\n", new_name);
                    printf("Customer: %s\n", new_customer.name);
                    printf("Customer Phone: %s\n", new_customer.phone);
                    printf("Customer Email: %s\n", new_customer.email);
                    printf("Customer GamePal Account Number: %s\n", new_customer.gamepal);
                    printf("Collected Amount: $%.2f\n", amount);
                    printf("Paid Amount Including 10%% VAT: $%.2f\n", final_amount);
                    printf("Returned Amount: $%.2f\n", (amount - final_amount));
                    blue_text();
                    printf("\nThank You for Your Purchase!\n");
                    reset_text();
                    printf("\n1. Main Menu\n2. Exit\nEnter: ");
                    scanf("%d", &action2);
                    if (action2 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else if (action2 == 2)
                    {
                        clear_screen();
                        red_text();
                        printf("Exited!");
                        reset_text();
                        return 0;
                    }
                    else
                    {
                        red_text();
                        printf("Invalid Choice!\n");
                        reset_text();
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
                        printf("\n1. Main Menu\n2. Exit\nEnter: ");
                        scanf("%d", &action2_1);
                        if (action2_1 == 1)
                        {
                            clear_screen();
                            break;
                        }
                        else if (action2_1 == 2)
                        {
                            clear_screen();
                            red_text();
                            printf("Exited!");
                            reset_text();
                            return 0;
                        }
                        else
                        {
                            red_text();
                            printf("Invalid Choice!\n");
                            reset_text();
                            continue;
                        }
                    }
                    if (action2_1 == 1)
                    {
                        clear_screen();
                        break;
                    }
                }
                else
                {
                    red_text();
                    printf("Invalid Choice!\n");
                    reset_text();
                }
            }
        }
        else if (action == 3)
        {
            int admin_choice;
            clear_screen();
            blue_text();
            printf("Welcome to Admin Access!\n");
            reset_text();

            printf("\nEnter Admin Username: ");
            scanf("%s", new_admin.name);
            printf("Enter Admin Email: ");
            scanf("%s", new_admin.email);
            printf("Enter Password (Maximum 12 Characters): ");
            scanf("%s", new_admin.password);

            while (1)
            {
                clear_screen();
                printf("1. Add a New Game to Replace one\n2. Exit\nEnter: ");
                scanf("%d", &admin_choice);

                if (admin_choice == 1)
                {
                    clear_screen();
                    printf("Enter Code of the Game You Want to Replace: ");
                    scanf("%d", &admin_index);
                    if (admin_index < 1 || admin_index > 20)
                    {
                        red_text();
                        printf("Invalid Code!\n");
                        reset_text();
                        continue;
                    }
                    for (int index = 0; index < 20; index++)
                    {
                        if (admin_index == item[index].code)
                        {
                            printf("\nThe Game You Want to Replace is:\n");
                            display_info(item, index);
                            printf("\nEnter Name of New Game: ");
                            scanf("%s", item[index].name);
                            printf("Enter Price of New Game: ");
                            scanf("%f", &item[index].price);
                            green_text();
                            printf("\n\nNew Game Added Successfully!\n");
                            reset_text();
                            printf("The New Game is:\n");
                            display_info(item, index);
                        }
                    }
                    printf("\n\n1. Admin Menu\n2. Exit\nEnter: ");
                    scanf("%d", &action3);
                    if (action3 == 1)
                    {
                        clear_screen();
                        break;
                    }
                    else if (action3 == 2)
                    {
                        clear_screen();
                        red_text();
                        printf("Exited!");
                        reset_text();
                        return 0;
                    }
                    else
                    {
                        red_text();
                        printf("Invalid Choice!\n");
                        reset_text();
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
                    red_text();
                    printf("Invalid Choice!\n");
                    reset_text();
                    continue;
                }
            }
        }
        else if (action == 4)
        {
            clear_screen();
            red_text();
            printf("Exited!\n");
            reset_text();
            break;
        }
        else
        {
            red_text();
            printf("Invalid Choice!\n");
            reset_text();
            clear_screen();
            continue;
        }
    }

    return 0;
}
