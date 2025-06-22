 #include <stdio.h>
 #include <limits.h>
 #include "ft_printf.h"

int main(void)
{
	printf("|%40.2s|\n", (char *)NULL);
	ft_printf("|%40.2s|\n", NULL);
	return (0);
}
