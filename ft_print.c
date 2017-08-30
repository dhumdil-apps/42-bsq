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

void try_print(char *buf, int *x, char c)
{
	buf[(*x)++] = c;

	if (*x == BUF_SIZE)
	{
		write(1, buf, *x);
		*x = 0;
	}
}

void ft_print_map(char buf[])
{
	int i;
	int j;
	int x;
	t_el *p;

	i = 0;
	x = 0;
	while (i < g_m.lines)
	{
		j = 0;
		p = g_m.row[i];
		while (p != NULL)
		{
			if (p->c == 0)
				try_print(buf, &x, g_m.obstacle);
			else
			{
				if (i >= (g_m.max.i - g_m.max.val + 1) && i <= g_m.max.i)
				{
					if (j >= (g_m.max.j - g_m.max.val + 1) && j <= g_m.max.j)
						try_print(buf, &x, g_m.full);
					else
						try_print(buf, &x, g_m.empty);
				}
				else
					try_print(buf, &x, g_m.empty);
			}
			p = p->next;
			j++;
		}
		try_print(buf, &x, '\n');
		i++;
	}
	write(1, buf, x);
}