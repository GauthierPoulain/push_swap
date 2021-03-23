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

NAME_C = checker

HEADERS_C = checker_src/includes/checker.h

CC = clang
CFLAGS = -Wall -Wextra -Werror -fno-builtin -O3

MAKE = make --no-print-directory

OBJS_C = $(SRCS_C:%.c=%.o)
SRCS_C = \
	checker_src/checker.c \
	checker_src/handle_close.c \
	checker_src/parsing/parsing.c \
	checker_src/parsing/check.c \
	checker_src/print_stacks.c \

%.o: %.c $(HEADERS_C)
	@printf "[ ${_PURPLE}${_BOLD}${NAME_C}${_END} ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_C)

$(NAME_C): $(OBJS_C)
	@$(MAKE) -C ./libft
	@printf "[ ${_PURPLE}${_BOLD}${NAME_C}${_END} ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME_C)$(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_C) ./libft/libft.a
	@printf "[ ${_PURPLE}${_BOLD}${NAME_C}${_END} ] > [ $(_BLUE)$(_BOLD)!$(_END) ][ done ]\n"

clean:
	@$(MAKE) clean -C ./libft
	@printf "[ ${_PURPLE}${_BOLD}${NAME_C}${_END} ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)objs $(_END)\n"
	@$(RM) $(OBJS_C)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@printf "[ ${_PURPLE}${_BOLD}${NAME_C}${_END} ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)$(NAME_C) $(_END)\n"
	@$(RM) $(NAME_C)

re: fclean
re: all

norm:
	norminette

.PHONY: all clean fclean re test_c