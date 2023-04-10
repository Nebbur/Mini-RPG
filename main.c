#include "rpg.h"

int difficulty_factor = 1;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        int choice;
        printf("\nYou are Welcome!\n");
        printf("Enter a valid option:\n1 - Play\n2 - Settings\n0 - Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
            create_hero();
        else if (choice == 2)
        {
            printf("Select a color:\n0 - White\n1 - Red\n2 - Green\n3 - Yellow\n4 - Blue\n5 - Magenta\n6 - Cyan\n");
            int color;
            scanf("%d", &color);
            printf("COLOR %d\n", color);
            settings(color);
            main(argc, argv);
        }
        else if (choice == 0)
        {
           printf("Getting out...\n");
           exit(2);
        }
    }
    else if (argc == 2 && ft_strlen(argv[1]) == 1 && argv[1][0] == 48)
    {
        printf("Getting out...\n");
        exit(2);
    }
    else if (argc == 2 && ft_strlen(argv[1]) == 1 && argv[1][0] == 49)
    {
        printf("You are welcome!\nStarting the game...\n");
        create_hero();
    }
    else
        printf("Don't type things at random -.-\n");
    return 0;

}