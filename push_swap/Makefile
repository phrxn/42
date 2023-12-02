NAME = push_swap
NAME_BONUS = checker

CC = cc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

#dirs
SOURCES_DIR = sources/
BONUS_DIR = bonus/

#source
SOURCES_FILES =	plumbing/stack.c\
				plumbing/stack_manipulation.c\
				check_parameters.c\
				convert.c\
				ft_string.c\
				instruction_apply.c\
				instruction_calc.c\
				instruction_calc2.c\
				instruction_commons.c\
				instruction_compress.c\
				instruction_create.c\
				instruction_list.c\
				instruction_print.c\
				instruction_sort.c\
				main.c\
				stack_utils.c

SOURCES_FILES_BONUS =	plumbing/stack.c\
						plumbing/stack_manipulation.c\
						check_parameters.c\
						convert.c\
						ft_string.c\
						instruction_apply.c\
						instruction_commons.c\
						instruction_compress.c\
						stack_utils.c\
						$(BONUS_DIR)main.c\
						$(BONUS_DIR)checker.c\
						$(BONUS_DIR)ft_memcmp.c\
						$(BONUS_DIR)get_next_line.c

# recipes

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_FILES))
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

SOURCES_BONUS = $(addprefix $(SOURCES_DIR), $(SOURCES_FILES_BONUS))
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
DEPENDS_BONUS = $(SOURCES_BONUS:.c=.d)

all : $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -g $(FLAGS) $(OBJECTS) -o $@ 

%.o : %.c
	$(CC) -MMD -c $< -o $@ -DBUFFER_SIZE=512

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(DEPENDS)
	$(RM) $(OBJECTS_BONUS)
	$(RM) $(DEPENDS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

bonus: $(OBJECTS_BONUS)
	$(CC) $(FLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS) 

.PHONY: all clean fclean re bonus
