NAME = libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

CREATE_LIB = ar rsc

RM = rm -f

#madatory part
SOURCES = ft_isalpha.c \
  ft_isdigit.c \
  ft_isalnum.c \
  ft_isascii.c \
  ft_isprint.c \
  ft_strlen.c \
  ft_memset.c \
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

OBJECTS = $(SOURCES:.c=.o)

#bonus part
BONUS_SOURCES = ft_lstnew.c \
       ft_lstadd_front.c \
       ft_lstsize.c \
       ft_lstlast.c \
       ft_lstadd_back.c \
       ft_lstdelone.c \
       ft_lstclear.c \
       ft_lstiter.c \
       ft_lstmap.c

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

#recipes

all : $(NAME) 

$(NAME) : $(OBJECTS)
	$(CREATE_LIB) $(NAME) $(OBJECTS)

$(OBJECTS) :
	$(CC) $(FLAGS) -c $(SOURCES) 

clean :
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(BONUS_OBJECTS) 

$(BONUS_OBJECTS) : 
	$(CC) $(FLAGS) -c $(@:.o=.c)
	$(CREATE_LIB) $(NAME) $@

.PHONY : clean fclean re bonus 
