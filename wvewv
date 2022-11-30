# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cbijman <cbijman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 11:43:00 by cbijman       #+#    #+#                  #
#    Updated: 2022/11/23 17:43:32 by cbijman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
EXEC = ./get_next_line

FILES 		= get_next_line.c get_next_line_utils.c
HEADERFILES = get_next_line.h

all:
	@echo "Compiling test variant without buffer flag!"
	@$(CC) -g -fsanitize=address $(FILES) -I $(HEADERFILES) -o $(EXEC) -D BUFFER_SIZE=42
	

.PHONY: all
