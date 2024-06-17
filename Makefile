#Directory definition

#Filenames definition
NAME := ft_lib.a

SRC_NAMES := ft_isalpha.c \
	     ft_isascii.c \
	     ft_isdigit.c \
	     ft_isprint.c \
	     ft_memset.c \
	     ft_strlen.c \
	     ft_bzero.c \
	     ft_memcpy.c \
	     ft_memmove.c \
	     ft_strlcpy.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean tclean re test show
all: $(OBJECTS) $(NAME)

%.o: %.c  
	cc $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

flags:
	@echo $(CFLAGS)
show:
	@echo $(T_NAME)
	@echo $(T_OBJ)

clean: 
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
