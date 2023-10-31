# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 19:57:11 by kryrodri          #+#    #+#              #
#    Updated: 2023/10/31 12:38:44 by kryrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g
FLAGS = -Wall -Wextra -Werror

# Nombre del proyecto
NAMEC	= client
NAMES	= server

# Archivos que uso al compilar
FUNCTIONC	=  client.c
FUNCTIONS	=  server.c
				
				
P_PF		= ft_printf
P_L			= libft

LIB_A		= libft.a
PF_A		= libftprintf.a
# Tenemos que transformar los .c en .o para poder compilar
OBJSC	= $(FUNCTIONC:.c=.o)
OBJSS	= $(FUNCTIONS:.c=.o)

# La libreria
HEADER	= minitalk.h
CP		= cp
# Se compila el archivo binario (ejecutable).
# all:  ${NAME}
all:  lib printf ${NAMEC} ${NAMES}

# esto es para que vaya al make de la carpeta libft y haga el all
lib:
	${MAKE} -C ${P_L} all
# ${CP} ${P_L}/${LIB_A} .

# esto es para que vaya al make de la carpeta printf y haga el all
printf:
	${MAKE} -C ${P_PF} all
# ${CP} ${P_PF}/${PF_A} .

# Se compila los objetos on las librerias y archivos.
${NAMEC}: ${OBJSC} ${HEADER}
	@echo "Ejecutando ${NAMEC}"
	$(CC) $(FLAGS) ${OBJSC} -o ${NAMEC} ./libft/$(LIB_A) ./ft_printf/$(PF_A)

# Se compila los objetos on las librerias y archivos.
${NAMES}: ${OBJSS} ${HEADER}
	@echo "Ejecutando ${NAMES}"
	$(CC) $(FLAGS) ${OBJSS} -o ${NAMES} ./libft/$(LIB_A) ./ft_printf/$(PF_A)

# Si no tuvieramos main.c usariamos el ar rcs en su lugar.
# ${NAME}: ${OBJS} ${HEADER}
# 	@echo "Generando la libreria ${NAME}..."
# 	ar rcs $(NAME) ${OBJS}

# Mirar google TODO
%.o: %.c Makefile ${HEADER}
	@echo "Compilando el objeto $@..."
	$(CC) -c $(FLAGS) $< -o $@
#	gcc -c -Wall -Wextra -Werror ...
# $@  = (todos los .o)
# $< = (Todos los inputs, seria todos los .c y su header (.h))
# -c es para convertir los .c en .o (.o = objetos, listos para usar)

# -f es para decir que si no existen ignoralos (evitando avisos como de errores innecesarios.)
clean:
	@echo "Ejecutando clean..."
	@rm -f $(OBJSC) $(OBJSS)
	${MAKE} -C ${P_PF} clean
	${MAKE} -C ${P_L} clean

fclean: clean
	@echo "Ejecutando fclean..."
	@rm -f $(NAMEC) $(NAMES) ./libft/$(LIB_A) ./ft_printf/$(PF_A)
	${MAKE} -C ${P_PF} fclean
	${MAKE} -C ${P_L} fclean

re: fclean all
	@echo "Ejecutando re..."

# Le dice al make que estos nombre no son archivos
.PHONY: re printf lib fclean clean all