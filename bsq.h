#ifndef BSQ_H

# define BSQ_H

# define BUF_SIZE 4096
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct			s_el
{
	int	c;
	struct 	s_el		*next;
} t_el;

typedef struct s_max
{
	int val;
	int i;
	int j;
}t_max;

typedef struct			s_map
{
	int			cols;
	int 		lines;
	char		empty;
	char		obstacle;
	char		full;
	struct s_el *first;
	struct s_el *second;
	struct s_max max;
	struct s_el	**row;
} t_map;


t_map g_m;

// main.c
void shift_left(char s[], int *x);
int	ft_read_map(int input);

// ft_print.c
void	ft_putchar(char c);
void	ft_putstr(char *s);
void ft_print_map(char buf[]);

// ft_list.c
void	ft_init_map();
int	ft_update_legend(char c, char s[], int *x, int *first_line);
int ft_init_lines();
void ft_list_push_first(int i, int c);
void ft_free_rows();

// ft_list2.c
int ft_list_push_next(int i, int j, int val);

//base_fct.c
int is_number(char c);
int is_distinct(char s[]);
int is_valid(char c);

#endif
