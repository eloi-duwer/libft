# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make_libft.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 18:54:25 by eduwer            #+#    #+#              #
#    Updated: 2021/06/04 01:19:06 by eduwer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_atoi.c \
	ft_bzero.c \
	ft_char_to_hex.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcat.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_itoa.c \
	ft_strsplit.c \
	ft_putchar.c \
	ft_legacy_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	get_next_line.c \
	ft_power.c \
	ft_abs.c \
	mlx_img_pixel_put.c \
	ft_itoa_intmax.c \
	ft_itoa_base_intmax.c \
	ft_char_to_unsigned.c \
	ft_reverse_string.c \
	ft_strtoupper.c \
	read_whole_file.c \
	ft_free_string_list.c

NAME = libft_noprintf.a

CC = clang

CFLAGS = -g -Wall -Wextra -Werror -I./include -O3

SRCF = ./srcs/libft/

OBJF = ./obj/libft/

OBJS = $(addprefix $(OBJF), $(SRC_NAME:.c=.o))

DEPS = $(OBJS:%.o=%.d)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

-include $(DEPS)

$(OBJF)%.o: $(SRCF)%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $(CFLAGS) -MMD -c $(addprefix $(SRCF), $*.c)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
