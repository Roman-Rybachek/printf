NAME = libftprintf.a
PRINTF = ft_basefree.c ft_procent.c ft_printf.c ft_fwidth.c ft_faccuracy.c ft_ffind_len.c ft_ftype.c ft_chartype.c ft_format.c ft_strtype.c ft_inttype.c ft_hexlowtype.c ft_hexuptype.c ft_uinttype.c ft_pointertype.c
FLAGS = -c -Wall -Wextra -Werror
LIBFT_BUILD = cd libft && make && cd ..
LIBFT_fCLEAN = cd libft && make fclean && cd ..
LIBFT_FILES = libft/ft_itoa_hex_t.o libft/ft_itoa_l.o libft/ft_itoa_hex.o libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o libft/ft_memccpy.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o libft/ft_putstr_fd.o libft/ft_split.o libft/ft_strchr.o libft/ft_strdup.o libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o libft/ft_strmapi.o libft/ft_strncmp.o libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_strtrim.o libft/ft_substr.o libft/ft_tolower.o libft/ft_toupper.o libft/libft.h
LIBFTPRINTF_BUILD = ar rc $(NAME)
LIBFTPRINTF_INDEX = ranlib $(NAME)

PRINTF_OBJ = $(PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF_OBJ) $(LIBFT_FILES) libftprintf.h
	$(LIBFT_BUILD)
	$(LIBFTPRINTF_BUILD) $(PRINTF_OBJ) libftprintf.h $(LIBFT_FILES)
	$(LIBFTPRINTF_INDEX)

%.o: %.c
	@ gcc $(FLAGS) $< -o $@

clean:
	@ $(LIBFT_fCLEAN)
	@ rm -f *.o

fclean: clean
	@ rm -f libftprintf.a
	@ rm -f *.out

re: fclean all

l:
	make
	make clean
	gcc main_.c ft_strtype.c ft_basefree.c libftprintf.a -g
	valgrind --leak-check=full ./a.out

bonus:
