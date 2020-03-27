//
// Created by irka on 21.03.2020.
//

//мб будет использоваться, мб нет, хз

#include "../inc/minishell.h"

void	clear_minishell(t_minishell **minishell)
{
	//очистить листы
	//очистить pwd
	free(*minishell);
	return;
}

void	get_minishell_env(t_minishell **put_here, char **env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (env[i])
	{
		(*put_here)->env = ft_lstnew(env[i], sizeof(char) * (ft_strlen(env[i]) + 1));
		i++;
	}
	tmp = (*put_here)->env;
	while (env[i])
	{
		tmp->next = ft_lstnew(env[i],  sizeof(char) * (ft_strlen(env[i])));
		i++;
		tmp = tmp->next;
	}
}

int		init_minishell(t_minishell **new, char **env)
{
	if (!(*new = (t_minishell *)malloc(sizeof(t_minishell))))
		minishell_error(MALLOC_ERROR);
	(*new)->commands = NULL;
	(*new)->env = NULL;
	(*new)->clear = &clear_minishell;
	get_minishell_env(new, env);
	return (0);
}
