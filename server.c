#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

int	main(void)
{
	ft_printf("PID: ", getpid());
}