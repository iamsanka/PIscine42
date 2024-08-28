#include "ft_stock_str.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stock_str *tab;
    int i;

    tab = ft_strs_to_tab(argc, argv);
    if (!tab)
        return (1);
    i = 0;
    while (i < argc)
    {
        printf("Size: %d\n", tab[i].size);
        printf("Str: %s\n", tab[i].str);
        printf("Copy: %s\n", tab[i].copy);
        i++;
    }
    return (0);
}

