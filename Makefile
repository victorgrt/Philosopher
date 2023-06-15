# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victor <victor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:10:40 by vgoret            #+#    #+#              #
#    Updated: 2023/06/15 18:34:18 by victor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ! ARGUMENTS ! #

NAME    =	philosopher
CCFLAGS =	-g -pthread -Wall -Werror -Wextra
CC      =	gcc

################################################################################
# * SRC * #

SRC = ./src/main.c \
	./src/utils.c \
	./src/error.c \
	./src/parsing.c \
	./src/structure.c \


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
	@echo ${GRAY}"\n██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗\n██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗\n██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝\n██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗\n██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║\n╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n"${NONE}
	@echo ${BLUE}${CURSIVE}"○  https://github.com/victorgrt/Philosopher\n"${NONE}
	@echo ${YELLOW}${BOLD}"○  By vgoret\n"${NONE}
	@$(MAKE) all --no-print-directory

all: ${NAME} 

${NAME} : ${OBJ}
	@echo ${BOLD} ${BLUE} "\033[1m○	Compiling files..." ${NONE}
	${CC} ${CCFLAGS} ${OBJ} -o ${NAME}
	@echo "\n"
	@sleep 0.5
	@echo ${BOLD} ${GREEN} "○	Compiled !" ${NONE}
	@echo "./${NAME} \n"
	@sleep 0.5
	@echo ${BOLD} ${GRAY} "‣	Usage : ./philo <number_of_philosopher> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"

%.o: %.c
	@$(CC) ${CCFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean	
	@echo ${RED} ${BOLD} "‣	Deleting..." ${NONE}
	@${foreach value, ${NAME}, echo ${value};}
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@${foreach value, $(OBJ), echo ${value};}
	@rm -f ${NAME}
	@rm -f ./a.out
	@echo ${RED} ${BOLD} "\n‣ Folder Cleaned Sucessfully" ${NONE}

re : fclean all

.PHONY : all clean fclean all re

title2 : 
	@echo ${BLUE}"#------------------------------------------#"
	@echo "#                ${BOLD}Philosopher${NONE}${BLUE}               #"
	@echo "#------------------------------------------#"
	@echo "|    ⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿	    |"
	@echo "|    ⣶⣤⣤⣤⣉⣉⣙⣛⡛⠻⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⠟⠛⠛⠛⠻⠿⠿⠿⠿⢿⣿⣷⣶⣶⣦⣤⣤⣉⣉⣉⠛⢻⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣶⣶⣶⣶⣦⣤⣤⣤⣤⣌⣉⣉⣉⣉⠛⠛⢻⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⢠⡿⠋⣽⠟⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⢠⡿⢁⣼⠋⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠻⣧⠘⢿⡀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠙⣷⡈⢻⣆⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣠⣿⣃⣼⣏⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⡏⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⢹     |"
	@echo "|    ⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿     |"
	@echo "|    ⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿     |"
	@echo "|    ⣿⣿⣿⣿⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡶⠶⠶⠶⠶⠶⠶⢶⣾⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "|    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿     |"
	@echo "------------------------------------------"
