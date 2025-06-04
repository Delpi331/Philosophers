NAME = philo_bonus

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/init.c $(SRC_DIR)/philosopher.c \
       $(SRC_DIR)/monitor.c $(SRC_DIR)/actions.c $(SRC_DIR)/utils.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
LDFLAGS = -lpthread

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: re

.PHONY: all clean fclean re bonus