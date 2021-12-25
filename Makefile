SRCFOLD		= src/

SRCS		= ${SRCFOLD}main.c \
				${SRCFOLD}parsing/arguments.c \
				${SRCFOLD}utils/errors.c \
				${SRCFOLD}utils/utils.c \
				${SRCFOLD}initialization/init.c \
				${SRCFOLD}debug/print_debug.c \
				${SRCFOLD}operations/swap.c \
				${SRCFOLD}operations/push.c \
				${SRCFOLD}operations/rotate.c \
				${SRCFOLD}operations/reverse_rotate.c \
				${SRCFOLD}core/get_median.c \
				${SRCFOLD}core/move_under_median.c \
				${SRCFOLD}core/move_after_sort_b.c \
				${SRCFOLD}core/move_above_median.c \
				${SRCFOLD}core/sort_under_five.c \
				${SRCFOLD}core/route_algo.c \
				${SRCFOLD}core/move_in_quantile.c \
				${SRCFOLD}core/get_quantiles.c

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= @clang

CFLAGS		= -Wall -Wextra -Werror -g3

RM			= @rm -f

%.o: %.c
	${CC} ${CFLAGS} -Iusr/include -Iincludes -Ilibft -c $< -o ${<:.c=.o}

${NAME}:		 ${OBJS}
	@make --no-print-directory -C libft
	@${CC} ${CFLAGS} ${OBJS} -L/usr/lib -Llibft -lft -lm -o ${NAME}

all:			${NAME}

clean:
	${RM} ${OBJS}
	@make clean --no-print-directory -C libft/

fclean:			clean
	${RM} ${NAME}
	@make fclean --no-print-directory -C libft/

re:				fclean all

.PHONY:			all clean fclean re