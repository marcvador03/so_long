#Filenames definition
NAME := ft_lib.a

SRC_NAMES := ft_isalpha.c \
	     ft_isascii.c \
	     ft_isdigit.c \
	     ft_isprint.c \
	     ft_memset.c \
	     ft_strlen.c \
	     ft_bzero.c 
ADD_NAMES := t_dir/ft_putchar.c

#Directory definition
SRC_DIR := .

INC_DIR := .

OBJ_DIR := obj

BIN_DIR := .

TEST_DIR := t_dir

SOURCES := $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

T_SRC := $(patsubst %.c, $(TEST_DIR)/t_%.c, $(SRC_NAMES))

T_OBJ := $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/%.o, $(T_SRC))

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean tclean re test
all: $(OBJECTS) $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)  
	cc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

test_%: %.c | $(T_SRC)
	cc  \
	-I $(INC_DIR) \
	-c $< $(TEST_DIR)/$@ $(ADD_NAMES)\
	-o t_$@.o

$(TEST_DIR)/t_%.c: $(TEST_DIR)
	touch $@

$(OBJ_DIR) $(BIN_DIR) $(TEST_DIR):  
ifneq ($@, .)
	mkdir -p $@
endif

flags:
	echo $(CFLAGS)

clean: 
	rm -rf $(OBJ_DIR)/*.o
ifneq ($(OBJ_DIR), .)
	rmdir $(OBJ_DIR)
endif

fclean: clean
	rm -rf $(NAME)
ifneq ($(BIN_DIR), .)
	rmdir $(BIN_DIR)
endif

tclean:
	rm -rf $(TEST_DIR)/*.o
re: fclean all
