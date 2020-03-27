//
// Created by irka on 22.03.2020.
//

#include "../../inc/minishell.h"

void	minishell_printenv(t_minishell *m)
{
	t_list	*tmp;

	tmp = m->env;
	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

void	minishell_setenv(t_minishell *m, t_function *f)
{
	char	*find;
	char	*new;
	char	*leak;

	if (!(ft_strchr(f->args[1], '=')))
	{
		function_error(NULL, NON_EQ);
		return;
	}
	if (!(find = ft_strdup(f->args[1] + 1)))
		minishell_error(MALLOC_ERROR);
	if (!(new = ft_strdup((ft_strchr(f->args[1], '=')) + 1)))
		minishell_error(MALLOC_ERROR);
	ft_strchr(find, '=')[1] = '\0';
	if (!(leak = find_env(find, m->env)))
		ft_lstadd(&m->env, ft_lstnew(f->args[1] + 1, ft_strlen(f->args[1] + 1)));
	else
	{
		change_env(m, find, new);
		ft_strdel(&leak);
	}
}


void	minishell_unsetenv(t_minishell *m, t_function *f)
{
	char	*find;
	char	*leak;

	if (!f->args[1] || (ft_strchr(f->args[1], '=')))
	{
		return ;
	}
	if (!(find = ft_strdup(f->args[1])))
		minishell_error(MALLOC_ERROR);
	ft_putendl(find);
	if (!(leak = find_env(find, m->env)))
	{
		return ;
	}
	else
	{
		ft_putendl("OK");
		del_env(find, m);
		ft_strdel(&leak);
	}
}