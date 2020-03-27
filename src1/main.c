//
// Created by irka on 20.03.2020.
//

#include "../inc/minishell.h"

int     main(int argc, char **argv)
{
	int     ret;
	char    buf[BUFSIZE + 1];
	int     fd;
	char    **priv;
	char    *lal;
	pid_t   p;

	priv = (char **)malloc(sizeof(char *) * 3);
	priv[0] = "-l";
	priv[1] = "-a";
	priv[2] = NULL;
	fd = 1;
	while ((fd == 1))
	{
		ret = read(1, buf, BUFSIZE);
		buf[ret - 1] = '\0';
		if ((ft_strequ(buf, "exit")) == 1)
			exit(0);
		p = fork();
		if (p == 0)
		{
			lal = ft_strjoin("/bin/", buf);
			if ((execve(lal, priv, NULL)) == -1)
			{
				ft_putstr("func not found\n");
				exit(0);
//				kill(p);
			}
		}
	}
	return (0);
}