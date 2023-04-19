#include "../includes/rpg.h"

void    interface()
{
     if (player.level < 20)
        count_calculate_xp = 10;
    else
        count_calculate_xp = 100;
    int xp_max = player.level * (difficulty_factor * count_calculate_xp);
    printf("\n__________________________________________________________________________\n");
    printf("\nRound: %d\n", round_counter);
    printf("\n%s the %s              %s the %s\n", player.name, player.class, enemy.name, enemy.class);
    printf(" hp: %d/%d                        %d/%d :hp\n", player.hp, player.max_hp, enemy.hp, enemy.max_hp);
    printf(" Mana: %d/%d                      %d/%d :Mana\n", player.mana, player.max_mana, enemy.mana, enemy.max_mana);
    printf(" Stamina: %d/%d                   %d/%d :Stamina\n\n", player.stamina, player.max_stamina, enemy.stamina, enemy.max_stamina);
    printf("\n Level: %d                           %d :Level\n", player.level, enemy.level);
    printf(" Experience: %d\n", player.xp);
    printf("__________________________________________________________________________\n\n");
    printf("1. Physical Attack       2. Magical Attack\n3. Protect               4. Rest\n5. Meditate              6. Run\n\n");
    char *choice = (char *) malloc(sizeof((char *)1 + 1));
    if (player.meditate == true && player.meditate_count < 1)
    {
        player.meditate_blocker = true;
        clear_screen();
        game(0);
    }
    else
    {
        if (player.meditate_count < 2)
        {
            player.meditate = false;
            player.meditate_count_helper++;
        }
        else
            player.meditate_count_helper++;
        scanf("%s", choice);
        printf("\n");
        int action = atoi(choice);
        turn_enemy = true;
        if (action <= 6 && action >= 1)
        {
            clear_screen();
            game(action);
        }
        else
        {
            clear_screen();
            printf("Choose an available option\n\n\n");
            interface();
        }
    }
}


