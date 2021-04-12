#include "ft_putchar.c"

void rush(int x, int y) // X colonna valore massimo, Y riga valore massimo
{
	int a; // colonna valore base
	int b; // colonna valore base

	b = 1;
	while (b <= y) // quando B e'minore-uguale a Y (Riga)
	{
		a = 1; // variabile a diventa 1
		while (a <= x) // quando a e'minore-uguale a X ( Colonna )
		{
			if (b == 1 || b == y) // Se b uguale ad 1 or b uguale a y
			{
				if (a == 1 || a == x) // Se a uguale a 1 or a uguale a x
					ft_putchar('o'); 
				else ft_putchar('-');
			}
			else
			{
				if (a == 1 || a == x)
					ft_putchar('|');
				else ft_putchar(' ');
			}
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
