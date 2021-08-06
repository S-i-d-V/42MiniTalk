.SILENT:

#GENERAL
GCC = gcc
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
	@$(GCC)$(CCFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) compiled with success.$(CLEAR)"
	@$(GCC)$(CCFLAG) client.c -o $(EXEC_CLIENT) $(NAME)
	@$(GCC)$(CCFLAG) server.c -o $(EXEC_SERVER) $(NAME)
	@echo "$(GREEN)$(EXEC_CLIENT) & $(EXEC_SERVER) compiled with success.$(CLEAR)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)objects files removed.$(CLEAR)"

fclean: clean
	@$(RM) $(NAME) $(EXEC_CLIENT) $(EXEC_SERVER)
	@echo "$(RED)$(EXEC_CLIENT) & $(EXEC_SERVER) removed.$(CLEAR)"

re: fclean all