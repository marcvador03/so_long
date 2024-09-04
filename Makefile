#Directory definition
LIBFT_DIR := libft
LIBMLX_DIR := minilibx
TARGET_LIB := ../lib
TARGET_INC := ../include

#Filenames definition
NAME := so_long

SRC_NAMES := so_long.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

LIBS_NAMES := libft.a \
			  libmlx.a
LIBS_TAG :=  -lXext \
			 -lX11 \
			 -lm \
			 -lz


LIBS_TAG += $(patsubst lib%.a, -l%, $(LIBS_NAMES)) 
DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft libmlx
all: $(OBJECTS) $(NAME)

$(NAME): libft libmlx Makefile $(OBJECTS) 
	cc  $(CFLAGS) -L $(LIBFT_DIR) -L $(LIBMLX_DIR) $(DEBUG) $(SOURCES) -o $@ $(LIBS_TAG) $(LIBS_TAGS)
#	$(MAKE) clean

%.o: %.c
	cc $(CFLAGS) $(DEBUG) -c -o $@ $^

libft:  
	$(MAKE) -C $(LIBFT_DIR)

libmlx:
	$(MAKE) -C $(LIBMLX_DIR)
#	cmake $(LIBMLX_DIR) -B $(TARGET_LIB)/libmlx && make -C $(TARGET_LIB) -j4 

flags:
	@echo $(CFLAGS)

show:
	@echo $(SOURCES)

clean: 
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE)  clean -C $(LIBMLX_DIR)
#	rm -rf $(TARGET_LIB)/libmlx

re: fclean all
