NAME = pipex

CC = gcc -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRC = 		src/pipex.c		\
		src/pipex_utils.c	\
		libft/libft.a

SRC_B = 	src_b/pipex_bonus.c \
		src_b/pipex_utils_bonus.c \
		src_b/get_next_line_bonus.c \
		src_b/get_next_line_utils_bonus.c \
		src_b/here_docs.c	\
		libft/libft.a

$(NAME) :
	make -s all -C libft
	$(CC) $(SRC) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean:
	$(RM) $(NAME)
	$(RM) src/*.o
	$(RM) src_b/*.o
	make -s clean -C libft

re : fclean all

bonus : clean
	make -s all -C libft
	$(CC) $(SRC_B) -o $(NAME)
