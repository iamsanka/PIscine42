CC = gcc 
SRCS = main.c utils.c dict.c
OBJS = $(SRCS:.c=.o) 
NAME = rush-02 

all: $(NAME) 

$(NAME): $(OBJS) 
	$(CC) -Wall -Wextra -Werror $(SRCS) -o $(NAME)
	
clean: 
	rm -f $(OBJS) 

fclean: clean 
	rm -f $(NAME) 
	
re: fclean all 

.PHONY: all clean fclean re

