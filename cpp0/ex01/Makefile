NAME = Phonebook
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Contact.cpp PhoneBook.cpp
RM = rm -f

GREEN=\033[32m
LGREEN=\033[1;92m
ORANGE=\033[33m
RED = \033[1;91m
NONE=\033[0m

OBJ = ${SRC:.cpp=.o}

all: $(NAME)

%.o: %.cpp Makefile
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
	@echo "$(GREEN)File $< compiled ✔$(NONE)"

$(NAME): $(OBJ) Makefile
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "\n$(LGREEN)Create $(NAME) ✔$(NONE)\n"

clean:
	@$(RM) -r $(OBJ)
	@echo "$(RED)Deleted .o files$(NONE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) Deleted$(NONE)"

re: fclean all

.PHONY: all clean fclean re