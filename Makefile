NAME = push_swap

SRC = srcs/algorithm.c\
	  srcs/f_common.c\
	  srcs/f_push_swap.c\
	  srcs/f_rotate.c\
	  srcs/f_stack_edit.c\
	  srcs/f_stack_fill_meta.c\
	  srcs/f_stack_metadata.c\
	  srcs/input_check.c\
	  srcs/push_swap.c\
	  srcs/sort_utils.c

OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./incs/libft
LIBFT_NAME	= libft.a

DEPS = incs/push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${LIBFT_PATH}/${LIBFT_NAME} ${DEPS} ${NAME}

${NAME}: ${LIBFT_PATH}/${LIBFT_NAME} ${OBJ}
	${CC} ${LIBFT_PATH}/${LIBFT_NAME} ${SRC} -o $@

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

clean:
	rm -f ${OBJ}
	cd $(LIBFT_PATH) && make clean

fclean: clean
	rm -f ${NAME}
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re
