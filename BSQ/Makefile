CC = cc 
SRCS = bsq.c
OBJS = $(SRCS:.c=.o) 
NAME = bsq

all: $(NAME) 

$(NAME): $(OBJS) 
	$(CC) -Wall -Wextra -Werror $(SRCS) -o $(NAME)
	
clean: 
	rm -f $(OBJS) 

fclean: clean 
	rm -f $(NAME) 
	
re: fclean all 

.PHONY: all clean fclean re
