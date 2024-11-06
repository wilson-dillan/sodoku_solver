SRC_DIR = source
OBJ_DIR = object
CFLAGS  = -c -Wall -I.
SRCS = $(SRC_DIR)/board.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/solver.cpp
OBJS = $(OBJ_DIR)/board.o $(OBJ_DIR)/main.o $(OBJ_DIR)/solver.o
# Note: The above will soon get unwieldy.
# The wildcard and patsubt commands will come to your rescue.


all: $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Trace.o: $(DEPS)
