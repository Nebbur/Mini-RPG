#include "../../includes/rpg.h"

char    ft_strcpy(char *dest, char *src)
{
    int i = -1;
    while (src[++i])
        dest[i] = src[i];
    return (*dest);
}
