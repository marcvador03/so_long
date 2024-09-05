#Directory definition
LIBFT_DIR := libft
LIBMLX_DIR := MLX42
TARGET_LIB := lib
TARGET_INC := ../include

#Filenames definition
NAME := so_long

SRC_NAMES := so_long.c \
			 colors.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

LIBS_NAMES := libft.a \
			  libmlx42.a
LIBS_TAG :=  -ldl \
			 -lglfw \
			 -pthread \
			 -lm


LIBS_TAG += $(patsubst lib%.a, -l%, $(LIBS_NAMES)) 
DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show libft libmlx
all: $(OBJECTS) $(NAME)

$(NAME): libft libmlx Makefile $(OBJECTS) 
	cc  $(CFLAGS) -L $(TARGET_LIB) $(DEBUG) $(SOURCES) -o $@ $(LIBS_TAG) $(LIBS_TAG)
#	$(MAKE) clean

%.o: %.c
	cc $(CFLAGS) $(DEBUG) -c -o $@ $^

libft:  
	$(MAKE) -C $(LIBFT_DIR)
	cp -u $(LIBFT_DIR)/libft.a $(TARGET_LIB)

libmlx:
	cmake -DDEBUG=1 -S $(LIBMLX_DIR) -B $(TARGET_LIB)
	$(MAKE) -C $(TARGET_LIB) -j4
#	cmake $(LIBMLX_DIR) -B $(TARGET_LIB)/libmlx && make -C $(TARGET_LIB) -j4 

flags:
	@echo $(CFLAGS)

show:
	@echo $(SOURCES)

clean: 
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(TARGET_LIB)
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
#	rm -rf $(TARGET_LIB)/libmlx

re: fclean all
