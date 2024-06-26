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
	     ft_putnbr_fd.c

SRC_NAMES_BNS := ft_lst_new \
#		 ft_lstadd_front \
#		 ft_lstsize \
#		 ft_lstlast \
#		 ft_lst_addback \
#		 ft_lstdelone \
#		 ft_lstclear \
#		 ft_lstiter \
#		 ft_lstmap

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))
SOURCES_BNS := $(patsubst %_bonus.c, %_bonus.c, $(SRC_NAMES_BNS))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
OBJECTS_BNS := $(OBJECTS) $(patsubst %_bonus.c, %_bonus.o, $(SOURCES_BNS))

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean tclean re test show bonus
all: $(OBJECTS) $(NAME)

bonus: $(OBJECTS_BNS) $(NAME) 

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	rm -rf *.o

%.o: %.c  
	cc $(CFLAGS) -I . -c $< -o $@

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

