#Directory definition
LIBFT_DIR := libft

#Filenames definition
NAME := push_swap

SRC_NAMES := push_swap.c \
			 push_swap_list_utils.c \
			 push_swap_operations.c \
			 list_display.c \
			 algorithms.c \
			 radix.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

LIBFT_NAME := libft.a 
LIBFT_TAG := $(patsubst lib%.a, -l%, $(LIBFT_NAME)) 

DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft bonus
all: $(OBJECTS) $(NAME)

$(NAME): libft $(LIBFT_DIR)/libft.h Makefile $(OBJECTS) 
	@cc $(CFLAGS) -L $(LIBFT_DIR) $(DEBUG) $(SOURCES) -o $@ $(LIBFT_TAG)
	$(MAKE) clean
libft: 
	$(MAKE) -C $(LIBFT_DIR)

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
