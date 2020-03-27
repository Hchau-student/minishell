//
// Created by irka on 20.03.2020.
//

#include "../inc/minishell.h"

static char		*read_command_line(int fd)
{
	int     		ret;
	char    		buf[BUFSIZE + 1];
	char			*res;

	ret = read(1, buf, BUFSIZE);
	if (ret == 1)
		return (NULL);
	buf[ret - 1] = '\0';
	res = ft_strdup(buf);
	return (res);
}

void	main_loop(t_minishell *minishell)
{
	t_function		execute;
	int     		key_loop;
	char			*command_line;
	pid_t			p;

	key_loop = 1;
	while ((key_loop == 1))
	{
		p = wait(NULL);
		if (p != 0)
			ft_putstr("$>");
		if (!(command_line = read_command_line(1)))
			continue ;
		make_function(&execute, command_line);
		ft_lstadd(&minishell->commands,
				ft_lstnew(command_line, ft_strlen(command_line)));
		if (execute.minishell_call(&execute, minishell) == FALSE)
			execute.terminal_call(&execute);
		execute.clear(&execute);
	}
}

int     main(int ac, char **av, char **env)
{
	t_minishell		*in_case;
	int				i;

	i = 0;
	if (ac > 1)
		minishell_error(TOO_MUCH_ARG);
	init_minishell(&in_case, env);
	main_loop(in_case);
	return (0);
}