NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

CREATE_LIB = ar rsc

RM = rm -f

#mandarory part
SOURCES = ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

#bonus part
SOURCES_BONUS = ft_aux_bonus.c \
				ft_printf_bonus.c \
				ft_printers_bonus.c

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

#recipes

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CREATE_LIB) $(NAME) $(OBJECTS)

$(OBJECTS) : 
	$(CC) $(FLAGS) -c $(SOURCES)

clean :
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

#recipes bonus

bonus : $(OBJECTS_BONUS)

$(OBJECTS_BONUS) :
	$(CC) $(FLAGS) -c $(@:.o=.c)
	$(CREATE_LIB) $(NAME) $@	

.PHONY : clean fclean re bonus
