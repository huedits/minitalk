NAMEC = client
NAMES = server

CFLAGS = -Wall -Wextra -Werror
INCLPATH = ./includes/
SRCPATH = ./srcs/
PFPATH = ./ft_printf/libftprintf.a
RM = rm -rf

CSRCS = $(addprefix $(SRCPATH), \
								client.c \
								utils.c)

SSRCS = $(addprefix $(SRCPATH), \
								server.c \
								utils.c )

all: $(NAMEC) $(NAMES)

$(NAMEC): $(PFPATH)
	cc -I $(INCLPATH) $(CSRCS) $(PFPATH) -o $@ $(CFLAGS)

$(NAMES): $(PFPATH)
	cc -I $(INCLPATH) $(SSRCS) $(PFPATH) -o $@ $(CFLAGS)

$(PFPATH):
	$(MAKE) all -C ./ft_printf/

clean:
	$(RM) $(CSRCS:%.c=%.o)
	$(RM) $(SSRCS:%.c=%.o)
	$(MAKE) clean -C ./ft_printf/

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	$(MAKE) fclean -C ./ft_printf/

re: fclean all

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push

.PHONY: clean fclean re all