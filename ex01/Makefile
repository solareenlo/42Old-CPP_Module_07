# Makefile for Old-CPP Module 07 ex01, updated Mon Nov 22 21:40:57 JST 2021

SRC := main.cpp
OBJ := main.o

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

NAME    := a.out

CC      := clang++
CFLAGS  := -Wall -Wextra -Werror -std=c++98 --pedantic
RM      := rm -fr

SRC_DIR := ./
OBJ_DIR := obj
SRCS    := $(addprefix $(SRC_DIR)/, $(SRC))
OBJS    := $(addprefix $(OBJ_DIR)/, $(OBJ))
HEADERS := $(shell find . -type f -name '*.hpp' -print)
CPPLINT_FILTERS := --filter=-runtime/references

.PHONY:	all
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: lint
lint:
	cpplint $(CPPLINT_FILTERS) $(SRC) $(HEADERS)

.PHONY: leak
leak: CFLAGS += -g -fsanitize=leak
leak: test

.PHONY: address
address: CFLAGS += -g -fsanitize=address
address: test

.PHONY: thread
thread: CFLAGS += -g -fsanitize=thread
thread: test

.PHONY: memory
memory: CFLAGS += -g -fsanitize=memory
memory: test

.PHONY: clean
clean:
	$(RM) Makefile.bak $(NAME).dSYM $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: valgrind
valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: test
test: re
	./$(NAME)

.PHONY: source
source:
	@mv Makefile Makefile.bak
	@echo "# Makefile for Old-CPP Module 07 ex01, updated `date`" >> Makefile
	@echo '' >> Makefile
	@echo SRC := `ls *.cpp` >> Makefile
	@echo OBJ := `ls *.cpp | sed s/cpp$$/o/` >> Makefile
	@echo '' >> Makefile
	@sed -n -e '/^# DO NOT ADD OR MODIFY/,$$p' < Makefile.bak >> Makefile
