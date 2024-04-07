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
					secure_ft.c \
					parser.c error.c \
					convert.c math_ft.c graphics_ft.c \
					keys_bindings.c \
					\
					debug.c

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
CFLAGS				= -Wextra -Wall -Werror -MMD -gdwarf-4
EXFLAGS				= -L lib/mlx -lmlx -lXext -lX11 -lm -lbsd

FLAGS				= $(CFLAGS) $(EXFLAGS)

#					RULES

all : $(NAME)
	$(LOG__ALLSUCCESS)

$(NAME): $(DIRS) $(LIB) $(OBJ)
	$(call logs, $(CYAN),"Compiling\ Executable")
	$(CC) $(FLAGS) $(OBJ) $(LIB) -I . -o $(NAME)
	$(LOG__SUCCESS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : force
	@make -sC lib/libft
	@make -sC lib/gnl
	@make -sC lib/mlx
	$(call logs, $(CYAN),"Compiling\ LIBS")
	$(LOG__SUCCESS)

$(DIRS) :
	$(call logs, $(CYAN),"Creating\ directories")
	@mkdir -p $(DIRS)
	$(LOG__SUCCESS)

clean : 
	@make clean -sC lib/libft
	@make clean -sC lib/gnl
	# @make clean -sC lib/mlx
	$(call logs, $(YELLOW),"Cleaning\ OBJ\ files")
	rm -rf $(OBJ_DIR)
	$(LOG__SUCCESS)

fclean : clean
	@make fclean -sC lib/libft
	@make fclean -sC lib/gnl
	$(call logs, $(YELLOW),"Cleaning\ Executable")
	rm -f $(NAME)
	$(LOG__SUCCESS)
	rm -rf lib/mlx/libmlx.a

re : fclean all

-include $(DEP)

.SILENT:

.PHONY: all clean re fclean force