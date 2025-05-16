CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) 
LDFLAGS = -lX11 -lm

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_FILES = main.c event/delete.c event/handle.c event/select.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
INC_FILES = include/visu.h include/keycode_i.h

NAME = visu

ifdef DEBUG
CFLAGS += -g3
endif	

all: $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(_CYAN)[LINKING]$(_END) $(NAME) est créé !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_CYAN)[COMPILATION]$(_END) Création de l'objet : $@"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_BLUE)[CLEAN]$(_END) Suppression des fichiers objets."

fclean: clean
	@rm -rf $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de $(NAME) et de la copie de libft."

re: fclean all

lint:
	cppcheck $(SRC_DIR) --enable=all --suppress=unusedFunction \
		--suppress=variableScope --suppress=missingIncludeSystem \
		2>&1 > /dev/null

.PHONY: all clean fclean re ascii
