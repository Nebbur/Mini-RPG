#include "../../includes/rpg.h"

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
