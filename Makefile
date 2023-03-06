NAMEC = client
NAMES = server
BNAMEC = client_bonus
BNAMES = server_bonus

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
BCSRCS = $(addprefix $(SRCPATH), \
	 							client_bonus.c \
								utils_bonus.c )
BSSRCS = $(addprefix $(SRCPATH), \
	 							server_bonus.c \
								utils_bonus.c )

all: $(NAMEC) $(NAMES)

bonus: $(BNAMEC) $(BNAMES) 

$(NAMEC): $(PFPATH)
	cc -I $(INCLPATH) $(CSRCS) $(PFPATH) -o $@ $(CFLAGS)

$(NAMES): $(PFPATH)
	cc -I $(INCLPATH) $(SSRCS) $(PFPATH) -o $@ $(CFLAGS)

$(BNAMEC): $(PFPATH)
	cc -I $(INCLPATH) $(BCSRCS) $(PFPATH) -o $@ $(CFLAGS)

$(BNAMES): $(PFPATH)
	cc -I $(INCLPATH) $(BSSRCS) $(PFPATH) -o $@ $(CFLAGS)

$(PFPATH):
	$(MAKE) all -C ./ft_printf/

clean:
	$(RM) $(CSRCS:%.c=%.o)
	$(RM) $(SSRCS:%.c=%.o)
	$(RM) $(BCSRCS:%.c=%.o)
	$(RM) $(BSSRCS:%.c=%.o)
	$(MAKE) clean -C ./ft_printf/

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	$(RM) $(BNAMEC)
	$(RM) $(BNAMES)
	$(MAKE) fclean -C ./ft_printf/

re: fclean all

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push

.PHONY: clean fclean re all bonus
