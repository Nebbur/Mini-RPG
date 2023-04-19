#include "../../includes/rpg.h"

void settings(int choice)
{
    if (choice == 0)
        printf("\033[0m");
    if (choice == 1)
        printf("\033[0;31m");
    else if (choice == 2)
        printf("\033[0;32m");
    else if (choice == 3)
        printf("\033[0;33m");
    else if (choice == 4)
        printf("\033[0;34m");
    else if (choice == 5)
        printf("\033[0;35m");
}

void    clear_screen()
{
    system("clear");
}

void    enter_key()
{
    printf("\nPress Enter to Continue\n");
    char press_key;
    press_key = fgetc(stdin);
    while( getchar() != '\n');
}
