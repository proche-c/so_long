
SRCS		= so_long_mandatory/srcs/initializers.c \
			so_long_mandatory/get_next_line/get_next_line.c \
			so_long_mandatory/get_next_line/get_next_line_utils.c\
			so_long_mandatory/libft/ft_putchar_fd.c\
			so_long_mandatory/libft/ft_putnbr_fd.c\
			so_long_mandatory/main.c\
			so_long_mandatory/srcs/map.c\
			so_long_mandatory/srcs/events.c\
			so_long_mandatory/srcs/game.c\
			so_long_mandatory/srcs/check_map.c\
			so_long_mandatory/srcs/utils.c

BONUS		= so_long_bonus/get_next_line/get_next_line.c \
			so_long_bonus/get_next_line/get_next_line_utils.c\
			so_long_bonus/libft/ft_putchar_fd.c\
			so_long_bonus/libft/ft_putnbr_fd.c\
			so_long_bonus/libft/ft_itoa.c\
			so_long_bonus/bonus/initializers.c \
			so_long_bonus/main_b.c \
			so_long_bonus/bonus/map.c\
			so_long_bonus/bonus/events.c\
			so_long_bonus/bonus/game.c\
			so_long_bonus/bonus/check_map.c\
			so_long_bonus/bonus/utils.c\
			so_long_bonus/bonus/moves.c\
			so_long_bonus/bonus/sprites.c\
			so_long_bonus/bonus/sprites_enemy.c\
			so_long_bonus/bonus/moves_enemy.c

OBJS		= ${SRCS:.c=.o}

OBJS_B		= ${BONUS:.c=.o}

MFLAGS		= -L . -lmlx -framework OpenGL -framework AppKit

CFLAGS		=  -Wall -Werror -Wextra

NAME		= so_long_mandatory/so_long

NAME_B		= so_long_bonus/so_long_b

HEADER		= so_long_mandatory/so_long.h

HEADER_B	= so_long_bonus/so_long_b.h

RM			= rm -f

AR			= ar rc

GC 			= gcc

all:		${NAME}	

${NAME}:	${OBJS} ${HEADER}
			${MAKE} -C ./so_long_mandatory/minilibx all
			cp ./so_long_mandatory/minilibx/libmlx.a .
			${GC} ${CFLAGS} ${MFLAGS} ${OBJS} -o  ${NAME}  

bonus:		${NAME_B}

${NAME_B}:	${BONUS} ${HEADER_B}
			${MAKE} -C ./so_long_bonus/minilibx all
			cp ./so_long_bonus/minilibx/libmlx.a .
			${GC} ${CFLAGS} ${MFLAGS} ${BONUS} -o ${NAME_B}

clean:		
			${MAKE} -C ./so_long_mandatory/minilibx clean
			${MAKE} -C ./so_long_bonus/minilibx clean
			${RM} ./libmlx.a
		#	${RM} ./so_long_bonus/libmlx.a
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

re_bonus:	fclean bonus




