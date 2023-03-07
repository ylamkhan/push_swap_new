NAME = push_swap
CHECKER = checker

SRCS =  srcs/actions.c\
		srcs/libft.c\
		srcs/main.c\
		srcs/min_actions.c\
		srcs/min1_actions.c\
		srcs/outils2_libft.c\
		srcs/outils_main.c\
		srcs/outils.c\
		srcs/outils1.c\
		srcs/outils2.c\
		srcs/pile_to_tab.c\
		srcs/sort_otuls.c\
		srcs/sort.c\
		srcs/outils_libft.c\



SRCS_BONUS = checker_bonus/actions_bonus.c\
			checker_bonus/checker_bonus.c\
			checker_bonus/ft_strdup_bonus.c\
			checker_bonus/get_next_line_bonus.c\
			checker_bonus/get_next_line_utils_bouns.c\
			checker_bonus/libft_bonus.c\
			checker_bonus/main_bonus.c\
			checker_bonus/push_swap_bonus.c\
			checker_bonus/outils_actions_bonus.c\
			checker_bonus/min_libtf_bonus.c\
			checker_bonus/min1_actions_bonus.c

CFLAGS = -Wall -Werror -Wextra
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
