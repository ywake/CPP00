#############
# Functions #
#############

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

#############
# Variables #
#############

NAME	:= megaphone
CXX		:= c++
CXXFLAGS:= -g -Wall -Werror -Wextra -std=c++98

SRCS	:= megaphone.cpp
SRCDIRS	:= $(call uniq, $(dir $(SRCS)))

OBJDIR	:= objs/
OBJDIRS	:= $(addprefix $(OBJDIR), $(SRCDIRS))
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.cpp=%.o))

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

.PHONY: FORCE
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

test1: FORCE
	./$(NAME) "shhhhh... I think the students are asleep..."
	@[ "`./$(NAME) "shhhhh... I think the students are asleep..."`" \
			= "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." ] \
	|| exit 1 \
	&& printf "$(GREEN)OK\n$(END)";


test2: FORCE
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@[ "`./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."`" \
			= "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." ] \
	|| exit 1 \
	&& printf "$(GREEN)OK\n$(END)";

test3: FORCE
	./$(NAME)
	@[ "`./$(NAME)`" \
			= "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ] \
	|| exit 1 \
	&& printf "$(GREEN)OK\n$(END)";

test: all test1 test2 test3

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
