#include "rpg.h"

Player player;
Inimigo enemy;
bool turn_enemy = false;
int run = 0;
char    *firstalpha(char *str)
{
    int i = -1;
    while ((!(str[i] <= 'Z' && str[i] >= 'A')) && (!(str[i] <= 'z' && str[i] >= 'a')))
        i++;
    if(str[i] <= 'z' && str[i] >= 'a')
        str[i] -=32;
    return (str);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    ft_strcpy(char *dest, char *src)
{
    int i = -1;
    while (src[++i])
        dest[i] = src[i];
    return (*dest);
}

/*   
   1 Vermelho: \033[0;31m
   2 Verde: \033[0;32m
   3 Amarelo: \033[0;33m
   4 Azul: \033[0;34m
   5 Magenta: \033[0;35m
   6 Ciano: \033[0;36m*/

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

int     ft_atoi(char *str)
{
    int i = -1;
    int sign = 1;
    int result = 0;
    while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
        i++;
    if (str[i] == 43 || str[i] == 45)
    {
        if (str[i] == 43)
            sign = -1;
        i++;
    }
    while (str[i] <= 57 && str[i] >= 48)
    {
        result *= 10;
        result += str[i] + 48;
        i++;
    }
    return (result * sign);
} 

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

int count_calculate_xp;

void    xp_check()
{
    int earned_xp = 0;
    earned_xp += enemy.level * difficulty_factor;
    player.xp += earned_xp;
    if (player.level < 20)
        count_calculate_xp = 10;
    else
        count_calculate_xp = 100;
    if (player.xp >= player.level * (difficulty_factor * count_calculate_xp))
    {
        player.level++;
        if (player.xp > player.level * (difficulty_factor * count_calculate_xp))
            player.xp = 0 + (earned_xp - difficulty_factor * count_calculate_xp);
        if (player.class == "Warrior")
        {
            difficulty_factor = difficulty_factor + 1;
            player.physical_damage = 120 + (player.level - 1) * 7;
            player.magical_damage = 10 + (player.level - 1) * 2;
            player.defense = 90 + (player.level - 1) * 12;
            player.magical_defense = 50 + (player.level - 1) * 4;
            player.agility = 60 + (player.level - 1) * 5;
            player.evasive = 20 + (player.level - 1) * 4;
            player.max_hp = 20 + (player.level - 1) * 100;
            player.max_mana = 10 + (player.level - 1) * 20;
            player.max_stamina = 50 + (player.level - 1) * 30;
            player.hp = player.max_hp;
            player.mana = player.max_mana;
            player.stamina = player.max_stamina;
        }
        else if (player.class == "Mage")
        {
            player.physical_damage = 10 + (player.level - 1) * 2;
            player.magical_damage = 150 + (player.level - 1) * 7;
            player.defense = 50 + (player.level - 1) * 4;
            player.magical_defense = 90 + (player.level - 1) * 12;
            player.agility = 40 + (player.level - 1) * 5;
            player.evasive = 20 + (player.level - 1) * 4;
            player.max_hp = 20 + (player.level - 1) * 90;
            player.max_mana = 30 + (player.level - 1) * 30;
            player.max_stamina = 10 + (player.level - 1) * 20;
            player.hp = player.max_hp;
            player.mana = player.max_mana;
            player.stamina = player.max_stamina;
        }
        else if (player.class == "Archer")
        {
            player.physical_damage = 100 + (player.level - 1) * 7;
            player.magical_damage = 10 + (player.level - 1) * 2;
            player.defense = 50 + (player.level - 1) * 5;
            player.magical_defense = 30 + (player.level - 1) * 5;
            player.agility = 120 + (player.level - 1) * 10;
            player.evasive = 90 + (player.level - 1) * 10;
            player.max_hp = 15 + (player.level - 1) * 90;
            player.max_mana = 10 + (player.level - 1) * 20;
            player.max_stamina = 20 + (player.level - 1) * 50;
            player.hp = player.max_hp;
            player.mana = player.max_mana;
            player.stamina = player.max_stamina;
        }
        if (player.meditate_count < 3 && player.meditate_blocker == true)
        {
            player.physical_damage += 30;
            player.magical_damage += 30;
            player.max_stamina += 30;
            player.max_mana += 30;
            player.max_hp += 100;
            player.stamina += 30;
            player.mana += 30;
            player.hp += 100;
        }
    }
}

void    ennemy_status(bool first_one)
{
    if (enemy.hp <= 0 && first_one == false)
        xp_check();
    if (enemy.hp <= 0 || first_one == true)
    {
        enemy_generator();
        turn_enemy = false;
    }
    int damage;
    if (turn_enemy == true && enemy.hp > 0 && first_one == false)
    {
        damage = enemy.damage - player.defense;
        if (damage > 0)
        {
            printf("%s inflicted %d damage to %s.\n", enemy.name, damage, player.name);
            player.hp -= damage;
        }
        if (player.hp <= 0)
        {
            printf ("\n%s the %s was killed by %s the %s.\n", player.name, player.class, enemy.name, enemy.class);
            exit(42);
        }
        turn_enemy = false;
    }
    int temp;
    if (enemy.hp <= 0)
    {
        printf("%s, succumbed to the inflicted damage...\n", enemy.name);
        enemy_generator();
    }
    if (player.buff == true)
    {
        player.buff = false;
        player.defense -= 100;
    }
    interface();
}

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
                printf("You don't have enough stamina.\n");
                interface();
            }
            else
            {
                int damage;
                damage = player.physical_damage - enemy.defense;
                if (damage > 0)
                    enemy.hp -= damage;
                else
                    printf("It had no effect\n");
                printf("%s inflicted %d damage to %s.\n", player.name, damage, enemy.name);
                player.stamina -= 15;
            }
        }
        else if(action == 2)
        {
            player.overrest = 0;
            if ((player.mana - 15) < 0)
            {
                printf("You don't have enough mana.\n");
                interface();    
            }
            else
            {
                int damage;
                damage = player.magical_damage - enemy.defense;
                if (damage > 0)
                    enemy.hp -= damage;
                else
                    printf("It had no effect.\n");
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
            printf("You can't meditate again.\n");
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
    if (run == 3)
        interface();
    else if (count == 0)
        ennemy_status(true);
    else
        ennemy_status(false);
}

void    interface()
{
     if (player.level < 20)
        count_calculate_xp = 10;
    else
        count_calculate_xp = 100;
    int xp_max = player.level * (difficulty_factor * count_calculate_xp);
    printf("\n__________________________________________________________________________\n");
    printf("\n%s the %s              %s the %s\n", player.name, player.class, enemy.name, enemy.class);
    printf(" hp: %d/%d                        %d/%d :hp\n", player.hp, player.max_hp, enemy.hp, enemy.max_hp);
    printf(" Mana: %d/%d                      %d/%d :Mana\n", player.mana, player.max_mana, enemy.mana, enemy.max_mana);
    printf(" Stamina: %d/%d                   %d/%d :Stamina\n\n", player.stamina, player.max_stamina, enemy.stamina, enemy.max_stamina);
    printf("\n Level: %d                           %d :Level\n", player.level, enemy.level);
    printf(" Experience: %d\n", player.xp);
    printf("__________________________________________________________________________\n\n");
    printf("1.Attack       2.Magical Attack\n3.Protect      4.Rest\n5.Meditate     6.Run\n\n");
    printf("%s xp: %d/%d\nLevel: %d\n", player.name, player.xp, xp_max, player.level);
    char *choice = (char *) malloc(sizeof((char *)1 + 1));
    if (player.meditate == true && player.meditate_count < 1)
    {
        player.meditate_blocker = true;
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
            game(action);
        else
        {
            printf("Choose an available option\n\n\n");
            interface();
        }
    }
}

void    create_hero_class()
{
    printf("\nWich class do you want?\n\n");
    printf("            HP      MANA     STAMINA\n");
    printf("1.Warrior     20       10         30\n");
    printf("2.Mage        20       30         10\n");
    printf("3.Archer      15       10         20\n");
    int class;
    scanf("%d", &class);
    
    if (class == 1)
    {
        player.class = "Warrior";
        player.physical_damage = 120;
        player.magical_damage = 10;
        player.defense = 40;
        player.magical_defense = 30;
        player.agility = 60;
        player.evasive = 30;
        player.max_hp = 20;
        player.max_mana = 10;
        player.max_stamina = 50;
        player.hp = player.max_hp;
        player.mana = player.max_mana;
        player.stamina = player.max_stamina;
    }
    else if (class == 2)
    {
        player.class = "Mage";
        player.physical_damage = 10;
        player.magical_damage = 150;
        player.defense = 25;
        player.magical_defense = 60;
        player.agility = 40;
        player.evasive = 30;
        player.max_hp = 20;
        player.max_mana = 30;
        player.max_stamina = 10;
        player.hp = player.max_hp;
        player.mana = player.max_mana;
        player.stamina = player.max_stamina;
    }
    else if (class == 3)
    {
        player.class = "Archer";
        player.physical_damage = 115;
        player.magical_damage = 10;
        player.defense = 30;
        player.magical_defense = 30;
        player.agility = 120;
        player.evasive = 90;
        player.max_hp = 15;
        player.max_mana = 10;
        player.max_stamina = 20;
        player.hp = player.max_hp;
        player.mana = player.max_mana;
        player.stamina = player.max_stamina;
    }
    else
    {
        printf("Enter a valid option\n");
        create_hero_class();
    }
    enemy.max_hp = 5;
    enemy.hp = enemy.max_hp;
    enemy.max_mana = 7;
    enemy.mana = enemy.max_mana;
    enemy.max_stamina = 5;
    enemy.stamina = enemy.max_stamina;
    enemy.damage = 50;
    enemy.defense = 50;
    enemy.evasive = 40;
    enemy.name = "Poor";
    enemy.class = "Bambi";
    enemy.level = 1;
    player.kills = 0;
    player.meditate_count = 10;
    player.meditate_count_helper = 0;
    player.meditate = false;
    player.meditate_blocker = false;
    ennemy_status(true);
}

void    create_hero()
{
    bool boolean = false;
    printf("Enter your name: \n");
    scanf("%s", player.name);
    if (ft_strlen(player.name) > 20)
        boolean = true;
    if (boolean != false)
    {
        printf("Enter a name of up to twenty characters!\n");
        scanf("%s\n", player.name);
        if (ft_strlen(player.name) >= 20)
            create_hero();
    }
    firstalpha(player.name);
    char *choice = (char *) malloc(sizeof((char *)1 + 1));
    printf("Do you confirm your choice?\ny/n: ");
    scanf("%s", choice);
    if (choice[0] == 'y' && choice[1] == '\0')
    {
        create_hero_class();
        free(choice);
    }
    else if (choice[0] == 'n' && choice[1] == '\0')
    {
        create_hero();
        free(choice);
    }
    else
    {
        printf("Choose an available option.\n");
        create_hero();
    }
}