#include "libftprintf.h"

int main()
{   
    //int i = 5;
    //printf("Bla bla %p\n", &i);
    //ft_printf("Bla bla %p\n", &i);

    printf("sys:Bla bla %*p\n", 5, (void*)-1);
    ft_printf("usr:Bla bla %*p\n", 5, (void*)-1);
    return (0);
}
