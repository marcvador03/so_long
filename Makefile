#Directory definition
LIBFT_DIR := libft

#Filenames definition
NAME := so_long

SRC_NAMES := so_long.c \
			 so_long_utils.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

LIBS_NAMES := libft.a \
			  libmlx42.a

LIBS_TAG := $(patsubst lib%.a, -l%, $(LIBS_NAMES)) 
LIBS_TAG +=  -ldl \
			 -lglfw \
			 -pthread \
			 -lm
DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft bonus
all: $(OBJECTS) $(NAME)

$(NAME): libft $(LIBFT_DIR)/libft.h Makefile $(OBJECTS) 
	cc $(CFLAGS) -L $(LIBFT_DIR) $(DEBUG) $(SOURCES) -o $@ $(LIBS_TAG)
#	$(MAKE) clean
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
