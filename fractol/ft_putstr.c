

#include "fractol.h"

void	ft_putstr(char *str)
{
	if (str)
	{
		while (*str != 0)
		{
			if (write(1, str, 1) == -1)
				break ;
			str++;
		}
	}
}
