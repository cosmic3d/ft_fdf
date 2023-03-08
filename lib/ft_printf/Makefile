NAME		= libftprintf.a

CFLAGS		= -Wall -Werror -Wextra $(INCLUDE)
AR		= ar -rcs
RM		= rm -f
MKDIR	= mkdir -p
CP		= cp -f

SRC_DIR	= src/
OBJ_DIR	= obj/
INC_DIR	= inc/
LIB_DIR	= libft/

LIBS		= $(LIB_DIR)libft.a
LIBS_HDRS	= -I $(LIB_DIR)libft.h
INCLUDE		= -I $(INC_DIR) $(LIBS_HDRS)

SRCS		= ft_print_char.c ft_print_str.c ft_printf.c ft_print_int.c ft_print_hexlow.c ft_print_hexupp.c ft_print_ptr.c ft_print_unsigned.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP		= $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

all: make_libs $(NAME)

make_libs:
	make -sC $(LIB_DIR)

$(NAME): $(OBJS) $(LIBS)
	$(CP) $(LIBS) ./$(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	make clean -sC $(LIB_DIR)
	$(RM) -r $(OBJ_DIR)

fclean:	clean
	make fclean -sC $(LIB_DIR)
	$(RM) $(NAME)

re:	fclean	all

-include $(DEP)

.PHONY:	all clean fclean re make_libs
