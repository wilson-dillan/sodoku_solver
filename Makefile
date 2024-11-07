SRC_DIR = source
INC_DIR = include
OBJ_DIR = object
CFLAGS  = -c -Wall -I. -I$(INC_DIR)
LDFLAGS = -o
CC = g++
EXECUTABLE = my_program

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))


all: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)
run: $(EXECUTABLE)
	./$(EXECUTABLE)
