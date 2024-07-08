#Directory definition

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
	     ft_putnbr_fd.c

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))
<<<<<<< HEAD

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
=======
SOURCES_BNS := ft_lstnew_bonus.c \
			   ft_lstadd_front_bonus.c \
			   ft_lstsize_bonus.c \
			   ft_lstlast_bonus.c \
			   ft_lstadd_back_bonus.c \
			   ft_lstdelone_bonus.c \
			   ft_lstclear_bonus.c \
			   ft_lstiter_bonus.c \
			   ft_lstmap_bonus.c

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
OBJECTS_BNS := $(patsubst %.c, %.o, $(SOURCES_BNS))
>>>>>>> bonus

CFLAGS += -Wall -Werror -Wextra

CUR_DIR := $(shell pwd)

#TARGETS
<<<<<<< HEAD
.PHONY: all flags clean fclean tclean re test show
all: $(OBJECTS) $(NAME)

=======
.PHONY: all flags clean fclean re show bonus
all: $(OBJECTS) $(NAME)

bonus: $(OBJECTS_BNS) $(NAME)
	ar rc $(NAME) $(OBJECTS_BNS)
	ranlib $(NAME)

>>>>>>> bonus
$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c libft.h Makefile 
	cc $(CFLAGS) -c $< -o $@

flags:
	@echo $(CFLAGS)

show:
	@echo $(T_NAME)
	@echo $(T_OBJ)

clean: 
	rm -rf $(OBJECTS) $(OBJECTS_BNS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
