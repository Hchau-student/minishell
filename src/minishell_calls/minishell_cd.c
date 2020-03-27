//
// Created by irka on 22.03.2020.
//

#include "../../inc/minishell.h"

/*
**		обработка указателей на любой path
*/
static char		*not_a_home(char *arg, t_minishell *msh)
{
	char	*path;
	char	ultimate[BUFSIZE + 1];
	char	*full_path;

	if (arg[0] == '$')
	{
		if ((path = find_env(arg, msh->env)) == NULL)
			return (NULL);
		return (path);
	}
	else
	{
		if (!(path = ft_strdup(arg)))
			minishell_error(MALLOC_ERROR);
	}
	return (path);
}

/*
**		обработка указателей на homedir
*/
static int		homedir(char **args, t_minishell *msh)
{
	char	*path;
	char	*leak;
	t_list	*tmp;

	if ((args[1]) && (ft_strequ("~", args[1])) != TRUE)
		return (FALSE);
	path = find_env("$HOME", msh->env);
	if ((chdir(path)) != PATH_IS_OK)
		;//обработать ошибку ~
	if (change_env(msh, "PWD=", path) == NONEXIST_ENV)
	{
		ft_strdel(&path);
		minishell_error(WTF_WHERE_IS_PWD);
	}
	ft_strdel(&path);
	return (TRUE);
}

/*
**		получение полного пути к уже изменённой текущей директории
*/
static void		get_full_path(char **path)
{
	char	buf[BUFSIZE + 1];

	ft_strdel(path);
	*path = getcwd(buf, BUFSIZE);//надо заменить на вектор
	if (!(*path))
		minishell_error(GETCWD_ERR);
}

/*
**		cd: обработка ошибок
*/
int		cd_command(t_function *execute, t_minishell *msh)
{
	char	*path;

	if ((ft_strequ(execute->filename, "cd")) == FALSE)
		return (FALSE);
	if (execute->args[1] && execute->args[2])
	{
		function_error("cd error", CD_TOO_MUCH);
		return (TRUE);
	}
	if ((homedir(execute->args, msh)) == TRUE)
		return (TRUE);
	if (!(path = (not_a_home(execute->args[1], msh))))
		return (TRUE);
	if ((chdir(path)) != PATH_IS_OK)
		;//обработать ошибку
	get_full_path(&path);
	if (change_env(msh, "PWD=", path) == NONEXIST_ENV)
		minishell_error(WTF_WHERE_IS_PWD);
	return (TRUE);
}
