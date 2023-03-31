# variables

NAME = fdf

CC = cc

FLAGS = -g -O3 -Wall -Werror -Wextra

#dirs
SRCS_DIR = sources/
INCL_DIR = include/
BONU_DIR = bonus/
LIBS_DIR = libs/
LIBFT_DIR = $(LIBS_DIR)libft/
MLX_DIR = $(LIBS_DIR)minilibx-linux/

#libs
LIBFT_A = $(LIBFT_DIR)libft.a
LIBML_A = $(MLX_DIR)libmlx.a

LIBS = $(LIBFT_A) \
$(LIBML_A)

SOURCES_FILES = colors.c \
draw_edge.c \
draw_map.c \
draw_pixel.c \
errors.c \
event_keyboard.c \
event_window.c \
fdf.c \
file_memory.c \
frame.c \
main.c \
map.c \
map2.c \
matrix.c \
point.c \
point2.c \
point3.c \
projection.c \
utils.c \
window.c

SOURCES_FILES_BONUS = colors.c \
$(BONU_DIR)draw_edge_bonus.c \
$(BONU_DIR)draw_map_bonus.c \
$(BONU_DIR)draw_map_events_bonus.c \
$(BONU_DIR)draw_map_events2_bonus.c \
$(BONU_DIR)draw_map_events3_bonus.c \
$(BONU_DIR)draw_pixel_bonus.c \
errors.c \
$(BONU_DIR)event_keyboard_bonus.c \
$(BONU_DIR)event_mouse_bonus.c \
$(BONU_DIR)event_window_bonus.c \
$(BONU_DIR)fdf_bonus.c \
file_memory.c \
$(BONU_DIR)frame_bonus.c \
$(BONU_DIR)menu_bonus.c \
$(BONU_DIR)menu2_bonus.c \
$(BONU_DIR)main_bonus.c \
$(BONU_DIR)map_bonus.c \
$(BONU_DIR)map2_bonus.c \
$(BONU_DIR)matrix_bonus.c \
$(BONU_DIR)point_bonus.c \
$(BONU_DIR)point2_bonus.c \
$(BONU_DIR)point3_bonus.c \
$(BONU_DIR)projection_bonus.c \
utils.c \
$(BONU_DIR)window_bonus.c

SOURCES = $(addprefix $(SRCS_DIR), $(SOURCES_FILES))
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

SOURCES_BONUS = $(addprefix $(SRCS_DIR), $(SOURCES_FILES_BONUS))
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
DEPENDS_BONUS = $(SOURCES_BONUS:.c=.d)

# recipes

all : $(NAME)

$(NAME) : $(LIBS) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@ $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm

%.o : %.c
	$(CC) -MMD -c $< -o $@

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

$(LIBS) :
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	
clean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJECTS) 
	$(RM) $(DEPENDS)
	$(RM) $(OBJECTS_BONUS) 
	$(RM) $(DEPENDS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(LIBS) $(OBJECTS_BONUS)
	$(CC) $(FLAGS) $(OBJECTS_BONUS) -o $(NAME) $(LIBFT_A) $(LIBML_A) -lXext -lX11 -lm -DBONUS

.PHONY : all clean fclean re bonus
