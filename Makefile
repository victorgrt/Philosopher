# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:10:40 by vgoret            #+#    #+#              #
#    Updated: 2023/06/14 16:38:34 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ! ARGUMENTS ! #

NAME    =	philosopher
CCFLAGS =	-Wall -Werror -Wextra
CC      =	gcc

################################################################################
# * SRC * #

SRC = ./src/main.c \
	./src/utils.c \
	./src/error.c \
	./src/parsing.c \


OBJ = ${SRC:.c=.o}

################################################################################
# ? RULES ? #

NONE='\033[0m'
CLIGNO = '\033[5m'
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BOLD='\033[1m'
BLUE='\033[0;34m'

title :
	@echo ${GRAY}"██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗\n██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗\n██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝\n██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗\n██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║\n╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n"${NONE}
	@echo ${BLUE}${CURSIVE}""${NONE}
	@echo ${YELLOW}${BOLD}"○ By vgoret"
	@$(MAKE) all --no-print-directory

all: ${NAME} 

${NAME} : ${OBJ}
	@echo ${BOLD} ${BLUE} "\033[1m○	Compiling files..." ${NONE}
	@${CC} ${OBJ} -o ${NAME}
	@echo ${BOLD} ${GREEN} "○	Compiled !" ${NONE}
	@echo ${BOLD} ${GRAY} "‣	Usage : ./philo <number_of_philosopher> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"

%.o: %.c
	@$(CC) ${CCFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean	
	@echo ${RED} ${BOLD} "‣	Deleting..." ${NONE}
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@${foreach value, $(OBJ), echo ${value};}
	@rm -f ${NAME}
	@rm -f ./a.out
	@echo ${RED} ${BOLD} "\n‣ Folder Cleaned Sucessfully" ${NONE}

re : fclean all

.PHONY : all clean fclean all re

#-----------------------------------
#|           Philosopher             |
#|-----------------------------------|
#|○ Github : https://github.com/victorgrt/philosopher                      |
#|$                                  |
#|                                   |
#|                                   |
#|                                   |
# -----------------------------------