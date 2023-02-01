NAMEC = client
NAMES = server

CFLAGS = -Wall -Wextra -Werror
INCLPATH = ./includes/
SRCPATH = ./srcs/
RM = rm -rf

CSRCS = $(addprefix $(SRCPATH), \
								client.c \
								utils.c)

SSRCS = $(addprefix $(SRCPATH), \
								server.c \
								utils.c )

all: $(NAMEC) $(NAMES)

$(NAMEC):
	cc -I $(INCLPATH) $(CSRCS) -o $@ $(CFLAGS)

$(NAMES):
	cc -I $(INCLPATH) $(SSRCS) -o $@ $(CFLAGS)

clean:
	$(RM) $(CSRCS:%.c=%.o)
	$(RM) $(SSRCS:%.c=%.o)

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)

re: fclean all

git: fclean
	git add .
	sleep 5
	git commit -m "Automatic commit from Makefile"
	git push

.PHONY: clean fclean re all