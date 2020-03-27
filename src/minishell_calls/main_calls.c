//
// Created by irka on 21.03.2020.
//

#include "../../inc/minishell.h"

static int		exit_command(t_function *execute, t_minishell **m)
{
//	t_list		*tmp;
//
	if ((ft_strequ(execute->filename, "exit")) == FALSE)
		return (FALSE);
	execute->clear(execute);
//	tmp = (*m)->commands;
//	while (tmp)
//	{
//		ft_putendl(tmp->content);
//		tmp = tmp->next;
//	}
	(*m)->clear(m);
	exit(0);
}

static int		echo_command(t_function *execute, t_minishell *m)
{
	int		i;
	t_list	*tmp;
	char	*env_res;

	i = 1;
	if ((ft_strequ(execute->filename, "echo")) == FALSE)
		return (FALSE);
	while (execute->args[i])
	{
		if (execute->args[i][0] != '$' && execute->args[i][0] != '~')
			ft_putstr(execute->args[i]);
		else if ((env_res = find_env(execute->args[i], m->env)) != NULL)
		{
			ft_putstr(env_res);
			ft_strdel(&env_res);
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (TRUE);
}

static int		env_command(t_function *execute, t_minishell *m)
{
	if ((ft_strequ(execute->filename, "env")) == TRUE)
	{
		minishell_printenv(m);
		return (TRUE);
	}
	if ((ft_strequ(execute->filename, "setenv")) == TRUE)
	{
		minishell_setenv(m, execute);
		return (TRUE);
	}
	else if ((ft_strequ(execute->filename, "unsetenv")) == TRUE)
	{
		minishell_unsetenv(m, execute);
		return (TRUE);
	}
	return (FALSE);
}

int				minishell_call(t_function *execute, t_minishell *m)//все хуки и все сравнения
{
	if (exit_command(execute, &m) == TRUE)
		;
	else if (echo_command(execute, m) == TRUE)
		;
	else if (cd_command(execute, m) == TRUE)
		;
	else if (env_command(execute, m) == TRUE)
		;
	else
		return (FALSE);
	return (TRUE);
}
