#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
/* functions prototype */
char *concat(char *arg0, char arg[]);
int start_shell();
char *_path();
int _strlen(char *arg);
int indexof(char arg0,char *arg);
int lastindexof(char arg0,char *arg);
char *_strcp(char *arg,int arg0,int arg1);
int _strcmp(const char *s1, const char *s2);
int toInt(char *p);
int power(int base, int a);
int _isdigit(char *p);
#endif
