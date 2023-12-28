NAME    = cub3D
CC = gcc
INC = cub3d.h
CFLAGS = -Wall -Wextra -Werror -L./mlx -lmlx -framework AppKit -framework OpenGL -g
LIBFT = libft/libft.a
RM = rm -rf
SRCS    =	main.c				\
			
OBJS = $(SRCS:.c=.o)
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

MLX = ./mlx/libmlx.a

all: $(NAME)

$(MLX):
		@make -C ./mlx

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo $(B)cub3d is ready!

%.o: %.c $(INC)
	@echo $(R)Complining [$<]
	@${CC} -c $< -o $@ -Wall -Werror -Wextra -g

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

norm:
	@norminette $(SRCS)
	@norminette cub3d.h
	@norminette libft/

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(MLX)
	@echo $(R)Removed [$(NAME)]
	@make fclean -C libft/

re: fclean all

.PHONY: all, clean, fclean, re
