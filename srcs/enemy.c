#include "../includes/rpg.h"

void    boss_generator(bool punishment)
{
    if (punishment == true)
    {
        enemy.name = "Boss";
        enemy.class = "Troll";
        enemy.max_hp = 999;
        enemy.hp = enemy.max_hp;
        enemy.max_mana = 999;
        enemy.mana = enemy.max_mana;
        enemy.max_stamina = 999;
        enemy.stamina = enemy.max_stamina;

        enemy.damage = 999;
        enemy.defense = 999;
        enemy.evasive = 999;
        round_counter++;
        interface();
    }
}

void    enemy_generator_helper()
{
    enemy.level++;
    srand(time(NULL));
    int random = (rand() % 3);
    int temp;
    if (random == 0)
    {
        enemy.name = "Jose";
        enemy.class = "Troll";
        enemy.max_hp *= 3;
        enemy.hp = enemy.max_hp;
        enemy.max_mana *= 1;
        enemy.mana = enemy.max_mana;
        enemy.max_stamina *= 1.5;
        enemy.stamina = enemy.max_stamina;

        enemy.damage *= 2.5;
        enemy.defense *= 2;
        enemy.evasive *= 1.7;
    }
    else if (random == 1)
    {
        enemy.name = "Carvalho";
        enemy.class = "Wolf";
        enemy.max_hp *= 2;
        enemy.hp = enemy.max_hp;
        enemy.max_mana *= 1.2;
        enemy.mana = enemy.max_mana;
        enemy.max_stamina *= 3;
        enemy.stamina = enemy.max_stamina;

        enemy.damage *= 1.6;
        enemy.defense *= 1.2;
        enemy.evasive *= 1.2;
    }
    else if (random == 2)
    {
        enemy.name = "Bernardete";
        enemy.class = "Bear";
        enemy.max_hp *= 2.5;
        enemy.hp = enemy.max_hp;
        enemy.max_mana *= 1.2;
        enemy.mana = enemy.max_mana;
        enemy.max_stamina *= 4;
        enemy.stamina = enemy.max_stamina;

        enemy.damage *= 1.8;
        enemy.defense *= 2.5;
        enemy.evasive *= 1.2;
    }
}

void    enemy_generator()
{
    if (enemy.hp < 0)
    {
        char *choice = (char *) malloc(sizeof((char *)1 + 1));
        printf("Do you wish to face a stronger enemy?\ny/n\n");
        scanf("%s", choice);
        if (choice[0] == 'y')
        {
            enemy_generator_helper();
            player.kills = 0;
            free(choice);
        }
        else if (choice[0] == 'n')
        {
            free(choice);
            player.kills++;
            enemy.hp = enemy.max_hp;
            enemy.mana = enemy.max_mana;
            enemy.stamina = enemy.max_stamina;
        }
        else
        {
            printf("Choose an available option.\n");
            free(choice);
            enemy_generator();
        }
        printf("You have killed %d enemys.\n", player.kills);
        if (player.kills > 9 && choice[0] != 'y' && choice[0] != 'n')
        {
            player.kills = 0;
            printf("There are no more enemys in this zone\nChanging zone...\n");
            enemy_generator_helper();
        }
    }
}

void    ennemy_status(bool first_one)
{
    if (enemy.hp <= 0 && first_one == false)
        xp_check();
    if (enemy.hp <= 0 && first_one == true)
    {
        printf("\nPress Enter to Continue\n");
        enter_key();
        enemy_generator();
        turn_enemy = false;
    }
    int damage;
    if (turn_enemy == true && enemy.hp > 0 && first_one == false)
    {
        damage = enemy.damage - player.defense;
        if (damage > 0)
        {
            printf("%s inflicted %d damage to %s.\n\n", enemy.name, damage, player.name);
            player.hp -= damage;
        }
        if (player.hp <= 0)
        {
            printf ("\n%s the %s was killed by %s the %s.\n\n", player.name, player.class, enemy.name, enemy.class);
            exit(42);
        }
        turn_enemy = false;
    }
    if (enemy.hp <= 0)
    {
        printf("%s the %s, succumbed to the inflicted damage...\n\n", enemy.name, enemy.class);
        enter_key();
        enemy_generator();
    }
    if (player.buff == true)
    {
        player.buff = false;
        player.defense -= 100;
    }
    round_counter++;
    interface();
}

