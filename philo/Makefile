# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 18:13:14 by fluchten          #+#    #+#              #
#    Updated: 2023/03/05 22:26:34 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror #${FSANITIZE}
FSANITIZE = -fsanitize=address -g
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS_DIR = srcs
SRCS =	args/check_args.c \
		args/parse_args.c \
		initialization/init_forks.c \
		initialization/init_philos.c \
		initialization/init_threads.c \
		initialization/initialization.c \
		philos/philos_actions.c \
		philos/philos_routines.c \
		philos/philos_utils.c \
		utils/utils.c \
		main.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS_DIR}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re