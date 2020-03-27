//
// Created by irka on 21.03.2020.
//

#include "../../inc/minishell.h"

static char		**split_command_line(char **filename, char *command_line)//+split
{
//	char			*command_line;
	char			**res;
	int 			i;

//	command_line = read_command_line();
	if (!(*filename = ft_strcdup(command_line, ' ')))
		minishell_error(MALLOC_ERROR);
	if (!(ft_strchr(command_line, ' ')))
	{
		res = (char **)malloc(sizeof(char *) * 2);
		res[0] = ft_strdup("  ");
		res[1] = NULL;
		return (res);
	}
	if (!(res = ft_strsplit(command_line, ' ')))
		minishell_error(MALLOC_ERROR);
	return (res);
}

static void		clear_funct(t_function *to_clear)
{
	ft_strdel(&(to_clear->filename));
	ft_freematr(&to_clear->args);
}

void			make_function(t_function *execute, char *command_line)
{
	execute->args = split_command_line(&execute->filename, command_line);
	execute->clear = &clear_funct;
	execute->minishell_call = &minishell_call;
	execute->terminal_call = &terminal_call;
}
