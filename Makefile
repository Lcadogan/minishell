# Цвет текста:
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
BLUE='\033[34m'
GRAY='\033[37m'

CC			= gcc # компилятор https://habr.com/ru/post/490850/

NAME = minishell
HEADER = minishell.h


# rm - удаление
# -r — обрабатывать все вложенные подкаталоги.
# -f — не возвращать код ошибочного завершения, если ошибки были вызваны 
# несуществующими файлами; не запрашивать подтверждения операций.
RM			= rm -rf

# директория источник. Внутри нее директории и файлы источники
SRC_DIR		= ./srcs/

SRCS	= 	main.c\
			execution_2.c \
			execution_3.c \
			execution.c \
			find_argv.c\
			make_list_2.c\
			make_list.c \
			my_cd.c \
			my_echo.c \
			my_env.c \
			my_exit.c \
			my_export.c \
			my_heredoc.c \
			my_pwd.c \
			my_unset.c \
			parce_dollar.c\
			parser_2.c\
			parser_3.c\
			parser_4.c\
			parser.c\
			pre_parser.c\
			redirect_2.c\
			redirect.c\
			utils_2.c\
			utils_3.c\
			utils_4.c\
			utils_5.c\
			utils_6.c \
			utils_7.c \
			utils.c \

# директория хранения объектных файлов
OBJ_DIR		= ./obj/

# правило для преобразования 
# ${SRCS:.c=.o} означает, что возьмем переменное значение ${SRCS} , которое 
# представляет собой строку, состоящую из слов, разделенных пробелами, и для каждого 
# слова замените суффикс .c на .o . 
# Можно опустить . в своем коде, потому что они не нужны, и обычно заменяют только
# суффиксы после точки. Можно писать OBJS := ${SRCS:c=o} 
OBJS = $(SRCS:.c=.o)

# ./obj/ft_printf.o \
# ./obj/ft_parser.o \
# ./obj/ft_processor.o \
# ./obj/create_b.o \
# ...
OBJS_WITH_DIR =  $(addprefix $(OBJ_DIR), $(OBJS))
SRC_WITH_DIR =  $(addprefix $(SRC_DIR), $(SRCS))

FLAGS = -Wall -Wextra -Werror -lreadline

all:	$(NAME)

$(NAME): $(OBJS_WITH_DIR) $(HEADER)
	@$(MAKE) -C libft
# -lft ключ, который подключает либу l - lib, 
	$(CC) $(FLAGS) -g -lreadline -L/Users/acarmela/.brew/opt/readline/lib -I/Users/acarmela/.brew/opt/readline/include $(OBJS_WITH_DIR) -L libft -lft -o $(NAME)
	@echo ${GREEN}"[Make finished]"
	@tput sgr0

# ./obj/ft_printf.o: ./src/ft_printf.c
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#	если не было директории, указанной в $(OBJ_DIR), то она создается
	@mkdir -p $(OBJ_DIR)
#	компилятор с флагами и заголовочными файлами. -с (не запускать линковку)
#	$< - имя первого пререквизита
#	$@ - имя цели
	@${CC} -c $< -o $@

clean:
#	@$(RM) $(OBJS_WITH_DIR)
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C libft
	@echo ${YELLOW}"[Object files deleted]"
	@tput sgr0

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@echo ${YELLOW}"[Binary files deleted]"
	@tput sgr0

re: fclean all

debug: $(NAME)
	@$(MAKE) -C libft
# -lft ключ, который подключает либу l - lib, 
	$(CC) -g -lreadline -L/Users/acarmela/.brew/opt/readline/lib -I/Users/acarmela/.brew/opt/readline/include $(SRC_WITH_DIR) /Users/acarmela/Documents/minishell/libft/srcs/ft_strchr.c ./libft/libft.a -o $(NAME)
	@echo ${GREEN}"[debag Make finished]"
	@tput sgr0



.PHONY:	all clean fclean re debag

# ставим @ чтобы не выводился текст команд.
# если не ввести цель, то сработает all или первая цель
