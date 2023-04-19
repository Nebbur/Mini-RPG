#include "../includes/rpg.h"

Player player;
Inimigo enemy;
bool turn_enemy = false;
int count_calculate_xp;
int run = 0;
int count = -1;

void    game(int action)
{
    count++;
    if (player.meditate == false)
    {
        player.meditate_count++;
        if (action == 1)
        {
            player.overrest = 0;
            if ((player.stamina - 15) < 0)
            {
                printf("You don't have enough stamina to make a physical attack.\n");
                interface();
            }
            else
            {
                int damage;
                damage = player.physical_damage - enemy.defense;
                if (damage > 0)
                {
                    enemy.hp -= damage;
                    printf("%s inflicted %d damage to %s.\n", player.name, damage, enemy.name);
                }
                else
                    printf("Your attack had no effect.\n");
                player.stamina -= 15;
            }
        }
        else if(action == 2)
        {
            player.overrest = 0;
            if ((player.mana - 15) < 0)
            {
                printf("You don't have enough mana to make a magic attack.\n");
                interface();    
            }
            else
            {
                int damage;
                damage = player.magical_damage - enemy.defense;
                if (damage > 0)
                    enemy.hp -= damage;
                else
                    printf("Your attack had no effect.\n");
                printf("%s inflicted %d damage to %s.\n", player.name, damage, enemy.name);
                player.mana -= 15;
            }
        }
        else if (action == 3)
        {
            player.overprotect++;
            player.overrest = 0;
            if (player.overprotect > 2)
            {
                player.overprotect = 0;
                printf("You can't protect yourself three times in a row.\n");
                interface();
            }
            player.buff = true;
            player.defense += 100;
            printf("Your defense has increased by 100.n");
        }
        else if(action == 4)
        {
            player.overrest++;
            player.overprotect = 0;
            if (player.overrest > 2)
            {
                player.overrest = 0;
                printf("You can't rest again.\n");
                interface();
            }
            player.stamina += 30;
            player.mana += 30;
            player.hp += (player.max_hp / 20);
            if (player.stamina > player.max_stamina)
                player.stamina = player.max_stamina;
            if (player.mana > player.max_mana)
                player.mana = player.max_mana;
            if (player.hp > player.max_hp)
                player.hp = player.max_hp;
        }
        else if (action == 5 && player.meditate_blocker == false)
        {
            player.meditate_count = 0;
            player.meditate_count_helper = 0;
            player.meditate = true;
            player.physical_damage += 30;
            player.magical_damage += 30;
            player.max_stamina += 30;
            player.max_mana += 30;
            player.max_hp += 100;
            player.stamina += 30;
            player.mana += 30;
            player.hp += 100;
        }
        else if (action == 5 && player.meditate_blocker == true)
        {
            printf("You can't meditate again.\n");
            interface();
        }
        else if (action == 6)
        {
            player.overrest = 0;
            player.overprotect = 0;
            run++;
            if (run == 3)
            {
                run = 0;
                printf("Good luck\n");
                boss_generator(true);
            }
            else if (run == 2)
            {
                printf("If you run one more time you'll regret it.\n");
            }
            else
                printf("Don't run coward.\n");
        }
    }
    else
        player.meditate_count++;
    turn_enemy = true;
    if (player.meditate_count_helper == 2 && player.meditate_blocker == true)
    {
        player.meditate_count = 10;
        player.meditate_blocker = false;
        player.meditate_count = 0;
        player.meditate_count_helper = 0;
        player.physical_damage -= 30;
        player.magical_damage -= 30;
        player.max_stamina -= 30;
        player.max_mana -= 30;
        player.max_hp -= 100;
        player.hp -= 100;
        if (player.stamina > player.max_stamina)
            player.stamina = player.max_stamina;
        if (player.mana > player.max_mana)
            player.mana = player.max_mana;
    }
    round_counter++;
    if (count == 0)
        ennemy_status(true);
    else
        ennemy_status(false);
}
