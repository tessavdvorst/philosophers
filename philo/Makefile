
NAME = philo

VPATH = src:\
		src/utils

OBJ = $(addprefix obj/, $(SRC_FILES:.c=.o))

SRC_FILES = main.c\
			data_init.c\
			routine.c\
			error.c\
			thread.c\
			print.c\
			time.c\
			check.c\
			$(UTILS_FILES)

UTILS_FILES = ft_putendl_fd.c\
				ft_atoi.c\
				ft_strlen.c\
				ft_putstr_fd.c\
				ft_isdigit.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_itoa.c\
				ft_strncmp.c\
				check_and_convert_arg.c\
				check_numeric.c\

INC = -Iincl

ifdef DEBUG
 CFLAGS = -Wextra -Wall -Werror -pthread -fsanitize=thread -g
else
 CFLAGS = -Wextra -Wall -Werror -pthread
endif

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(INC) -o $@ $^

debug:
	$(MAKE) DEBUG=1 all

obj/%.o: %.c
		@mkdir -p obj
		$(CC) $(CFLAGS) $(INC) -c -o $@ $^

clean:
		rm -rf obj

fclean: clean
		rm -rf $(NAME)

re: fclean all

PHONY: make re all clean fclean
