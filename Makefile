# ****************************************************************************** #/
#                                                                                #/
#                                                           :::      ::::::::    #/
#    Makefile                                             :+:      :+:    :+:    #/
#                                                       +:+ +:+         +:+      #/
#    By: ael-madi <ael-madi@student.42.fr>            +#+  +:+       +#+         #/
#                                                   +#+#+#+#+#+   +#+            #/
#    Created: 2020/11/05 18:39:00 by ael-madi            #+#    #+#              #/
#    Updated: 2020/11/05 18:39:01 by ael-madi           ###   ########.fr        #/
#                                                                                #/
# ****************************************************************************** #/

NAME = libftprintf.a

SRC =	ft_printf.c\
		flags_width_prec.c\
		ft_putnbr.c\
		handle_char.c\
		handle_hexa.c\
		handle_int.c\
		handle_pointer.c\
		handle_string.c\
		handle_unsigned_int.c\
		length_num.c\
		spaces_zeros_hexa.c\
		spaces_zeros_int.c\
		utils1.c\
		utils2.c\

OBJ =	ft_printf.o\
		flags_width_prec.o\
		ft_putnbr.o\
		handle_char.o\
		handle_hexa.o\
		handle_int.o\
		handle_pointer.o\
		handle_string.o\
		handle_unsigned_int.o\
		length_num.o\
		spaces_zeros_hexa.o\
		spaces_zeros_int.o\
		utils1.o\
		utils2.o\

FLAGS = -Werror -Wall -Wextra

all: ${NAME}

#test: ${NAME} main.c
#	@gcc ${FLAGS} -I./inc/ -L. -lftprintf main.c && ./a.out

norme:
	@echo "Checking the norme..."
	@norminette *.c
	@norminette *.h

bonus: all

${NAME}:${OBJ}
		@ar rcs ${NAME} ${OBJ}
		@echo "The library is done"

%.o: %.c
	@gcc ${FLAGS} -I ${NAME} -c $< -o $@

clean:
	@rm -rf ${OBJ} a.out a.out.dSYM
	@echo "Cleaned"

fclean: clean
		@rm -rf ${NAME} obj
		@echo "Force Cleaned"

test:
	@gcc ${FLAGS} main.c ${NAME}
	@./a.out	

re: fclean all

.PHONY: clean fclean all re