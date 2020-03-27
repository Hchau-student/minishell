//
// Created by irka on 21.03.2020.
//

#include "../../inc/minishell.h"

void				terminal_call(t_function *execute)
{
	char    		*full_filename;
	pid_t   		p;

	p = fork();
	if (p == 0)
	{
		full_filename = ft_strjoin("/bin/", execute->filename);
		if ((execve(full_filename, execute->args, NULL)) == -1)
		{
			ft_strdel(&full_filename);
			function_error(execute->filename, NONEXIST_FUNCTION);
		}
		ft_strdel(&full_filename);
	}
}
