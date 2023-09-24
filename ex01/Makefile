NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

# CXXFLAGS +=-fsanitize=undefined

SRCS = main.cpp \
	Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)