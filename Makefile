# Dossier de destination
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src


all: $(BIN_DIR)/test $(BIN_DIR)/main


# Règles de compilation

$(OBJ_DIR)/Image.o: $(SRC_DIR)/Image.cpp $(SRC_DIR)/Image.h 
	g++ -c -g $(SRC_DIR)/Image.cpp -o $(OBJ_DIR)/Image.o

$(OBJ_DIR)/MainTest.o: $(SRC_DIR)/MainTest.cpp $(SRC_DIR)/Image.h
	g++ -c -g $(SRC_DIR)/MainTest.cpp -o $(OBJ_DIR)/MainTest.o

$(BIN_DIR)/test: $(OBJ_DIR)/MainTest.o $(OBJ_DIR)/Image.o
	g++ $(OBJ_DIR)/MainTest.o $(OBJ_DIR)/Image.o -o $(BIN_DIR)/test

$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/menu.h 
	g++ -c -g $(SRC_DIR)/menu.cpp -o $(OBJ_DIR)/menu.o

$(OBJ_DIR)/Main.o: $(SRC_DIR)/Main.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/menu.h
	g++ -c -g $(SRC_DIR)/Main.cpp -o $(OBJ_DIR)/Main.o


$(BIN_DIR)/main: $(OBJ_DIR)/Main.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/menu.o
	g++ $(OBJ_DIR)/Main.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/menu.o -o $(BIN_DIR)/main

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/test $(BIN_DIR)/main