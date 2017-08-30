#include "bsq.h"

int is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// make sure that the empty, obstacle and full chars are distinct
int is_distinct(char s[])
{
	if (s[0] == s[1])
		return (0);
	if (s[0] == s[2])
		return (0);
	if (s[1] == s[2])
		return (0);
	return (1);
}

// initial valid chars are the empty chars and obstacle chars
int is_valid(char c)
{
	if (c == g_m.empty || c == g_m.obstacle)
		return (1);
	return (0);
}
