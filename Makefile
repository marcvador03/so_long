NAME := libft.a

SRC_DIR := .

INC_DIR := .

OBJ_DIR := .

BIN_DIR := .

SOURCES := $(SRC_DIR)/main.c 

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

.PHONY: all flags clean fclean re
all: $(NAME)

$(NAME): $(OBJECTS) | $(BIN_DIR)
	cc $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR): 
ifneq ($(OBJ_DIR), .)
	mkdir -p $@
endif

$(BIN_DIR): 
ifneq ($(BIN_DIR), .)
	mkdir -p $@
endif

flags:
	echo $(CFLAGS)

clean: 
	rm -rf $(OBJ_DIR)/*.o
ifneq ($(OBJ_DIR), .)
	rmdir $(OBJ_DIR)
endif
ifneq ($(BIN_DIR), .)
	rmdir $(BIN_DIR)
endif

fclean: clean
	rm -rf $(NAME)

re: fclean all
