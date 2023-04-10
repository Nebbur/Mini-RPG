#ifndef RPG_H
# define RPG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

extern int difficulty_factor;

// Define uma estrutura para representar um inimigo
typedef struct {
    char* name;
    char* class;
    int damage;
    int defense;
    int magical_defense;
    int agility;
    int evasive;
    int hp;
    int stamina;
    int mana;
    int max_hp;
    int max_stamina;
    int max_mana;
    int level;
} Inimigo;

typedef struct {
    char name[20];
    const char* class;
    int physical_damage;
    int magical_damage;
    int defense;
    int magical_defense;
    int agility;
    int evasive;
    int hp;
    int stamina;
    int mana;
    int max_hp;
    int max_stamina;
    int max_mana;
    int level;
    int xp;
    int kills;
    int overrest;
    int overprotect;
    int meditate_count;
    int meditate_count_helper;
    bool meditate_blocker;
    bool buff;
    bool meditate;
} Player;

int main(int argc, char **argv);
int ft_strlen(char *str);
void    create_hero();
void    create_hero_class();
void    interface();
void    game(int action);
void    ennemy_status(bool first_one);
void settings(int choice);

#endif