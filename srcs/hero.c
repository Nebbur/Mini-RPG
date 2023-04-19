#include "../includes/rpg.h"

void    create_hero_class()
{
    clear_screen();
    printf("\nWich class do you want?\n\n");
    printf("            HP      MANA     STAMINA\n");
    printf("1.Warrior     20       10         30\n");
    printf("2.Mage        20       30         10\n");
    printf("3.Archer      15       10         20\n");
    int class;
    scanf("%d", &class);
    clear_screen();

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
    player.level = 1;
    ennemy_status(true);
}

void    create_hero()
{
    clear_screen();
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
