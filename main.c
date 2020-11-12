#include "libftprintf.h"

int main()
{   
    //int i = 5;
    //printf("Bla bla %p\n", &i);
    //ft_printf("Bla bla %p\n", &i);

    printf("Bla bla %p\n", (void*)-1);
    ft_printf("Bla bla %p\n", (void*)-1);
    return (0);
}