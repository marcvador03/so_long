#Directory definition
SRC_DIR := .

INC_DIR := .

OBJ_DIR := . 

BIN_DIR := .

#Filenames definition
NAME := ft_lib.a

SRC_NAMES := ft_isalpha.c \
	     ft_isascii.c \
	     ft_isdigit.c \
	     ft_isprint.c \
	     ft_memset.c \
	     ft_strlen.c \
	     ft_bzero.c 

SOURCES := $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean tclean re test show
all: $(OBJECTS) $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)  
	#cc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJ_DIR) $(BIN_DIR) $(TEST_DIR):  
ifneq ($@, .)
	mkdir -p $@
endif

flags:
	@echo $(CFLAGS)
show:
	@echo $(T_NAME)
	@echo $(T_OBJ)

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

re: fclean all
