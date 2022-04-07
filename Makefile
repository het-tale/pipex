# _*_ MakeFile _*_

FLAGS 	= -Wall -Wextra -Werror

SRCS 	= ft_split.c ft_strjoin.c ft_strlen.c ft_substr.c path.c pipex.c ft_strchr.c ft_strncmp.c ft_strtrim.c ft_strdup.c exec.c
 
NAME 	= pipex
OBJS 	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):
	cc $(FLAGS) $(SRCS) -o $(NAME)
clean : 
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME) 

re : fclean all
