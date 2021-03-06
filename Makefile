# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:26:19 by eduwer            #+#    #+#              #
#    Updated: 2020/02/14 12:22:02 by eduwer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = append_string.c \
	context_control.c \
	main_functions.c \
	exposed_functions.c \
	double_utils.c \
	parsing/flags_parsing.c \
	parsing/get_convertion.c \
	parsing/get_modifiers.c \
	parsing/percent_convertion_process.c \
	parsing/precision_field_width.c \
	convert/convert_string.c \
	convert/convert_int.c \
	convert/convert_uint.c \
	convert/space_and_plus_flag.c \
	convert/field_width.c \
	convert/convert_octal_hexa.c \
	convert/convert_char.c \
	convert/convert_double.c

NAME = libft.a

CC = clang

CFLAGS = -I./include -I./libft/include -Wall -Wextra -Werror -g -O3

SRCF = ./srcs/ft_printf/

OBJF = ./obj/ft_printf/

OBJS = $(addprefix $(OBJF), $(SRC_NAME:.c=.o))

DEPS = $(OBJS:%.o=%.d)

LFT = ./libft_noprintf.a

all : compile 

$(NAME) : $(LFT) $(OBJS)
	@$(MAKE) -f ./Make_libft.mk
	cp $(LFT) $(NAME)
	ar -rc libft.a $(OBJS)
	ranlib libft.a

-include $(DEPS)

$(OBJF)%.o : $(SRCF)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -MMD -c $(addprefix $(SRCF), $*.c)

clean :
	rm -rf	$(OBJS)
	make -f ./Make_libft.mk clean

fclean : clean
	rm -rf $(NAME)
	make -f ./Make_libft.mk fclean

re : fclean all

compile:
	$(MAKE) -f ./Make_libft.mk
	$(MAKE) $(NAME)