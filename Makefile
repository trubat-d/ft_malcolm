ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/
SRC = ft_malcolm.c arp_listen.c input_check.c arp_builder.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=$(OBJ_PATH)%.o)

NAME = ft_malcolm
CC	= gcc
RM	= rm -f

INCLUDES = -I libft/ -I includes/

OPTIONS = -L libft -lft
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de $(NAME)...$(RESETTXT)"
		cd libft && $(MAKE)
		gcc $(CFLAGS) $(OBJ) -o $@ $(INCLUDES) $(OPTIONS) -g3 -fsanitize=address
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
		$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
		@$(RM) $(OBJ)
		@cd libft && $(MAKE) clean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de ft_malcolm et libft.a...$(RESETTXT)"
		@$(RM) $(NAME)
		@cd libft && $(MAKE) fclean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"
		
re:		fclean all

.PHONY: all clean fclean re 
