# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 18:40:32 by dolifero          #+#    #+#              #
#    Updated: 2024/05/08 18:24:30 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	commands_a.c\
					commands_b.c\
					commands.c\
					error_checks.c\
					initial_sorting.c\
					parsing.c\
					sorted_check.c\
					allocation_utilities.c\
					complicated_sorting.c
OBJS			= $(SRCS:.c=.o)

BONUS_SRCS		=	checker_program/checker.c\
					checker_program/parsing_checker.c
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= push_swap
BONUS_NAME		= checker

LIBFT_DIR 		= Libft
LIBFT			= $(LIBFT_DIR)/libft.a

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
BOLD_WHITE	=	\033[1;97m
BOLD_GREEN	=	\033[1;92m
NO_COLOR	=	\033[0m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[2;96m
WHITE		=	\033[0;97m

all:
				@echo "\n$(BOLD_CYAN)Starting $(BOLD_WHITE)[${NAME}] $(BOLD_CYAN)compilation..$(DEF_COLOR)\n"
				@Make ${NAME}
				@echo "\n$(BOLD_GREEN)${NAME} DONE!\n$(DEF_COLOR)"

clean:
				@echo "$(CYAN)"
				$(RM) $(OBJS) push_swap.o $(BONUS_OBJS) $(LIBFT_DIR)/*.o
				@echo "$(DEF_COLOR)"

fclean:
				@echo "$(CYAN)"
				$(RM) $(OBJS) push_swap.o $(BONUS_OBJS) $(NAME) $(BONUS_NAME) $(LIBFT_DIR)/*.o $(LIBFT)
				@echo "$(DEF_COLOR)"

bonus:			$(BONUS_NAME)

$(NAME):		$(OBJS) $(LIBFT)
				@echo "$(CYAN)"
				$(CC) $(CFLAGS) -o $(NAME) push_swap.c $(OBJS) -L$(LIBFT_DIR) -lft
				@echo "$(DEF_COLOR)"

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

$(BONUS_NAME):	$(BONUS_OBJS) $(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(OBJS) -L$(LIBFT_DIR) -lft


re:				fclean all

.PHONY:			all clean fclean re
