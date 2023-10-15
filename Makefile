CC		= gcc
CFLAGS	= -Wall -Wextra
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC  = 	errorhandling.c \
		init.c \
		lst_operation.c \
		main.c \
		rules_push.c \
		rules_rotate_bw.c \
		rules_rotate_fw.c \
		rules_swap.c \
		set_index.c \
		sort_big_sort_1_main.c \
		sort_big_sort_2_callculate.c \
		sort_big_sort_3_pushback.c \
		sort_big_sort_4_rotat_first_postion.c \
		sort_simple_sort.c \
		utiles_1.c \
		utiles_2.c \
		utiles_ft_itoa.c 

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME)

allgdb: $(OBJ_PATH) $(NAME) -g

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

gdb: fclean allgdb

.PHONY: all clean fclean re