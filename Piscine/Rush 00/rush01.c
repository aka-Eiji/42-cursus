
#include"ft_putchar.c"

void rush(int x, int y)
{
	int a;
	int b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if (b == 1)
			{
				if (a == 1)
					ft_putchar('/');
				else if (a == x)
					ft_putchar('\\');
				else ft_putchar('*');
			}
			else
				if (b == y)
				{
					if (a == 1)
						ft_putchar('\\');
					else if (a == x)
						ft_putchar('/');
					else ft_putchar('*');
				}
			else
				{
					if (a == 1 || a == x)
						ft_putchar('*');
					else ft_putchar(' ');
				}
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
