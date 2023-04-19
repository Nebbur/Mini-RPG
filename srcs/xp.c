#include "../includes/rpg.h"

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
