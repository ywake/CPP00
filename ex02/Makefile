#############
# Functions #
#############

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

#############
# Variables #
#############

NAME	:= a.out
CXX		:= c++
CXXFLAGS:= -g -std=c++98 -pedantic -Wall -Werror -Wextra

SRCS	:= Account.cpp tests.cpp
SRCDIRS	:= $(call uniq, $(dir $(SRCS)))

OBJDIR	:= build/
OBJDIRS	:= $(addprefix $(OBJDIR), $(SRCDIRS))
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.cpp=%.o))

DEPS	:= $(addprefix $(OBJDIR), $(SRCS:%.cpp=%.d))

DSTRCTR	:= ./destructor.c

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean: FORCE
	$(RM) $(OBJS) $(DEPS)

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
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
	@printf "$(END)"

-include $(DEPS)

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

FILE	:= 19920104_091532.log

$(FILE):
	curl -O https://projects.intra.42.fr/uploads/document/document/6787/19920104_091532.log

test: $(FILE) $(NAME)
	@cat $(FILE) | awk '{if (NR<52) print $$2}' > expect
	@./$(NAME) | awk '{if (NR<52) print $$2}' > out
	diff -y expect out
	@$(RM) expect out

# gTestFlag	:= -std=c++11 -DDEBUG -g -fsanitize=integer -fsanitize=address -Wno-writable-strings
# gTestDir	:= ../.google_test
# gVersion	:= release-1.11.0
# gTestVer	:= googletest-$(gVersion)
# gTest		:= $(gTestDir)/gtest $(gTestDir)/$(gTestVer)

# TEST_SRCS	:= $(filter-out main.cpp, $(SRCS))
# TEST_OBJS	:= $(addprefix $(OBJDIR), $(TEST_SRCS:%.cpp=%.o))
# TEST_CPP	:= $(shell find . -type f -name test_*.cpp)

# $(gTest):
# 	mkdir -p $(gTestDir)
# 	curl -OL https://github.com/google/googletest/archive/refs/tags/$(gVersion).tar.gz
# 	tar -xvzf $(gVersion).tar.gz $(gTestVer)
# 	$(RM) $(gVersion).tar.gz
# 	python $(gTestVer)/googletest/scripts/fuse_gtest_files.py $(gTestDir)
# 	mv $(gTestVer) $(gTestDir)

# tester: $(gTest) $(OBJDIRS) $(TEST_OBJS)
# 	$(CXX) $(gTestFlag) \
# 		$(TEST_OBJS) $(TEST_CPP) \
# 		$(gTestDir)/$(gTestVer)/googletest/src/gtest_main.cc \
# 		$(gTestDir)/gtest/gtest-all.cc \
# 		-I$(gTestDir) $(INCLUDE) $(LIBS) -lpthread -o tester

# test: tester
# 	./tester

# test_fclean:
# 	$(RM) -r tester tester.dSYM

# test_re: test_fclean test

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
