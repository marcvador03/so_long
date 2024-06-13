NAME := libft.a

TEST_NAME = t_$(SRC_NAME)

SRC_DIR := .

INC_DIR := .

OBJ_DIR := obj 

BIN_DIR := .

TEST_DIR := t_dir

SRC_NAME := ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c 

SOURCES :=$(SRC_DIR)/$(SRC_NAME) \

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

.PHONY: all flags clean fclean re
all: $(NAME)

$(NAME): $(OBJECTS) | $(BIN_DIR)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(TEST_NAME): $(TEST_DIR)/$(TEST_NAME) | $(TEST_DIR)
	cc $(CFLAGS) -I $(INC_DIR) -o $@ $^

$(OBJ_DIR): 
ifneq ($(OBJ_DIR), .)
	mkdir -p $@
endif

$(BIN_DIR): 
ifneq ($(BIN_DIR), .)
	mkdir -p $@
endif

$(TEST_DIR): 
ifneq ($(TEST_DIR), .)
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
