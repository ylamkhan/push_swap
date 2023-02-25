NAME = push_swap

SRCS = actions.c\
		libft.c\
		main.c\
		min_actions.c\
		otuls_sort_100.c\
		outils_main.c\
		outils.c\
		outils1.c\
		outils2.c\
		pile_to_tab.c\
		sort_otuls.c\
		sort.c\
		outils_libft.c\


SRCS_BONUS = checker_bonus/actions_bonus.c\
			checker_bonus/checker_bonus.c\
			checker_bonus/ft_strdup_bonus.c\
			checker_bonus/get_next_line_bonus.c\
			checker_bonus/get_next_line_utils_bonus.c\
			checker_bonus/libft_bonus.c\
			checker_bonus/main_bonus.c\
			checker_bonus/push_swap_bonus.c

#CFLAGS = -Wall -Werror -Wextra  -fsanitize=address -g
CC = gcc
RM = rm -rf

all: $(NAME)

OBJ = $(SRCS:%.c=%.o)
OBJ_BONUS = $(SRCS_BONUS:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus : $(CHECKER)

$(CHECKER): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(CHECKER)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean
