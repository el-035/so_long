CC = cc

CFILES = main.c events.c map.c path_validation.c window.c map_validation.c map_parsing.c game_rules.c error.c free_stuff.c
FT_PRINTF_FILES = ft_printf/ft_printf.c ft_printf/ft_printmore.c ft_printf/ft_printstuff.c 
#GNL_FILES = gnl/get_next_line.c gnl/get_next_line_utils.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

#creates object files from the c files given
OFILES = $(CFILES:.c=.o)

FT_PRINTF_OFILES = $(FT_PRINTF_FILES:.c=.o)
#GNL_OFILES = $(GNL_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

MLX = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11
FT_PRINTF = -I./ft_printf
#GNL = -I./gnl


NAME = so_long

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  

# all compiles all the c files into o files and archive them into libft.a
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#flags rcs: r adds o files to archive, c creates the archive if it doesnt exist yet, s for the index
$(NAME): $(OFILES) $(FT_PRINTF_OFILES) $(LIBFT)
	$(CC) $(OFILES) $(FT_PRINTF_OFILES) $(LIBFT) $(MLX) -o $(NAME)

#gets rid of all o files after creating application
clean:
	rm -f $(OFILES) $(FT_PRINTF_OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

#removes o files and library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

#to rebuild the whole project after cleaning everything
re: fclean all

#tells make that all, clean, re, and fclean should always be treated as commands and not as files to be created.
.PHONY: all clean re fclean