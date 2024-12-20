CC = cc

CFILES = main.c events.c map.c path_validation.c window.c map_validation.c map_parsing.c game_rules.c error.c free_stuff.c
LIBFT_FILES = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
	libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c \
	libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
	libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c \
	libft/ft_strtrim.c libft/ft_itoa.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c \
	libft/ft_putchar_fd.c libft/ft_striteri.c libft/ft_strmapi.c libft/ft_split.c
FT_PRINTF_FILES = ft_printf/ft_printf.c ft_printf/ft_printmore.c ft_printf/ft_printstuff.c 
GNL_FILES = gnl/get_next_line.c gnl/get_next_line_utils.c

#creates object files from the c files given
OFILES = $(CFILES:.c=.o)
LIBFT_OFILES = $(LIBFT_FILES:.c=.o)
FT_PRINTF_OFILES = $(FT_PRINTF_FILES:.c=.o)
GNL_OFILES = $(GNL_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
#del extra stuff
MLX = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11
FT_PRINTF = -I./ft_printf
GNL = -I./gnl
LIBFT = -I./libft

NAME = so_long

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  

# all compiles all the c files into o files and archive them into libft.a
all: $(NAME)

#flags rcs: r adds o files to archive, c creates the archive if it doesnt exist yet, s for the index
$(NAME): $(OFILES) $(LIBFT_OFILES) $(FT_PRINTF_OFILES) $(GNL_OFILES)
	$(CC) $(OFILES) $(LIBFT_OFILES) $(FT_PRINTF_OFILES) $(GNL_OFILES) $(MLX) -o $(NAME)
#does the same as the one up but for bonus
#bonus: $(BONUS_OFILES)
#	ar -rcs $(NAME) $(BONUS_OFILES)

#gets rid of all o files after creating application
clean:
	rm -f $(OFILES) $(LIBFT_OFILES) $(FT_PRINTF_OFILES) $(GNL_OFILES)

#removes o files and library
fclean: clean
	rm -f $(NAME)

#to rebuild the whole project after cleaning everything
re: fclean all

#tells make that all, clean, re, and fclean should always be treated as commands and not as files to be created.
.PHONY: all clean re fclean