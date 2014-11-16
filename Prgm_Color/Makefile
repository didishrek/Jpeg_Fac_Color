NAME	=	ColorJpeg

SRC	=	main.c		\
		jpeg_read.c	\
		jpeg_write.c	\
		transform.c	\
		utils.c

CC	=	clang -o

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rvf

CFLAGS	+=	-W -Wall -Wextra

LFLAGS	+=	-I. -ljpeg

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

test:	re
	./$(NAME) ../image.jpg ../image2.jpg

.PHONY:	clean fclean all re
