#Directory definition
LIBFT_DIR := libft
LIBMLX_DIR := MLX42
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib

#Filenames definition
NAME := so_long

SRC_NAMES := so_long.c \
			 maps.c \
			 movements.c \
			 textures.c \
			 animations.c \
			 sprites.c \
			 sprites_utils.c \
			 utils.c \
			 checks.c \
			 actions.c \
			 loading.c \
			 path.c \
			 physics.c


INC_NAMES := so_long.h \
			 animations.h \
			 textures.h \
			 errors.h

SOURCES := $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC_NAMES))

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES := $(patsubst %.h, $(INC_DIR)/%.h, $(INC_NAMES))

DEPS := $(OBJECTS:.o=.d)

CFLAGS += -Wall -Werror -Wextra -MMD -MP

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
all: libft libmlx $(OBJECTS) $(NAME) 

$(NAME): libft/libft.a Makefile $(INCLUDES) $(OBJECTS)
#	cmake -DDEBUG=1 -S $(LIBMLX_DIR) -B $(CUR_DIR)/$(LIB_DIR)
#	$(MAKE) -C $(CUR_DIR)/$(LIB_DIR) -j4
	cc $(CFLAGS) -L $(LIB_DIR) -L libft $(DEBUG) $(OBJECTS) -o $@ $(LIBS_TAG) $(LIBS_TAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) $(DEBUG) -c $< -o $@ 

libft: | $(LIB_DIR) $(INC_DIR) 
	@$(MAKE) -C $(LIBFT_DIR)

libmlx: | $(LIB_DIR) $(INC_DIR)
	cmake -DDEBUG=1 -S $(LIBMLX_DIR) -B $(CUR_DIR)/$(LIB_DIR)
	$(MAKE) -C $(CUR_DIR)/$(LIB_DIR) -j4

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
	$(MAKE) clean -C $(CUR_DIR)/$(LIB_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(LIB_DIR)/*

re: fclean all
ifneq ($(DEPS), )
-include $(DEPS)
endif
.PHONY: all flags clean fclean re show libft bonus
