# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= fdf
MK			= Makefile
OS = $(shell uname -s)

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RESET		:= \033[0;39m
BLACK		:= \033[0;30m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
GRAY		:= \033[0;90m
WHITE		:= \033[0;97m

# -=-=-=-=-	DIRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
SRC_DIR	= src/
OBJ_DIR	= obj/
INC_DIR	= hdrs/
LIBS_DIR = lib/
X11_FLAGS = -lXext -lX11
FRAMEWORK_FLAGS = -framework OpenGL -framework Appkit


# -=-=-=-=-	CMNDS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
CC			= gcc
SANS		= -fsanitize=address -g
CFLAGS		= -Wall -Werror -Wextra -D BUFFER_SIZE=42 -O3
AR			= ar -rcs
RM			= rm -f
MKDIR		= mkdir -p
CP			= cp -f

# -=-=-=-=-	LIBS/HEADERS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

# Libraries

ifeq ($(OS),Linux)
	LBX_DIR = $(LIBS_DIR)minilibx_linux/
else ifeq ($(OS),Darwin)
	LBX_DIR = $(LIBS_DIR)minilibx_macos/
endif

# imprimimos mlx_dir para ver
$(info $(MLX_DIR))

LFLAGS =

ifeq ($(OS),Linux)
	LFLAGS = -L$(LBX_DIR) -lmlx $(X11_FLAGS) -lm
else ifeq ($(OS),Darwin)
	LFLAGS = -L$(LBX_DIR) -lmlx $(FRAMEWORK_FLAGS) -lm
endif

LIB_DIR	= $(LIBS_DIR)ft_libft/
LIBFT_LIB = libft.a
LIBS += $(LIB_DIR)$(LIBFT_LIB)

PRINTF_DIR = $(LIBS_DIR)ft_printf/
PRINTF_LIB = libftprintf.a
LIBS += $(PRINTF_DIR)$(PRINTF_LIB)

MLX_LIB = libmlx.a
LIBS += $(LBX_DIR)$(MLX_LIB)



INCLUDE		= -I $(LBX_DIR) -I $(PRINTF_DIR) -I $(LIB_DIR) -I $(INC_DIR)

# -=-=-=-=-	SOURCES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
SRCS		+= fdf.c utils_check.c free.c \
get_next_line.c get_next_line_utils.c pixels.c \
utils_check2.c int_check.c parse.c load.c \
draw_utils.c angles.c draw.c geometry.c hooks.c \
geometry_utils.c cohenshuterland.c mouse.c menu.c matrix.c


# -=-=-=-=-	OBJECTS/DEPENDENCIES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP			= $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MK)
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

# -=-=-=-=-	MAKING LIBS AND COMPILING WITH THEM -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: make_libs $(NAME)

make_libs:
	@$(MAKE) -sC $(LBX_DIR)
	@$(MAKE) -sC $(LIB_DIR)
	@$(MAKE) -sC $(PRINTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) -o $(NAME) -lm
	@echo "$(GREEN)🧩FDF COMPILED🧩$(RESET)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)
	@make clean -sC $(PRINTF_DIR)
	@make clean -sC $(LBX_DIR)
	@echo "$(CYAN)Dependencies and objects removed$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -sC $(LIB_DIR)
	@make fclean -sC $(PRINTF_DIR)
	@echo "$(RED)$(NAME) Removed$(RESET)"

re:	fclean	all

-include $(DEP)

.PHONY:	all clean fclean re make_libs bonus
