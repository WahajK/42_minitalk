#include <stdio.h>

int	main(void)
{
	int i = 7;
	printf("%d\n",i);
	i = i >> 1;
	printf("%d\n",i);
	i = i << 1;
	printf("%d\n",i);
	return (0);
}