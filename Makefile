NAME = fdf

SRC =	src/main.c \
		src/add.c \
		src/help_parce.c \
		src/paint.c \
		src/ft_abs.c \
		src/button.c \
		src/add_2.c \
		src/help_main.c \
		src/help_paint.c \

OBJ =	main.o \
		add.o \
		help_parce.o \
		paint.o \
		ft_abs.o \
		button.o \
		add_2.o \
		help_main.o \
		help_paint.o \

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ): $(SRC) includes/fdf.h
	@gcc  -c $(SRC) 

$(NAME): $(OBJ) includes/fdf.h
	@make -C libft
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -L./libft -lft 
	@echo " \x1B[36m ----------------------\033[0m"
	@echo " \x1B[36m MAKE for FDF DONE \033[0m"
	@echo " \x1B[36m ----------------------\033[0m"

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
