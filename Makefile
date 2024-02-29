NAME			= cub3D

SRCC_DIR		= src/

SRCS			= main.c

CC 				= cc

CFLAGS			= -Wextra -Wall -Werror -gdwarf-4

HEADERS			= $(SRCC_DIR)cub3D.h

LIB_DIR = lib/

LIBFT = $(LIB_DIR)libft.a
MLX = $(LIB_DIR)mlx/libmlx.a
INCLUDE_MLX = ./mlx/mlx.h ./mlx/mlx_int.h
MLXFLAGS = -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

OBJ_DIR = OBJ/

vpath %.c $(SRCC_DIR)

OBJ_PATH 		= $(SRCC_DIR)$(OBJ_DIR)

OBJ 			= $(patsubst %.c, $(OBJ_PATH)%.o, $(SRCS))

all : $(NAME)

$(NAME): $(OBJ) $(LIB) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -I $(MLXFLAGS) . -o $(NAME)

$(LIB): force
	@make -sC $(LIB_DIR)/libft
	@make -sC $(LIB_DIR)/mlx

clean :
	rm -f $(OBJ)
	make clean -C $(LIB_DIR)/libft
	make clean -C $(LIB_DIR)/mlx

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)/libft
	make fclean -C $(LIB_DIR)/mlx

re : fclean all

.PHONY: all clean re fclean force