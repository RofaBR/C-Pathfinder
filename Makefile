CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBMX_DIR = libmx

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIBMX = $(LIBMX_DIR)/libmx.a
EXEC = pathfinder

all: $(LIBMX) $(EXEC)

$(LIBMX):
	$(MAKE) -C $(LIBMX_DIR) re  # Чистка и пересборка библиотеки

$(EXEC): $(OBJ_FILES) $(LIBMX)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBMX) -o $(EXEC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIBMX_DIR)/$(INC_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBMX_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -f $(EXEC)
.PHONY: clean