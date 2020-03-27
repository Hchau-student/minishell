//
// Created by irka on 21.03.2020.
//

#include "../inc/minishell.h"

void	main_loop(t_minishell *minishell)
{
	t_function		execute;
	int     		key_loop;
	char    		*lal;
	pid_t   		p;

	key_loop = 1;
	while ((key_loop == 1))
	{
		make_function(&execute);
		if (execute.minishell_call(&execute) == FALSE)
			execute.terminal_call(&execute);
		execute.clear(&execute);
	}
}
