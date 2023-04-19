#include "../../includes/rpg.h"

char    *firstalpha(char *str)
{
    int i = -1;
    while ((!(str[i] <= 'Z' && str[i] >= 'A')) && (!(str[i] <= 'z' && str[i] >= 'a')))
        i++;
    if(str[i] <= 'z' && str[i] >= 'a')
        str[i] -=32;
    return (str);
}
