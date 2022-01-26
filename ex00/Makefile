#############
# Functions #
#############

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

#############
# Variables #
#############

NAME	:= megaphone
CXX		:= c++
INCLUDE	:= -I./includes
CXXFLAGS:= -g -Wall -Werror -Wextra -std=c++98 $(INCLUDE)

SRCS	:= megaphone.c
SRCDIRS	:= $(call uniq, $(dir $(SRCS)))

OBJDIR	:= objs/
OBJDIRS	:= $(addprefix $(OBJDIR), $(SRCDIRS))
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

DSTRCTR	:= ./tests/destructor.c

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean: FORCE
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM

re: fclean all

run: $(NAME)
	./$(NAME)

norm: FORCE
	@printf "$(RED)"; norminette | grep -v ": OK!" \
	&& exit 1 \
	|| printf "$(GREEN)%s\n$(END)" "Norm OK!"

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: %.cpp
	@printf "$(THIN)$(ITALIC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "$(END)"

FORCE:

###############
# Debug rules #
###############

$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

sani: $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

Darwin_leak: $(DSTRCTR) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak: sani

leak: $(shell uname)_leak

##############
# Test rules #
##############

test: all
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)

##########
# Colors #
##########

END		= \e[0m
BOLD	= \e[1m
THIN	= \e[2m
ITALIC	= \e[3m
U_LINE	= \e[4m
BLACK	= \e[30m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
PURPLE	= \e[35m
CYAN	= \e[36m
WHITE	= \e[37m
