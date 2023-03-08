NAME    = tutorial#
SRCS_PATH	= src#												# the path to your sources without ending /
INCS_PATH	= include#											# the path to your headers without ending /
BIN_PATH  	=	bin#											# path to bin for the binary files without ending /
INC     = /usr/local/include#									# could be /usr/include depending on your OS
LIBMLX  = /usr/local/lib#										# could be /usr/lib or minilibx_opengl_20191021/, depends on where you decided to put your mlx library 
UNAME   := $(shell uname)#										# UNAME will get the OS name, this will help define behaviors for certain OS's
CFLAGS  = -Wall -Werror -Wextra -O3 -g -I$(INC) -I$(INCS_PATH)#	# C Flags (gcc) & linking. "-Iinclude" if you created the folder "include" to put your project headers"
LFLAGS  = -L$(LIBMLX) -lmlx#									# if you decided to install libmlx.a locally you don't need "-L$(LIBMLX) -lmlx" the school also has it locally as well...
SRC     = $(wildcard $(SRCS_PATH)/*.c)#							# list your source files
OBJ     = $(SRC:$(SRCS_PATH)%.c=$(SRCS_PATH)%.o)#							# convert source files to binary list
BIN_OBJ	= $(SRC:$(SRCS_PATH)%.c=$(BIN_PATH)%.o)#							# convert source files to binary list
OUTPUT_LEAKS = valgrind-out.txt

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC = clang
else #Linux and others...
	CC = gcc
	LFLAGS += -lbsd -lXext -lX11 -lm
	CFLAGS += -D LINUX -fsanitize=leak
endif

all: $(NAME)

$(NAME): $(OBJ)
	@mv $(OBJ) $(BIN_PATH)
	$(CC) $(BIN_OBJ) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(BIN_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(OUTPUT_LEAKS)

re: fclean all

test: all
	./$(NAME)

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(OUTPUT_LEAKS) ./$(NAME)
	@cat valgrind-out.txt

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"

PHONY: show fclean clean all
