#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct game
{
    char name[100];
    float price;
    int code;
};

struct customer
{
    char name[100];
    char phone[20];
    char email[100];
    char password[12];
    char gamepal[6];
};

struct admin
{
    char name[100];
    char email[100];
    char password[12];
};

void display_games(struct game array[]) {
    
    printf("\033[1;34m");
    printf("%s%35s\n", "Code", "Game Name");
    printf("\033[0m");
    
    for (int index = 0; index < 20; index++)
    {
        printf("%d.%35s\n", array[index].code, array[index].name);
    }

}

void display_info(struct games array[], int index) {

    printf("Game Name: %s\n", array[index].name);
    printf("Price: %.2f\n", array[index].price);
}

int main(void) {

    struct game games[20] = {
        {"Assassin's Creed IV: Black Flag", 29.99, 1},
        {"Baldur's Gate 3", 49.99, 2},
        {"Call of Duty: Black Ops 2", 39.99, 3},
        {"Cyberpunk 2077", 59.99, 4},
        {"DOOM Eternal", 44.99, 5},
        {"EA Sports FC 24", 34.99, 6},
        {"Elden Ring", 54.99, 7},
        {"Far Cry 6", 49.99, 8},
        {"Forza Horizon 5", 59.99, 9},
        {"God of War", 39.99, 10},
        {"Grand Theft Auto V", 29.99, 11},
        {"Hades", 24.99, 12},
        {"Marvel's Spider-Man", 49.99, 13},
        {"Max Payne 3", 19.99, 14},
        {"Red Dead Redemption 2", 54.99, 15},
        {"Resident Evil 4", 29.99, 16},
        {"Starfield", 59.99, 17},
        {"The Elder Scrolls V: Skyrim", 39.99, 18},
        {"The Last of Us", 49.99, 19},
        {"The Witcher 3", 39.99, 20}
    };

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
    int option;
    srand(time(NULL));

    while (1)
    {
        printf("\033[2J");
        printf("\033[1;34m");
        printf("Welcome to GameHub\n");
        printf("\033[0m");
        printf("1. Display Available gamess\n");
        printf("2. Place an Order\n");
        printf("3. Admin Access\n");
        printf("4. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &action);

        if (action == 1)
        {
            printf("\033[2J");
            printf("Available Games are:\n\n");
            display_games(games);
            printf("Enter 1 to Go Back to Main Menu and 0 to Exit: ");
            scanf("%d", &inner_action);
            if (inner_action == 1)
            {
                continue;
            }
            else if (inner_action == 0)
            {
                printf("Exited!\n");
                break;
            }
            else
            {
                printf("Invalid Choice!\n");
                continue;
            }
        }
        else if (action == 2)
        {
            printf("\033[2J");
            printf("Enter Game Code from Displayed Games (1 - 20): ");
            scanf("%d", &game_choice);

            printf("\n\n");

            for (int index = 0; index < 20; index++)
            {
                if (game_choice == games[index].code)
                {
                    display_info(games, index);
                    strcpy(new_name, game[index].name);
                    price = games[index].price;
                    break;
                }
            }
            
            printf("\n\n");

            printf("Enter New Username: ");
            scanf("%s", new_customer.name);
            printf("\nEnter Phone Number: ");
            scanf("%s", new_customer.phone);
            printf("\nEnter Email: ");
            scanf("%s", new_customer.email);
            printf("\nEnter a Password (Maximum 12 Characters): ");
            scanf("%s", new_customer.password);
            printf("Enter Your GamePal Account Number (6 Digits): ");
            scanf("%s", new_customer.gamepal);

            printf("\033[2J");
            float final_amount = price + (price * 0.10);
            printf("Amount to be Paid Including 10%% VAT: %2.f\n", final_amount);
            printf("Enter Amount to Collect from your GamePal: ");
            scanf("%f", &amount);

            printf("\n\n");

            printf("An OTP Code has been sent to you\n");

            otp = rand() % 90001 + 510000;

            printf("Your OTP Code is: %d\n", otp);
            printf("\nEnter your OTP Code: ");
            scanf("%d", &new_otp);

            printf("\n\n");

            if (new_otp == otp)
            {
                printf("Enter 1 to Confirm Order and 2 to Cancel Order: ");
                scanf("%d", &option);
                if (option == 1)
                {
                    printf("\033[2J");
                    printf("Order Confirmed!\n");
                    printf("Transaction Successful!\n");
                    printf("Game: %s\n", new_name);
                    printf("Customer: %s\n", new_customer.name);
                    printf("Customer Phone: %s\n", new_customer.phone);
                    printf("Customer Email: %s\n", new_customer.email);
                    printf("Customer GamePal Account Number: %s\n", new_customer.gamepal);
                    printf("Collected Amount: $%.2f\n", amount);
                    printf("Paid Amount Including 10%% VAT: $%.2f\n", final_amount);
                    printf("Returned Amount: $%.2f\n", (amount - final_amount));
                    printf("Thank You for your Purchase!\n");
                }
                else if (option == 2)
                {
                    printf("Order Canceled!\n");
                }
                else
                {
                    printf("Invalid Choice!\n");
                }
            }
            else
            {
                price("OTP did not match, please try again!\n");
            }
        }
        else if (action == 3)
        {
            int admin_choice;
            printf("\033[1;34m");
            printf("Welcome to Admin Access!\n");
            printf("\033[0m");

            printf("\nEnter Admin Username: ");
            scanf("%s", new_admin.name);
            printf("Enter Admin Email: ");
            scanf("%s", new_admin.email);
            printf("Enter Password (Maximum 12 Characters): ");
            scanf("%s", new_admin.password);

            printf("\033[2J");

            printf("1. Add a new game to replace one\n2. Go Back to Main Menu\nEnter a choice: ");
            scanf("%d" &admin_choice);

            if (admin == 1)
            {
                
            }
            else
            {
                continue;
            }
            
        }
        else if (action == 4)
        {
            printf("Exited!\n");
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
        }
    }

    return 0;

}
