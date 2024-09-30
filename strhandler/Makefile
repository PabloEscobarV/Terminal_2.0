# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 17:51:31 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/09/30 22:01:47 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = strhandler
LIBNAME = libstrhandler.a
TEST = test
TESTFILE = test.c
READLINE = readline

SRCDIR = src
OBJDIR = objs

LIBFT = ft
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

VARHANDLER = varhandler
VARHANDLERDIR = ../$(VARHANDLER)
LIBFTDIR = ../libft
LIB_HST = -L$(VARHANDLERDIR) -l$(VARHANDLER)

CC = gcc
CFLAGS = -Wall -Wextra
LIBRS = -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libfull: $(LIBNAMEFULL)

cobj: $(OBJ)

run: $(LIBNAME)
	$(CC) $(CFLAGS) $(TESTFILE) -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

re: fclean lib

clean:
	$(MAKE) -C $(VARHANDLERDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(VARHANDLERDIR) fclean
	rm -rf $(NAME) $(LIBNAME) $(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(VARHANDLERDIR)
	ar -x $(VARHANDLERDIR)/lib$(VARHANDLER).a
	ar -x $(LIBFTDIR)/lib$(LIBFT).a
	mv *.o $(OBJDIR)
	ar -rc $(LIBNAME) $(OBJDIR)/*.o
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@

