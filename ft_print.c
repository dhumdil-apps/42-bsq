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
	t_el *p;

	i = 0;
	while (i < g_m.lines)
	{
		p = g_m.row[i];
		while (p != NULL)
		{
			ft_putnbr(p->c);
			ft_putstr(" ");
			p = p->next;
		}
		ft_putchar('\n');
		i++;
	}
}