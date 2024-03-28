#					MACRO INITIALIZATION

NAME				= gnl.a

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
LOG__ALLSUCCESS		= @printf "\033[1;92m\n\rGNL DONE $(RESET)\n\n"

#			DIRECTORIES
SRC_DIR				= src/
HEAD_DIR			= src/
LIB_DIR				= lib/
OBJ_DIR				= $(SRC_DIR)OBJ/

#			FILES
ALL_SRC				= get_next_line.c \
					gnl_utils.c \

ALL_HEADERS			= gnl.h

ALL_LIBS			= lib.a

PREFIX_SRC			= $(addprefix $(SRC_DIR), $(ALL_SRC))
PREFIX_LIB			= $(addprefix $(LIB_DIR), $(ALL_LIBS))
PREFIX_HEADER		= $(addprefix $(HEAD_DIR), $(ALL_HEADERS))
SRC					= $(wildcard $(PREFIX_SRC))
HEADER				= $(wildcard $(PREFIX_HEADER))
LIB					= $(wildcard $(PREFIX_LIB))
OBJ					= $(patsubst %.c, $(OBJ_DIR)%.o, $(notdir $(ALL_SRC)))
DEP					= $(OBJ:.o=.d)

DIRS				= $(sort $(dir $(OBJ)))

#			UTILITIES
ALIB				= ar crs
CC					= cc
CFLAGS				= -Wextra -Wall -Werror -MMD -gdwarf-4

#					RULES

all : $(NAME)
	$(LOG__ALLSUCCESS)

$(NAME): $(DIRS) $(OBJ)
	$(ALIB) $(NAME) $(OBJ)


$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : force
	$(call logs, $(CYAN),"Compiling\ LIBS")
	@make -sC $(LIB_DIR)

$(DIRS) :
	@mkdir -p $(DIRS)

clean : 
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEP)

.SILENT:

.PHONY: all clean re fclean force