NAME = fixed02

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp Fixed.cpp

TMP_DIR = tmp/

OBJS = $(addprefix $(TMP_DIR), $(SRCS:.cpp=.o))

DEPS = $(OBJS:.o=.d)

DFLAGS = -MMD -MP

all: $(TMP_DIR) $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

$(TMP_DIR)%.o:%.cpp Makefile
	c++ $(FLAGS) $(DFLAGS) -c $< -o $@

clean:
	rm -rf $(TMP_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re

-include $(DEPS)