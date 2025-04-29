CC = gcc

CFLAGS = -Wall -Wextra -g -std=c11 -DDEBUG -I$(SRC_DIR) -I$(FIGURES_DIR) -I$(IO_DIR) -I$(MATRIX_DIR) -I$(TESTS_DIR) -fsanitize=address
LIBS = -lncurses

SRC_DIR = src
FIGURES_DIR = $(SRC_DIR)/figures
IO_DIR = $(SRC_DIR)/io
MATRIX_DIR = $(SRC_DIR)/matrix
TESTS_DIR = tests

OBJ = $(SRC_DIR)/main.o $(FIGURES_DIR)/figures.o $(IO_DIR)/main_screen.o $(MATRIX_DIR)/matrix.o 
TESTS_OBJ = $(TESTS_DIR)/tests.o $(FIGURES_DIR)/figures.o $(IO_DIR)/main_screen.o $(MATRIX_DIR)/matrix.o 

BIN_DIR = build
TARGET = $(BIN_DIR)/console_render
TESTS_TARGET = $(BIN_DIR)/tests_runner

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIBS)
$(TESTS_TARGET): $(TESTS_OBJ)
	$(CC) $(CFLAGS) $(TESTS_OBJ) -o $(TESTS_TARGET) $(LIBS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(FIGURES_DIR)%.o: $(FIGURES_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(IO_DIR)%.o: $(IO_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(MATRIX_DIR)%.o: $(MATRIX_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(TESTS_DIR)%.o: $(TESTS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TESTS_OBJ) $(TARGET) $(TESTS_TARGET)

rebuild: clean $(TARGET) $(TESTS_TARGET)
