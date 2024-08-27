target := bin/main
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

CC := g++
CFLAGS := -Wall 
LFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
BIN := bin
OBJ := obj
SRC := src

$(shell mkdir -p obj bin saves)

all: $(target) $(BIN) $(OBJ)

$(target): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN)/* $(OBJ)/*
