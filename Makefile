#					MACRO INITIALIZATION

NAME				= Cub3D


#		DEBUG TOOLS

RESET				= \033[0m
UNDERLINE			= \033[4m
BOLD				= \033[1m
RED					= \033[0;91m
GREEN				= \033[0;92m
YELLOW				= \033[0;93m
BLUE				= \033[0;94m
PURPLE				= \033[0;35m
CYAN				= \033[0;96m
WHITE				= \033[0;37m

define	logs
	@printf "$(1)\r\t $(2) $(RESET)"
endef

LOG__TITLE			= @echo "$(BOLD) \nULTIMAKEFILE - CUB3D $(RESET)\n\n\n"
LOG__PREL			= @echo "$(PURPLE) \nMAKEFILE $(RESET)\n"
LOG__SUCCESS		= @printf "$(GREEN)\rDONE $(RESET)\n"
LOG__ALLSUCCESS		= @printf "\033[1;92m\n\rALL DONE $(RESET)\n\n"


#			DIRECTORIES

SRC_DIR				= src/
HEAD_DIR			= src/
LIB_DIR				= lib/
OBJ_DIR				= $(SRC_DIR)OBJ/


#			FILES

ALL_SRC				= main.c init.c init_map.c reset.c \
					memory_edit.c memory_edit_bis.c memory_scan.c memory_scan_bis.c \
					memory_str_edit.c \
					secure_ft.c \
					parser.c error.c \
					misc.c convert.c math_ft.c \
					keys_bindings.c \
					graphic.c gameplay.c render.c draw.c \
					\
					bonus_minimap.c \
					\
					safemode.c \
					debug.c \
					sandbox.c

ALL_HEADERS			= cub3d.h

ALL_LIBS			= libft/libft.a \
					gnl/gnl.a


PREFIX_SRC			= $(addprefix $(SRC_DIR), $(ALL_SRC))
PREFIX_LIB			= $(addprefix $(LIB_DIR), $(ALL_LIBS))
PREFIX_HEADER		= $(addprefix $(HEAD_DIR), $(ALL_HEADERS))
SRC					= $(wildcard $(PREFIX_SRC))
HEADER				= $(wildcard $(PREFIX_HEADER))
LIB					= $(PREFIX_LIB)
OBJ					= $(sort $(patsubst %.c, $(OBJ_DIR)%.o, $(notdir $(ALL_SRC))))
DEP					= $(OBJ:.o=.d)

DIRS				= $(sort $(dir $(OBJ)))


#			UTILITIES

CC					= cc
CFLAGS				= -Wextra -Wall -Werror -MMD

FLAGS				= $(CFLAGS)
ALL_INCLUDE			= -I $(SRC_DIR) \
					-I /usr/include \
					$(MLX_INCLUDE)


#			MLX
MLX_DIR				= $(LIB_DIR)mlx_linux
MLX_LIB				= $(MLX_DIR)/libmlx.a
MLX_HEAD			= $(MLX_DIR)/mlx.h
MLX_INCLUDE			= -I $(MLX_DIR)
MLX_FLAGS			= -L $(MLX_DIR) $(MLX_INCLUDE) -lmlx -lXext -lX11 -lm -lbsd -lz

MLX_ALL				= $(MLX_LIB) $(MLX_FLAGS)

#					RULES

all : $(NAME)
	$(LOG__ALLSUCCESS)

$(NAME): $(LIB) $(OBJ)
	$(call logs, $(CYAN),"Compiling\ Executable")
	$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX_ALL) $(ALL_INCLUDE) -o $(NAME)
	$(LOG__SUCCESS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : force
	make -sC lib/libft
	make -sC lib/gnl
	make -sC $(MLX_DIR)
	$(call logs, $(CYAN),"Compiling\ LIBS")
	$(LOG__SUCCESS)

$(DIRS) :
	$(call logs, $(CYAN),"Creating\ directories")
	@mkdir -p $(DIRS)
	$(LOG__SUCCESS)

clean : 
	make clean -sC lib/libft
	make clean -sC lib/gnl
	# @make clean -sC $(MLX_DIR)
	$(call logs, $(YELLOW),"Cleaning\ OBJ\ files")
	rm -rf $(OBJ_DIR)
	$(LOG__SUCCESS)

fclean : clean
	make fclean -sC lib/libft
	make fclean -sC lib/gnl
	$(call logs, $(YELLOW),"Cleaning\ Executable")
	rm -f $(NAME)
	$(LOG__SUCCESS)
	rm -rf lib/mlx/libmlx.a

re : fclean all

-include $(DEP)

.SILENT:

.PHONY: all clean re fclean force