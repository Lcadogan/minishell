# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarmela <acarmela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 12:02:54 by acarmela          #+#    #+#              #
#    Updated: 2021/07/17 15:24:36 by acarmela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Цвет текста:
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
BLUE='\033[34m'
GRAY='\033[37m'

CC			= gcc # компилятор https://habr.com/ru/post/490850/

NAME	= libft.a

# директория заголовочных файлов
INC = -I include/

# rm - удаление
# -r — обрабатывать все вложенные подкаталоги.
# -f — не возвращать код ошибочного завершения, если ошибки были вызваны 
# несуществующими файлами; не запрашивать подтверждения операций.
RM			= rm -rf

# директория источник. Внутри нее директории и файлы источники
SRC_DIR		= srcs/

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_atoi.c ft_isalpha.c \
		  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		  ft_tolower.c ft_calloc.c ft_strdup.c ft_strncmp.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c

# поиск cи файлов   ПРОВЕРИТЬ может можно без этой строчки
CFIND = $(SRCS:%=$(SRC_DIR)%)


# директория хранения объектных файлов
OBJ_DIR		= obj/

# правило для преобразования 
# ${SRCS:.c=.o} означает, что возьмем переменное значение ${SRCS} , которое 
# представляет собой строку, состоящую из слов, разделенных пробелами, и для каждого 
# слова замените суффикс .c на .o . 
# Можно опустить . в своем коде, потому что они не нужны, и обычно заменяют только
# суффиксы после точки. Можно писать OBJS := ${SRCS:c=o} 
OBJS	= ${SRCS:.c=.o}

# ./obj/ft_printf.o \
# ./obj/ft_parser.o \
# ./obj/ft_processor.o \
# ./obj/create_b.o \
# ...
OBJ =  $(addprefix $(OBJ_DIR), $(OBJS))

FLAGS = -Wall -Wextra -Werror $(INC) -c -o

# L		= -L.
# LIB		= -lft
# GCC		= gcc
# CFLAGS	= -Wall -Wextra -Werror
ARRC	= ar -rc
# .c.o:	${OBJS}
# 		@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
# $(L) $(LIB)

all:	$(NAME)

$(NAME):$(OBJ_DIR) $(OBJ)
	@$(ARRC) $(NAME) $(OBJ)
#ranlib генерирует индекс содержимого архива и сохраняет его в архиве
	@ranlib $(NAME)	
	@echo ${GREEN}"[lib Make finished]"
	@tput sgr0

$(OBJ_DIR):
#	если не было директории, указанной в $(OBJ_DIR), то она создается
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(CFIND)
	@$(MAKE) $(OBJS)	
		
$(OBJS):
	@${CC} $(FLAGS) ${OBJ_DIR}$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	@${RM} $(OBJ_DIR)
	@echo ${BLUE}"[lib Object files deleted]"
	@tput sgr0

fclean:	clean
	@${RM} $(NAME)
	@echo ${BLUE}"[lib Binary files deleted]"
	@tput sgr0
	
re:	fclean all

.PHONY:	all clean fclean re