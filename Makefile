# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:02:18 by aoudija           #+#    #+#              #
#    Updated: 2023/02/01 16:10:37 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# B_NAME = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

mlx_FLAGS = -lmlx -framework OpenGL -framework AppKit

DEPS = so_long.h

FILES = so_long.c

# FILES_B = checker.c checker_fts.c rules_1.c rules_2.c rules_3.c ft_putsr.c libft_tools.c libft_tools2.c\
# 		  ft_split.c ft_strtrim.c check_errors.c get_next_line.c ft_tools_1.c ft_tools_2.c \
# 			ft_lstclear.c

OBG = $(FILES:.c=.o)

# OBGB = $(FILES_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(OBG) $(mlx_FLAGS) -o $(NAME) 

# bonus : $(OBGB)
# 	$(CC) $(CFLAGS) $(OBGB) -o $(B_NAME)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<
# $(OBGB)
clean:
	rm -f $(OBG)
# $(B_NAME)
fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re