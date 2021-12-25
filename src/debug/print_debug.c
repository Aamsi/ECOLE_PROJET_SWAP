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
    printf("MEDIAN: %d\n", piles->median);
    printf("Q1: %d\n", piles->q1);
    printf("Q2: %d\n", piles->q2);
    printf("Q3: %d\n", piles->q3);
    printf("Q4: %d\n", piles->q4);
    printf("Q5: %d\n\n", piles->q5);
}
