#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	printf("%lld", LLONG_MIN);
	printf("Lo que imprime ft_printf:\n");
	int n = ft_printf("Hola que tal, char: %c, string: %s", 'c', "Esto es un string");
	printf("\nLo que devuelve ft_printf: %d\n", n);
	printf("Lo que imprime printf:\n");
	n = printf("Hola que tal, char: %c, string: %s", 'c', "Esto es un string");
	printf("\nLo que devuelve printf: %d\n", n);
}