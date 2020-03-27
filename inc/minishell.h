//
// Created by irka on 20.03.2020.
//

#ifndef MINISHELL_H
#define MINISHELL_H
//ускорение overclocking
#include <stdlib.h>
#include "../libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termios.h>
#define BUFSIZE     500
#include "minishell_error.h"
#define FINISH	2
#define TRUE	1
#define FALSE	0
#define UP		"^[[A"
#define DOWN	"^[[B"
#define RIGHT	"^[[C"
#define LEFT	"^[[D"

typedef struct	s_minishell
{
	void		(*clear)(struct	s_minishell **);
	t_list		*env;
	t_list		*commands;
}				t_minishell;

typedef struct	s_function
{
	char		*filename;
	char		**args;
	void		(*make)(struct s_function *);
	void		(*clear)(struct s_function *);
	int			(*minishell_call)(struct s_function *, t_minishell *);
	void		(*terminal_call)(struct s_function *);
}				t_function;

/*
**		programm core
*/
void			main_loop(t_minishell *minishell);

/*
**		objects work
*/
int				init_minishell(t_minishell **new, char **env);
void			make_function(t_function *execute, char *command_line);

/*
**		errors management
*/
void			minishell_error(int errnum);
void			function_error(char *name, int errnum);
void			path_errors(int errnum);

/*
**		function calls
*/
void			terminal_call(t_function *execute);
int				minishell_call(t_function *execute, t_minishell *);
int				cd_command(t_function *execute, t_minishell *msh);

/*
**		enviroment work
*/
void			minishell_printenv(t_minishell *m);
void			minishell_setenv(t_minishell *m, t_function *f);
void			minishell_unsetenv(t_minishell *m, t_function *f);
char			*find_env(char *s, t_list *env);
int				change_env(t_minishell *msh, char *find, char *new);
void		del_env(char *s, t_minishell *msh);

#endif
