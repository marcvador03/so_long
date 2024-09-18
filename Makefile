#Directory definition
TARGET_LIB ?= .
TARGET_INC ?= .

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

FT_PRINTF_NAMES := ft_printf.c \
				   ft_printf_char.c \
				   ft_printf_dec.c \
				   ft_printf_hexa.c \
				   ft_printf_string.c \
				   ft_printf_unsigned.c \
				   ft_printf_utils.c

GNL_NAMES := get_next_line.c \
			 get_next_line_utils.c 

INC_SOURCES := libft.h \
			   ft_printf/ft_printf.h \
			   getnextline/get_next_line.h

SOURCES := $(patsubst %.c, %.c, $(SRC_NAMES))
FT_PRINTF_SOURCES := $(patsubst %.c, ft_printf/%.c, $(FT_PRINTF_NAMES))
GNL_SOURCES := $(patsubst %.c, getnextline/%.c, $(GNL_NAMES))

OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
OBJECTS += $(patsubst %.c, %.o, $(FT_PRINTF_SOURCES))
OBJECTS += $(patsubst %.c, %.o, $(GNL_SOURCES))

CFLAGS += -Wall -Werror -Wextra
DEBUG ?=

CUR_DIR := $(shell pwd)

#TARGETS
.PHONY: all flags clean fclean re show install
all: $(OBJECTS) $(NAME)

install: $(INC_SOURCES) $(NAME) | $(TARGET_LIB) $(TARGET_INC)
	@echo "Copying " $< " in " $(TARGET_INC)
	@cp $< $(TARGET_INC)/
	@echo "Copying " $(NAME) " in " $(TARGET_LIB)
	@cp $(NAME) $(TARGET_LIB)/

$(NAME): $(OBJECTS) 
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@$(MAKE) clean

%.o: %.c libft.h Makefile 
	@cc $(CFLAGS) $(DEBUG) -c $< -o $@

%.h:
	@echo $@ "is missing!"

$(TARGET_LIB):
	mkdir $(TARGET_LIB)

$(TARGET_INC):
	mkdir $(TARGET_INC)

flags:
	@echo $(CFLAGS)

show:
	@echo $(T_NAME)
	@echo $(T_OBJ)

clean: 
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
