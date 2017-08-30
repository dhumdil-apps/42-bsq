#include "bsq.h"

int ft_min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		return (c);
	}
	else
	{
		if (b < c)
			return (b);
		return (c);
	}
	return (0);
}

void ft_update_max(int val, int i, int j)
{
	if (val > g_m.max.val)
	{
		g_m.max.val = val;
		g_m.max.i = i;
		g_m.max.j = j;
	}
}

int ft_list_push_next(int i, int j, int val)
{
	t_el *new_element;

	new_element = (t_el*)malloc(sizeof(t_el));
	if (!new_element)
		return (1);
	if (val == 0)
		new_element->c = 0;
	else
	{
		new_element->c = ft_min(g_m.first->c, g_m.first->next->c, g_m.second->c) + 1;
		ft_update_max(new_element->c, i, j);
	}
	new_element->next = NULL;
	g_m.first = g_m.first->next;
	
	g_m.second->next = new_element;
	g_m.second = g_m.second->next;
	return (0);
}