#ifndef RPG_H
# define RPG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>

typedef struct
{
    char*   name;
    char*   class;

    int     damage;
    int     defense;
    int     magical_defense;
    int     agility;
    int     evasive;
    int     hp;
    int     stamina;
    int     mana;
    int     max_hp;
    int     max_stamina;
    int     max_mana;
    int     level;
} Inimigo;

typedef struct
{
    const char* class;
    char        name[20];

    bool        meditate_blocker;
    bool        buff;
    bool        meditate;

    int         physical_damage;
    int         magical_damage;
    int         defense;
    int         magical_defense;
    int         agility;
    int         evasive;
    int         hp;
    int         stamina;
    int         mana;
    int         max_hp;
    int         max_stamina;
    int         max_mana;
    int         level;
    int         xp;
    int         kills;
    int         overrest;
    int         overprotect;
    int         meditate_count;
    int         meditate_count_helper;
} Player;

extern Player player;
extern Inimigo enemy;
extern int difficulty_factor;
extern int round_counter;
extern int count_calculate_xp;
extern bool turn_enemy;

/************   INT FUNCTIONS   ************/

    /********   MAIN   ********/
    int     main(int argc, char **argv);
    /**************************/

    /********   AUXILIARY   ********/
    int     ft_strlen(char *str);
    int     ft_atoi(char *str);
    /*******************************/

/*******************************************/

/************   CHAR FUNCTIONS   ************/

    /********   AUXILIARY   ********/
    char    ft_strcpy(char *dest, char *src);
    char    *firstalpha(char *str);
    /*******************************/

/********************************************/

/************   VOID FUNCTIONS   ***********/
   
    /********   MAIN   ********/
    void    interface();
    void    game(int action);
    /**************************/

    /********   HERO   ********/
    void    create_hero();
    void    create_hero_class();
    /**************************/

    /********   ENEMY   ********/
    void    ennemy_status(bool first_one);
    void    enemy_generator();
    void    enemy_generator_helper();
    void    boss_generator(bool punishment);
    /**************************/

    /********   AUXILIARY   ********/
    void    settings(int choice);
    void    clear_screen();
    void    enter_key();
    void    xp_check();
    /*******************************/

/*******************************************/

#endif
