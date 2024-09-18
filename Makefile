#Directory definition
LIBFT_DIR := libft
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
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


SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))

OBJECTS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

LIBFT_NAME := libft.a 
LIBFT_TAG := $(patsubst lib%.a, -l%, $(LIBFT_NAME)) 

DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft bonus
all: $(OBJECTS) $(NAME)

$(NAME): libft $(LIBFT_DIR)/libft.h Makefile 
	cc $(CFLAGS) -L $(LIBFT_DIR) $(DEBUG) $(SOURCES) -o $@ $(LIBFT_TAG)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc $(CFLAGS) $(DEBUG) -c -o $@ $^

libft: 
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

flags:
	@echo $(CFLAGS)

show:
	@echo $(SOURCES)

clean: 
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
