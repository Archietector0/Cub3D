SRC = get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c cub_c_part_1.c cub_c_part_2.c cub_c_part_3.c \
	cub_c_part_4.c cub_c_part_5.c cub_c_part_7.c cub_c_part_8.c \
	pars.c pars_c_part_1.c pars_c_part_2.c pars_c_part_3.c pars_c_part_4.c \
	pars_c_part_5.c cube_1.c checker_maker.c

OBJC = ${SRS:.c=.o}

NAME = cub3D

FLAG = -Wall -Wextra -Werror

OBJC = ${SRC:.c=.o}

GCC = gcc

INCLUDE = cub3d.h

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(INCLUDE) -MMD -c $< -o $@

all: ${NAME}

${NAME}: ${OBJC} libmlx.dylib $(INCLUDE)
	ar rc ${NAME} ${OBJC}
	${GCC} $(FLAG) ${NAME} cube.c libmlx.dylib libft/libft.a -o ${NAME}

bonus: all

clean:
	rm -f ${OBJC}
	rm -f ./get_next_line/*d
	rm -f *.d

fclean: clean
	rm -f ${NAME}
	rm -f cub3D

re: fclean all

.PHONY: all clean fclean re bonus
