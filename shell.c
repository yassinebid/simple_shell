#include "shell.h"
/**
 *start_shell - start the shell
 *Return: status
 */
int start_shell(void)
{
	char *input, *token, *p, *cmd, *envVec[] = {NULL};
	int i = 0, pid, status = 0;
	size_t bufsize = 32;
	char **argVec;
	char *path[32];

	token = strtok(_path(), ":");
	while (token != NULL)
	{
		path[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	path[i] = (char *)0;
	while (1)
	{
start:
		write(1, "$ ", 2);
		input = malloc(bufsize * sizeof(char));
		argVec = malloc(sizeof(char *) * 32);
		getline(&input, &bufsize, stdin);
		if (_strlen(input) == 1 && (int)input[0] == 10)
			goto start;
		i = 0;
		token = strtok(input, " \n\t\0");
		while (token != NULL)
		{
			argVec[i] = token;
			token = strtok(NULL, " \n\t\0");
			i++;
		}
		argVec[i] = (char *)0;
		if (_strcmp("exit", argVec[0]) == 0)
		{
			if (argVec[1] != NULL)
			{
				if (_isdigit(argVec[1]))
					return (toInt(argVec[1]));
				else
					write(1, "Please check the argement\n", 27);
			}
			else if (argVec[1] == NULL)
				return (status);
		}
		i = 0;
		if (access(input, F_OK) == 0)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("fail to fork");
			}
			else if (pid == 0)
			{
				if (execve(input, argVec, envVec) != 0)
				{
					perror("fail to execute");
				}
			}
			else
			{
				waitpid(pid, &status, WUNTRACED);
			}
		}
		else
		{
			while (path[i] != NULL)
			{
				p = concat(path[i], "/");
				cmd = concat(p, argVec[0]);
				if (access(cmd, F_OK) == 0)
				{
					pid = fork();
					if (pid < 0)
					{
						perror("fail to fork");
					}
				else if (pid == 0)
				{
					if (execve(cmd, argVec, envVec) != 0)
					{
						perror("fail to execute");
					}
				}
				else
				{
					waitpid(pid, &status, WUNTRACED);
				}
		break;
		}
		i++;
			}
		}
	}
}
