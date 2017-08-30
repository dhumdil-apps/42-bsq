#include "bsq.h"

void	ft_init_map()
{
	g_m.cols = 0;
	g_m.lines = 0;
	g_m.empty = '\0';
	g_m.obstacle = '\0';
	g_m.full = '\0';
	g_m.max.val = 0;
}

int	ft_update_legend(char c, char s[], int *x, int *first_line)
{
	static int temp = 0;

	if (temp < 4 && c == '\n')
		return (1);
	s[(*x)++]= c;
	temp++;
	if (*x == 4)
	{
		if (s[3] != '\n')
		{
			if (!is_number(s[0]))
				return (1);
			g_m.lines = (g_m.lines * 10) + (s[0] - '0');
			shift_left(s, x);
		}
		else
		{
			if (!is_distinct(s) || g_m.lines == 0)
				return (1);
			*first_line = 0;
			g_m.empty = s[0];
			g_m.obstacle = s[1];
			g_m.full = s[2];
		}
	}
	return (0);
}

int ft_init_lines()
{
	int i;

	if ((g_m.row = (t_el **)malloc(g_m.lines * sizeof(t_el *))) == NULL)
        return (1);
	i = 0;
	while (i < g_m.lines)
	{
		if ((g_m.row[i] = (t_el *)malloc(sizeof(t_el))) == NULL)
			return (1);
		g_m.row[i] = NULL;
		i++;
	}
	return (0);
}

void ft_list_push_first(int i, int c)
{
	t_el *new_column;

	if (g_m.row[i] == NULL)
	{
		g_m.row[i] = (t_el*)malloc(sizeof(t_el));
		g_m.row[i]->c = c;
		g_m.row[i]->next = NULL;
		g_m.second = g_m.row[i];
	}
	else
	{
		new_column = (t_el*)malloc(sizeof(t_el));
		new_column->c = c;
		new_column->next = NULL;
		g_m.second->next = new_column;
		g_m.second = g_m.second->next;
	}
}

void ft_free_rows()
{
	int i;
	t_el *p;
	t_el *to_be_freed;

	i = 0;
	while (i < g_m.lines)
	{
		p = g_m.row[i];
		while (p)
		{
			to_be_freed = p;
			p = p->next;
			free(to_be_freed);
		}
		i++;
	}
	free(g_m.row);
}
