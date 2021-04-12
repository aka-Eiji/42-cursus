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
					ft_putchar('A');
				else
					if (a == x)
						ft_putchar('C');
				else ft_putchar('B');
			}
			else
				if (b == y)
				{
					if (a == 1)
						ft_putchar('C');
					else
						if (a == x)
							ft_putchar('A');
					else ft_putchar('B');
				}
			else
			{
				if (a == 1 || a == x)
					ft_putchar('B');
				else ft_putchar(' ');
			}
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
