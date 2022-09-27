SRC_M = so_long.c \
	check_error.c \
	check_error2.c \
	init_game.c \
	get_next_line.c \
	activate_game.c \
	create_window.c \
	parse_map.c \
	manage_event.c \
	manage_event2.c \
	close_game.c \

SRC_B = so_long_bonus.c \
	check_error_bonus.c \
	check_error2_bonus.c \
	init_game_bonus.c \
	get_next_line_bonus.c \
	activate_game_bonus.c \
	create_window_bonus.c \
	parse_map_bonus.c \
	manage_event_bonus.c \
	manage_event2_bonus.c \
	manage_event3_bonus.c \
	close_game_bonus.c \


SOURCES_DIR		=	srcs
BONUS_DIR		=	srcs_bonus

HEADER			=	includes/so_long.h
HEADER_BONUS	=	includes/so_long_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SRC_M))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SRC_B))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-I -g -L /usr/X11/lib -Lincludes -L./mlbx -Imlx -lXext -lX11 -lz -lm

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./mlx_linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

FT_PRINTF_PATH	=	./ft_printf
FT_PRINTF		=	$(FT_PRINTF_PATH)/libftprintf.a

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)
$(FT_PRINTF):
				$(MAKE) -C $(FT_PRINTF_PATH)
$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(FT_PRINTF_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus