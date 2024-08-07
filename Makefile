#Directory definition
TARGET_LIB := ~/PROG/Libraries/libs
TARGET_INC := ~/PROG/Libraries/includes

#Filenames definition
NAME := libft.a

SRC_NAMES := ft_isalpha.c \
	     ft_isascii.c \
	     ft_isdigit.c \
	     ft_isalnum.c \
	     ft_isprint.c \
	     ft_memset.c \
	     ft_strlen.c \
	     ft_bzero.c \
	     ft_memcpy.c \
	     ft_memmove.c \
	     ft_strlcpy.c \
	     ft_strlcat.c \
	     ft_toupper.c \
	     ft_tolower.c \
	     ft_strchr.c \
	     ft_strrchr.c \
	     ft_strncmp.c \
	     ft_memchr.c \
	     ft_memcmp.c \
	     ft_strnstr.c \
	     ft_atoi.c \
	     ft_calloc.c \
	     ft_strdup.c \
	     ft_substr.c \
	     ft_strjoin.c \
	     ft_strtrim.c \
	     ft_split.c \
	     ft_itoa.c \
	     ft_strmapi.c \
	     ft_striteri.c \
	     ft_putchar_fd.c \
	     ft_putstr_fd.c \
	     ft_putendl_fd.c \
	     ft_putnbr_fd.c \
		 ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))
INC_NAMES := libft.h

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
INC_SOURCES := $(patsubst %.h, %.h, $(INC_NAMES))

CFLAGS += -Wall -Werror -Wextra
DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show install
all: $(OBJECTS) $(NAME)

install: $(INC_SOURCES) $(NAME)
	@echo "Copying " $< " in " $(TARGET_INC)
	cp $< $(TARGET_INC)/
	@echo "Copying " $(NAME) " in " $(TARGET_LIB)
	cp $(NAME) $(TARGET_LIB)/

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(INC_SOURCES) Makefile 
	cc $(CFLAGS) $(DEBUG) -c $< -o $@

%.h:
	@echo $@ "is missing!"

flags:
	@echo $(CFLAGS)

show:
	@echo $(T_NAME)
	@echo $(T_OBJ)

clean: 
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
