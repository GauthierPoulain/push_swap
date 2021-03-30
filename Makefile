_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m

NAME = push_swap

CC = clang
CFLAGS = -Wall -Wextra -Werror -fno-builtin -O3

MAKE = make --no-print-directory

NAME_C = checker
DIR_C = checker_src
HEADERS_C = $(DIR_C)/includes/checker.h
OBJS_C = $(SRCS_C:%.c=%.o)
SRCS_C = \
	$(DIR_C)/checker.c \
	$(DIR_C)/parsing/parsing.c \
	$(DIR_C)/parsing/check.c \

DIR_PS = push_swap_src
NAME_PS = push_swap
HEADERS_C = $(DIR_PS)/includes/push_swap.h
OBJS_PS = $(SRCS_PS:%.c=%.o)
SRCS_PS = \
	$(DIR_PS)/push_swap.c \

%.o: %.c $(HEADERS_C)
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME)$(_END) ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_C) $(NAME_PS)

$(NAME_C): $(OBJS_C)
	@$(MAKE) -C ./libft
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME)$(_END) ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME_C)$(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) ./libft/libft.a
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME)$(_END) ] > [ $(_BLUE)$(_BOLD)!$(_END) ][ done ]\n"

$(NAME_PS): $(OBJS_PS)
	@$(MAKE) -C ./libft
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME_PS)$(_END) ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME_PS)$(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJS_PS) ./libft/libft.a
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME_PS)$(_END) ] > [ $(_BLUE)$(_BOLD)!$(_END) ][ done ]\n"

clean:
	@$(MAKE) clean -C ./libft
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME)$(_END) ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)objs $(_END)\n"
	@$(RM) $(OBJS_C)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME)$(_END) ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)$(NAME_C) $(_END)\n"
	@$(RM) $(NAME_C)
	@printf "[ $(_PURPLE)$(_BOLD)$(NAME)$(_END) ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)$(NAME_PS) $(_END)\n"
	@$(RM) $(NAME_PS)

re: fclean
re: all

norm:
	norminette

test:
	./test.sh

.PHONY: all clean fclean re test_c