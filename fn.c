#include "shell.h"
/**
 *_strlen - concat two strings
 *@arg: input
 * Return: length of a string
 */
int _strlen(char *arg)
{
	int i = 0;

	while (arg[i] != '\0')
		i++;
	return (i);
}
/**
 *concat - concat two strings
 *@arg: input
 *@arg0: input
 * Return: new string
 */
char *concat(char *arg0, char *arg)
{
	int len = _strlen(arg0);
	int len1 = _strlen(arg);
	char *res = malloc(sizeof(char *) * (len + len1));
	int i = 0;

	while (i != len)
	{
		res[i] = arg0[i];
		i++;
	}
	i = 0;
	while (i != len1)
	{
		res[len] = arg[i];
		len++;
		i++;
	}
	res[len] = '\0';
	return (res);
}
/**
 *indexof - index of input
 *@arg: input
 *@arg0: input
 * Return: first index of input
 */
int indexof(char arg0, char *arg)
{
	int i = 0, res = -1;

	while (arg[i] != '\0')
	{
		if (arg[i] == arg0)
		{
			res = i;
			break;
		}
		i++;
	}
	return (res);
}
/**
 *lastindexof - last index of input
 *@arg: input
 *@arg0: input
 * Return: last index of input
 */
int lastindexof(char arg0, char *arg)
{
	int i = _strlen(arg), res = -1;

	while (i != 0)
	{
		if (arg[i] == arg0)
		{
			res = i;
			break;
		}
		i--;
	}
	return (res);
}
/**
 *_strcp - copy from string
 *@arg: input
 *@arg0: input
 *@arg1: input
 * Return: string
 */
char *_strcp(char *arg, int arg0, int arg1)
{
	int i = arg0 + 1, j = 0;
	char *res = malloc(sizeof(char) * (arg1 - (arg0 + 1)));

	while (i != arg1)
	{
		res[j] = arg[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
