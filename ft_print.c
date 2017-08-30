#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	unsigned int n;

	n = 0;
	while (s[n] != '\0')
		n++;
	write(1, s, n);
}

void ft_compute_nbr(int nr)
{
	if (nr != 0)
	{
		ft_compute_nbr(nr / 10);
		ft_putchar(nr % 10 + '0');
	}
}

void ft_putnbr(int nr)
{
	if (nr == 0)
		ft_putchar('0');
	else
		ft_compute_nbr(nr);
}

void ft_print_map()
{
	int i;
	int j;
	t_el *p;

	i = 0;
	while (i < g_m.lines)
	{
		j = 0;
		p = g_m.row[i];
		while (p != NULL)
		{
			if (p->c == 0)
				ft_putchar(g_m.obstacle);
			else
			{
				if (i >= (g_m.max.i - g_m.max.val + 1) && i <= g_m.max.i)
				{
					if (j >= (g_m.max.j - g_m.max.val + 1) && j <= g_m.max.j)
						ft_putchar(g_m.full);
					else
						ft_putchar(g_m.empty);
				}
				else
					ft_putchar(g_m.empty);
			}
			p = p->next;
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}