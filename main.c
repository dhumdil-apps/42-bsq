#include "bsq.h"

int		main(int ac, char **av)
{
	int	file;
	int	index;

	if (ac > 1)
	{
		index = 1;
		while (index < ac)
		{
			if ((file = open(av[index], O_RDONLY)) > 0)
			{
				if (ft_read_map(file) == 1)
					ft_putstr("map error\n");
			}
			else
				ft_putstr("map error\n");
			index++;
		}
	}
	else
	{
		if (ft_read_map(0) == 1)
			ft_putstr("map error\n");
	}
	return (0);
}

int	ft_read_map(int input)
{
	int		i;
	int		j;
	int		n;
	int		first_line;
	char	s[5];

	char buf[BUF_SIZE];
	int k;

	ft_init_map();
	first_line = 1;
	i = 0;
	j = 0;
	while ((n = read(input, buf, BUF_SIZE)) > 0)
	{
		k = 0;
		while (k < n)
		{
			if (!first_line && g_m.lines != 0 && i == g_m.lines)
				return (1);
			if (first_line)
			{
				if (ft_update_legend(buf[k], s, &i, &first_line) == 1)
					return (1);
				if (!first_line)
				{
					if (ft_init_lines() == 1)
						return (1);
					i = 0;
				}
			}
			else if (buf[k] == '\n')
			{
				if (g_m.cols == 0)
					g_m.cols = j;
				else if (j != g_m.cols)
					return (1);
				j = 0;
				g_m.first = g_m.row[i];
				i++;
			}
			else
			{
				if (!is_valid(buf[k]))
					return (1);
				if (i == 0 || j == 0)
				{
					if (buf[k] == g_m.obstacle)
						ft_list_push_first(i, 0);
					else
						ft_list_push_first(i, 1);
				}
				else
				{
					if (buf[k] == g_m.obstacle)
					{
						if (ft_list_push_next(i, 0, 0))
							return (1);
					}
					else
					{
						if (ft_list_push_next(i, j, 1) == 1)
							return (1);
					}
				}
				j++;
			}
			k++;
		}
	}
	if (n == -1 || i < g_m.lines)
		return (1);
	ft_print_map(buf);
	printf("max=%d, i=%d, j=%d\n", g_m.max.val,g_m.max.i,g_m.max.j);
	ft_free_rows();
	return (0);
}

void shift_left(char s[], int *x)
{
	int i;

	i = 0;
	while (i < 3)
	{
		s[i] = s[i + 1];
		i++;
	}
	(*x)--;
}
