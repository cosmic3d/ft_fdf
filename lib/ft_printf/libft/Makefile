NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_strrchr.c ft_calloc.c ft_strnstr.c ft_memcmp.c ft_memchr.c ft_atoi.c ft_strncmp.c ft_strchr.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_strlcpy.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_memset.c ft_strlen.c ft_isprint.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c

SRCS2	= ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c $(SRCS)

OBJ		= $(SRCS:.c=.o)

OBJ2	= $(SRCS2:.c=.o) 

RM		= rm -rf

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar -crs $(NAME) $(OBJ)
bonus: $(OBJ2)
	ar -crs $(NAME) $(OBJ2)
	touch $@
clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME)
	$(RM) bonus
re: fclean all

.PHONY: all clean fclean re
