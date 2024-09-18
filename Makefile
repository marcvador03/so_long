#Directory definition
LIBFT_DIR := libft
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib

#Filenames definition
NAME := push_swap

SRC_NAMES := push_swap.c \
			 push_swap_stack_utils.c \
			 push_swap_utils.c \
			 push_swap_operations.c \
			 push_swap_algo_utils.c \
			 push_swap_search.c \
			 push_swap_parse_checks.c \
			 three_five_sort.c \
			 radix_sort.c \
			 turk_sort.c \
			 list_display.c


SOURCES := $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

LIBFT_NAME := libft.a 
LIBFT_TAG := $(patsubst lib%.a, -l%, $(LIBFT_NAME)) 

DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft bonus
all: libft $(OBJECTS) $(NAME) 

$(NAME): $(OBJECTS) 
	cc $(CFLAGS) -L $(LIB_DIR) $(DEBUG) $(OBJECTS) -o $@ $(LIBFT_TAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) $(DEBUG) -c -o $@ $^

libft: | $(LIB_DIR) $(INC_DIR) 
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE)  -C $(LIBFT_DIR) install \
		TARGET_LIB=$(CUR_DIR)/$(LIB_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(LIB_DIR):
	@mkdir $(LIB_DIR)

$(INC_DIR):
	@mkdir $(INC_DIR)

flags:
	@echo $(CFLAGS)

show:
	@echo $(SOURCES)

clean: 
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(LIB_DIR)/*

re: fclean all
