.PHONY: all fclean re clean

NAME = fract_al
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)

MINILIB_DIR = minilibx/
LDFLAGS = -L$(MINILIB_DIR)
LDLIBS = -lm -L/usr/X11R6/lib -L minilibx -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MINILIB_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS) minilibx/libmlx.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re:fclean all
