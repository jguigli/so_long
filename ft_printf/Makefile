NAME = libftprintf.a

SRC = ft_printf.c \
		format1.c \
		format2.c \
		itoa_base.c \
		ft_printf_utils.c \

OBJ = ${SRC:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes/

all: ${NAME}

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ}
	ranlib ${NAME}	

.c.o:
	${CC} ${FLAGS} -o $@ -c $< ${INCLUDES}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all