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
			 turk_sort.c \
			 cost_calculations.c

INC_NAMES := push_swap.h

SOURCES := $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES := $(patsubst %.h, $(INC_DIR)/%.h, $(INC_NAMES))

CFLAGS += -Wall -Werror -Wextra

LIB_NAMES := libft.a 
LIBS_TAG := $(patsubst lib%.a, -l%, $(LIB_NAMES)) 

DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft bonus
all: $(OBJECTS) $(NAME) 

$(NAME): Makefile $(INCLUDES) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE)  -C $(LIBFT_DIR) install \
		TARGET_LIB=$(CUR_DIR)/$(LIB_DIR)
	cc $(CFLAGS) -L $(LIB_DIR) $(DEBUG) $(OBJECTS) -o $@ $(LIBS_TAG) $(LIBS_TAG)

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
