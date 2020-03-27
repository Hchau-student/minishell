//
// Created by irka on 22.03.2020.
//

#include "../../inc/minishell.h"
//
//void		del_str(char *s, size_t size)
//{
//	ft_memdel(&s);
//	size
//}

void		del_env(char *s, t_minishell *msh)
{
	t_list	*tmp;
	char 	*find;
	t_list	*prev;

	if ((ft_strequ(s, "~")) == TRUE)
		find = ft_strdup("HOME");
	else
		find = ft_strdup((s + 1));
	tmp = msh->env;
	prev = NULL;
	while (tmp)
	{
		if ((ft_strstr(tmp->content, find))
			&& ft_strcmp(tmp->content, find) == '=')
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	ft_strdel(&find);
//	ft_putendl(prev->content);
//	ft_putendl(tmp->content);
	prev->next = tmp->next;
//	ft_lstdelone

}

int			change_env(t_minishell *msh, char *find, char *new)
{
	t_list	*tmp;

	tmp = msh->env;
	while (tmp && !(ft_strstr(tmp->content, find)))
	{
//		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
	if (!tmp)
		return (NONEXIST_ENV);
//	ft_putendl(tmp->content);
	ft_strdel((char **)(&tmp->content));
	if (!(tmp->content = ft_strjoin(find, new)))
		minishell_error(MALLOC_ERROR);
//	ft_putendl(tmp->content);
	return (FINISH);
}

char		*find_env(char *s, t_list *env)
{
	t_list	*tmp;
	char 	*find;

	if ((ft_strequ(s, "~")) == TRUE)
		find = ft_strdup("HOME");
	else
		find = ft_strdup((s + 1));
	tmp = env;
	while (tmp)
	{
		if ((ft_strstr(tmp->content, find))
			&& ft_strcmp(tmp->content, find) == '=')
			break ;
		tmp = tmp->next;
	}
	ft_strdel(&find);
	if (tmp == NULL)
		return (NULL);
	find = ft_strdup((ft_strchr(tmp->content, '=') + 1));
	return (find);
}
