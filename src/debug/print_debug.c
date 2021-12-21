# include "push_swap.h"

void    print_debug(t_piles *piles)
{
    int i;

    i = 0;
    printf("\n\nLen A: %d\n", piles->len_a);
    printf("Tab A: ");
    while (i < piles->len_a)
    {
        printf("%d / ", piles->tab_a[i]);
        i++;
    }
    i = 0;
    printf("\n\nLen B: %d\n", piles->len_b);
    printf("Tab B: ");
    while (i < piles->len_b)
    {
        printf(" %d /", piles->tab_b[i]);
        i++;
    }
    printf("\n");
    printf("MEDIAN: %d\n\n", piles->median);
}