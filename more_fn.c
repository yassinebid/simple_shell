#include "shell.h"
/**
 *_strcmp - compare two string
 *@s1: string input
 *@s2: string input
 *Return: 0 if equals
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *) --s2);
}
/**
 *_path - path of command
 *Return: string of path in function of its position.
 */
char *_path()
{
	int fd;
	char *ch;
	char *buf = malloc(sizeof(char) * 1024);

	fd = open("/etc/environment", O_RDONLY);
	read(fd, buf, 1024);
	ch = _strcp(buf, indexof((char)34, buf), lastindexof((char)34, buf));
	ch = concat(".:", ch);
	return (ch);
}
/**
 *_isdigit - check if input is a digit
 *@p: input
 *Return: 1 if is a digit
 */
int _isdigit(char *p)
{
	int i = 0;

	while (p[i] != '\0')
	{
	if (!(p[i] >= '0' && p[i] <= '9'))
	return (0);
	i++;
	}
	return (1);
}
/**
 *power - calc power
 *@base: input
 *@a: input
 *Return: power result
 */
int power(int base, int a)
{
	if (a != 0)
		return (base * power(base, a - 1));
	else
		return (1);
}
/**
 *toInt - convert string to int
 *@p: input
 *Return: int
 */
int toInt(char *p)
{
	int i = 0, res = 0, len = _strlen(p) - 1;

	while (p[i] != '\0')
	{
		res = res + (((int)p[i] - 48) * power(10, len));
		len--;
		i++;
	}
	return (res);
}
