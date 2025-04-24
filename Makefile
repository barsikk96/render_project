CC = gcc

CFLAGS = -Wall -Wextra -g -std=c11 -DDEBUG -I$(SRC_DIR) -I$(INCLUDE_DIR) -I$(MAIN_DESIGN_DIR)
LIBS = -lncurses

SRC_DIR = src
INCLUDE_DIR = include
MAIN_DESIGN_DIR = $(SRC_DIR)/main_design

OBJ = $(SRC_DIR)/main.o $(MAIN_DESIGN_DIR)/main_screen.o

BIN_DIR = build
TARGET = $(BIN_DIR)/console_render

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(MAIN_DESIGN_DIR)%.o: $(MAIN_DESIGN_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean $(TARGET)
