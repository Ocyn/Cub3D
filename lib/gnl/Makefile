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
LOG__ALLSUCCESS		= @printf "\033[1;92m\n\rALL DONE $(RESET)\n\n"

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

DIRS				= $(dir $(OBJ))

#			UTILITIES
ALIB				= ar crs
CC					= cc
CFLAGS				= -Wextra -Wall -Werror -MMD -gdwarf-4

#					RULES

all : $(NAME)
	$(LOG__ALLSUCCESS)

$(NAME): $(DIRS) $(OBJ)
	$(call logs, $(CYAN),"Compiling\ Executable")
	$(ALIB) $(NAME) $(OBJ)
	$(LOG__SUCCESS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(call logs, $(CYAN),"Compiling\ OBJ\ files")
	$(CC) $(CFLAGS) -c $< -o $@
	$(LOG__SUCCESS)

$(LIB) : force
	$(call logs, $(CYAN),"Compiling\ LIBS")
	@make -sC $(LIB_DIR)
	$(LOG__SUCCESS)

$(DIRS) :
	$(call logs, $(CYAN),"Creating\ directories")
	@mkdir -p $(DIRS)
	$(LOG__SUCCESS)

clean : 
	$(call logs, $(YELLOW),"Cleaning\ OBJ\ files")
	rm -rf $(OBJ_DIR)
	$(LOG__SUCCESS)

fclean : clean
	$(call logs, $(YELLOW),"Cleaning\ Executable")
	rm -f $(NAME)
	$(LOG__SUCCESS)

re : fclean all

-include $(DEP)

.SILENT:

.PHONY: all clean re fclean force