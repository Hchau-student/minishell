//
// Created by irka on 21.03.2020.
//

#include "../inc/minishell.h"

void	minishell_error(int errnum)
{
	ft_putstr("minishell:\n");
	if (errnum == MALLOC_ERROR)
		ft_putstr("memory allocation error\n");
	if (errnum == TOO_MUCH_ARG)
		ft_putstr("programm shouldn't have arguments after call. Try again.\n");
	if (errnum == NOT_A_FUNC)
		ft_putstr("not a function. Try again.\n");
	if (errnum == WTF_WHERE_IS_PWD)
		ft_putendl("error: please set pwd");
	exit (0);
}

void	function_error(char *name, int errnum)
{
	if (errnum == NONEXIST_FUNCTION)
	{
		ft_putstr(name);
		ft_putstr(": command not found\n");
		exit (0);
	}
	if (errnum == CD_TOO_MUCH)
		ft_putstr("minishell: cd: too many arguments\n");
	if (errnum == NON_EQ)
	{
		ft_putstr("minishell: you forgot the \'=\'\n");
	}
}

void	path_errors(int errnum)
{
	//найти ошибки и обработать
//	if (errnum == EFAULT)
//		ft_putstr("I don`t know\n");
//	if (errnum == ENOENT)
//		ft_putstr("no such file or directory\n");
}