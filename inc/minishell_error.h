//
// Created by irka on 21.03.2020.
//

#ifndef MINISHELL_MINISHELL_ERROR_H
#define MINISHELL_MINISHELL_ERROR_H

#define PATH_IS_OK			0
#define MALLOC_ERROR		0
#define TOO_MUCH_ARG		1
#define NOT_A_FUNC			2
#define NONEXIST_FUNCTION	3
#define CD_TOO_MUCH			4
#define WTF_WHERE_IS_PWD	5
#define NONEXIST_ENV		6
#define GETCWD_ERR			7
#define NON_EQ				8
/*
**		path errors:
*/

//path errors:
/*EFAULT
		path указывает за пределы доступного адресного пространства.
ENAMETOOLONG
		path слишком длинно.
ENOENT
		Файл не существует.
ENOMEM
		Ядру не хватило памяти.
ENOTDIR
		Компонент пути, использованный как каталог в path, в действительности таковым не является.
EACCES
		В одном из каталогов, находящихся по пути к path, не разрешен поиск.
ELOOP
		path является зацикленной символической ссылкой, то есть при подстановке возникает ссылка на неё саму.
EIO
		Произошла ошибка ввода-вывода.*/
//#define
#endif //MINISHELL_MINISHELL_ERROR_H
