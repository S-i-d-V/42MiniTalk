.SILENT:

#GENERAL
CC = clang
CCFLAGS = -Wall -Werror -Wextra
CD = cd
MV = mv
RM = rm -rf

#COLOR
RED =`tput setaf 1`
GREEN =`tput setaf 2`
CLEAR =`tput sgr0`

#PROJECT
NAME = minitalk.a
EXEC_CLIENT = client
EXEC_SERVER = server

#PROJECT FILES
SRCS =	error.c \
		server.c \
		client.c \
		utils.c
OBJS = $(SRCS:.c=.o)

#RULES
.c.o:
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)$(EXEC_CLIENT) & $(EXEC_SERVER) compiled with success.$(CLEAR)"
	@$(CC) server.c $(NAME) -o server
	@$(CC) client.c $(NAME) -o client
 
clean:
	@echo "$(RED)objects files removed.$(CLEAR)"
	$(RM) $(OBJS)

fclean:	clean
	@echo "$(RED)$(EXEC_CLIENT) & $(EXEC_SERVER) removed.$(CLEAR)"
	$(RM) $(NAME)
	$(RM) $(EXEC_CLIENT) $(EXEC_SERVER)

re : fclean all
