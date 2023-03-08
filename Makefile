# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= fdf
MK			= Makefile

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
LIB_DIR	= lib/ft_libft/
LBX_DIR = lib/minilibx_macos/
PRINTF_DIR = lib/ft_printf/
#BONUS_DIR = 

# -=-=-=-=-	CMNDS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
CC			= gcc
SANS		= -fsanitize=address -g
CFLAGS		= -Wall -Werror -Wextra
LFLAGS		=  -L$(LBX_DIR) -lmlx -framework OpenGL -framework AppKit
AR			= ar -rcs
RM			= rm -f
MKDIR		= mkdir -p
CP			= cp -f

# -=-=-=-=-	LIBS/HEADERS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS		+= $(LIB_DIR)libft.a
LIBS		+= $(PRINTF_DIR)libftprintf.a
LIBS_HDRS	+= $(INC_DIR)fdf.h
LIBS_HDRS	+= $(LBX_DIR)mlx.h
INCLUDE		= -I $(LIBS_HDRS)

# -=-=-=-=-	SOURCES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #
SRCS		+= fdf.c

# -=-=-=-=-	OBJECTS/DEPENDENCIES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP			= $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MK)
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)Compiling: $<$(RESET)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) -c $< -o $@

# -=-=-=-=-	MAKING LIBS AND COMPILING WITH THEM -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: make_libs $(NAME)

make_libs:
	@$(MAKE) -sC $(LIB_DIR)
	@$(MAKE) -sC $(PRINTF_DIR)
	@$(MAKE) -sC $(LBX_DIR)

$(NAME): $(OBJS) $(LIBS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIBS) -o $(NAME)
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
