CC = gcc

CFLAGS = -Wall -Wextra -g -std=c11 -DDEBUG -I$(SRC_DIR) -I$(FIGURES_DIR) -I$(MAIN_DESIGN_DIR) -I$(MATRIX_DIR) -fsanitize=address
LIBS = -lncurses

SRC_DIR = src
FIGURES_DIR = $(SRC_DIR)/figures
MAIN_DESIGN_DIR = $(SRC_DIR)/main_design
MATRIX_DIR = $(SRC_DIR)/matrix

OBJ = $(SRC_DIR)/main.o $(FIGURES_DIR)/figures.o $(MAIN_DESIGN_DIR)/main_screen.o $(MATRIX_DIR)/matrix.o

BIN_DIR = build
TARGET = $(BIN_DIR)/console_render

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(FIGURES_DIR)%.o: $(FIGURES_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(MAIN_DESIGN_DIR)%.o: $(MAIN_DESIGN_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(MATRIX_DIR)%.o: $(MATRIX_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean $(TARGET)
