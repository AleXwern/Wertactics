# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anystrom <anystrom@hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 16:09:13 by anystrom          #+#    #+#              #
#    Updated: 2021/05/07 12:37:41 by anystrom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLG = -O1
SRCS = ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c ft_strsub.c \
	ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c \
	ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c \
	ft_tolower.c ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c \
	ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_putstr.c \
	ft_striter.c ft_strnequ.c ft_isalpha.c ft_memdel.c ft_putstr_fd.c \
	ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c ft_strcat.c \
	ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c \
	ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c \
	ft_strlen.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c \
	ft_strmap.c ft_strstr.c ft_wordlen.c ft_isblank.c ft_isnegative.c \
	ft_intsize.c ft_isextascii.c get_next_line.c ft_puthex.c ft_lcm.c \
	ft_abs.c ft_fabs.c ft_putnbrln.c ft_quadjoin.c ft_splitfree.c \
	ft_strfjoin.c ft_printmem.c ft_atof.c ft_strsjoin.c ft_listlen.c \
	ft_realloc.c
OBJS = $(SRCS:.c=.o)
ASM = $(SRCS:.c=.s)
INCLS = ./
OBJFLD = ../obj/
GREEN = \033[0;32m
PURPLE = \033[0;35m
STOP = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

#-Wall -Wextra -Werror
%.o:%.c
	gcc $(FLG) -I $(INCLS) -o $@ -c $<
	echo "Compiling Libft -> $(GREEN)$@$(STOP)"

%.s:%.c
	gcc $(FLG) -S -I $(INCLS) -o $@ $<
	echo "Compiling Libft -> $(GREEN)$@$(STOP)" 

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "Compiled $(PURPLE)$(NAME)$(STOP)"
	mv $(OBJS) ../obj
	mv $(NAME) ../obj

asm: $(ASM)
	@echo "Asm output assembled."

clean:
	@/bin/rm -f $(addprefix $(OBJFLD),$(OBJS))
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(ASM)

fclean: clean
	@/bin/rm -f $(addprefix $(OBJFLD),$(NAME))
	@/bin/rm -f $(NAME)

re: fclean all
