NAME = pipex

CC = cc

FLAGS = -Wall -Werror -Wextra

# folders
SOURCES_DIR = sources/
OBJECTS_DIR = build/
LIBFT_DIR = libs/libft/
BONUS_DIR = $(SOURCES_DIR)bonus/

SOURCES_FILES = main.c\
				argv.c\
				dupz.c\
				errors.c\
				path.c\
				pipex.c\
				process.c\
				utils.c

OBJECTS_FILES = $(SOURCES_FILES:.c=.o)
DEPENDS_FILES = $(SOURCES_FILES:.c=.d)

SOURCES_FILES_BONUS = $(BONUS_DIR)main_bonus.c\
$(SOURCES_DIR)argv.c\
$(SOURCES_DIR)dupz.c\
$(SOURCES_DIR)errors.c\
$(SOURCES_DIR)path.c\
$(SOURCES_DIR)pipex.c\
$(SOURCES_DIR)process.c\
$(SOURCES_DIR)utils.c\
$(BONUS_DIR)heredoc_bonus.c

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_FILES))
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

OBJECTS_BONUS = $(SOURCES_FILES_BONUS:.c=.o)
DEPENDS_BONUS = $(SOURCES_FILES_BONUS:.c=.d)

LIBFT_A = $(LIBFT_DIR)libft.a

all : $(NAME)

$(NAME) : $(LIBFT_A) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT_A) -o $@

%.o : %.c
	$(CC) -MMD -c $< -o $@

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

clean :
	rm -rf $(OBJECTS)
	rm -rf $(DEPENDS)
	rm -rf $(OBJECTS_BONUS)
	rm -rf $(DEPENDS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re : fclean all

$(LIBFT_A) :
	make -C $(LIBFT_DIR)

bonus : $(LIBFT_A) $(OBJECTS_BONUS)
	$(CC) $(FLAGS) $(OBJECTS_BONUS) $(LIBFT_A) -o $(NAME)

.PHONY: clean fclean re bonus
