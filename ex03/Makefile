# --- Couleurs ---
GREEN       = \033[1;32m
RED         = \033[1;31m
BLUE        = \033[1;34m
YELLOW      = \033[1;33m
RESET       = \033[0m
#---------------------

NAME = intern
CFLAGS = c++ -Wall -Wextra -Werror -std=c++98 -Iinclude

OBJ_DIR = objs/
SRC_DIR = src/

SRC_FILES = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJS)
			@printf "$(GREEN)[EX03] Linking...$(RESET)\n"
			@$(CFLAGS) $(OBJS) -o $(NAME)
			@printf "$(GREEN)[EX03] $(NAME) compilation success!$(RESET)\n\n"
			$(HEADER)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
			@mkdir -p $(OBJ_DIR)
			@printf "$(YELLOW)[EX03] Compiling : $< $(RESET)\n"
			@$(CFLAGS) -c $< -o $@

clean :
			@rm -rf $(OBJ_DIR)
			@printf "$(RED)[EX03] Object files cleaned!$(RESET)\n"

fclean : clean
			@rm -f $(NAME)
			@rm *_shrubbery
			@printf "$(RED)[EX03] Executable $(NAME) cleaned.$(RESET)\n"

re  : fclean all

			
.PHONY : fclean re clean
