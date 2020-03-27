
NAME = minishell
SRC = ./src/main.c ./src/minishell_error.c ./src/minishell_constructor.c ./src/function_obj/constructor.c \
	./src/minishell_calls/*.c ./src/env_work/find_change_env.c ./src/env_work/minishell_env.c \
	./src/minishell_calls/minishell_cd.c
OBJ = ./main.o ./minishell_error.o minishell_constructor.o constructor.o main_calls.o terminall_calls.o \
	find_change_env.o minishell_env.o minishell_cd.o
INC = -I ./inc
LIBFT = ./libft/libft.a
# FLAGS = -Wall -Wextra
# FLAGS += -Werror

all: $(NAME)

$(NAME): $(LIBFT)
	gcc $(FLAGS) $(SRC) -c
	gcc $(OBJ) $(INC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all
