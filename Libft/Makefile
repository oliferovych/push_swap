# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 14:48:30 by dolifero          #+#    #+#              #
#    Updated: 2024/05/08 18:00:47 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c / ft_printf

SRCS			=	ft_isalpha.c\
					ft_isdigit.c\
					ft_isalnum.c\
					ft_isascii.c\
					ft_isprint.c\
					ft_strlen.c\
					ft_memset.c\
					ft_bzero.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_strlcpy.c\
					ft_strlcat.c\
					ft_toupper.c\
					ft_tolower.c\
					ft_strchr.c\
					ft_strrchr.c\
					ft_strncmp.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_strnstr.c\
					ft_atoi.c\
					ft_calloc.c\
					ft_strdup.c\
					ft_substr.c\
					ft_strjoin.c\
					ft_strtrim.c\
					ft_split.c\
					ft_itoa.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					get_next_line.c\
					ft_printf.c\
					ft_putptr.c\
					integer_print.c\
					utilities.c

OBJS			= $(SRCS:.c=.o)

BONUS_SRCS		=	ft_lstnew_bonus.c\
					ft_lstadd_front_bonus.c\
					ft_lstsize_bonus.c\
					ft_lstlast_bonus.c\
					ft_lstadd_back_bonus.c\
					ft_lstdelone_bonus.c\
					ft_lstclear_bonus.c\
					ft_lstiter_bonus.c\
					ft_lstmap_bonus.c
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

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

$(NAME):		$(OBJS)
				@ar -crs ${NAME} ${OBJS}
				@echo "🔗 $(CYAN) ar -crs ${NAME} ${OBJS} $(DEF_COLOR)"

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
				@echo "\n$(BOLD_CYAN)Cleaning $(BOLD_WHITE)[${NAME}] $(BOLD_CYAN)..$(DEF_COLOR)\n"
				@echo "$(CYAN)"
				${RM} ${OBJS}
				@echo "$(DEF_COLOR)"
				@echo "\n$(BOLD_GREEN)${NAME} ALLCLEAN!\n$(DEF_COLOR)"

fclean:
				@echo "\n$(BOLD_CYAN)FCleaning $(BOLD_WHITE)[${NAME}] $(BOLD_CYAN)..$(DEF_COLOR)\n"
				@echo "$(CYAN)"
				${RM} ${OBJS} ${NAME}
				@echo "$(DEF_COLOR)"
				@echo "\n$(BOLD_GREEN)${NAME} 🚽ALLFCLEAN!\n$(DEF_COLOR)"

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
