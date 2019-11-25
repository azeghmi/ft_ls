# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 15:34:30 by thflahau          #+#    #+#              #
#    Updated: 2019/05/09 12:24:03 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

NAME			=	ft_ls

# Folders
SRCDIR			=	srcs/
OBJDIR			=	objs/
INCDIR			=	include/
LIBDIR			=	libft/
PRINTF			=	ft_printf/

# Source files
SRCS			=	main.c					parsing.c					\
					tools.c					display_default.c			\
					ft_lstnew.c				ft_lst_pushback.c			\
					ft_lstdel.c				display_file_informations.c	\
					ft_lstreverse.c			ft_append_files.c			\
					ft_filelstdel.c			sort_std_option.c			\
					sort_compare.c			blocks_print.c				\
					padding.c				single_files.c				\
					read_links.c			ft_lstsize.c				\
					recurse_lsdir.c 		display_default2.c
OBJS			=	$(SRCS:.c=.o)

# Prefixes
SRCDIR1			=	$(addprefix $(SRCDIR), $(SRCS))
OBJDIR1			=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

# Compilation flags
INCDIRF			=	-I $(INCDIR)
LIBFT			=	-L $(LIBDIR) -lft
LIBFT_PRINTF	=	-L $(PRINTF) -lftprintf
CFLAGS			=	-Wall -Wextra -Werror -Wpadded

# Rules
all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c include/ft_ls.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIRF) -c -o $@ $<

$(NAME): $(OBJDIR1)
	@make -C $(PRINTF)
	@make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(LIBFT_PRINTF) $(LIBFT) -o $@ $^
	@echo "\t\033[32m[*]\033[0m Compiled $(NAME) successfully"

clean:
	make $@ -C $(PRINTF)
	make $@ -C $(LIBDIR)
	/bin/rm -f $(OBJDIR1)

fclean: clean
	make $@ -C $(PRINTF)
	make $@ -C $(LIBDIR)
	/bin/rm -f $(NAME)

re: fclean all

.phony: $(NAME) fclean clean re all

.SILENT: clean fclean
