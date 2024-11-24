# Dossier de destination
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src


all: $(BIN_DIR)/test 


# Règles de compilation

$(OBJ_DIR)/Image.o: $(SRC_DIR)/Image.cpp $(SRC_DIR)/Image.h 
	g++ -c -g $(SRC_DIR)/Image.cpp -o $(OBJ_DIR)/Image.o

$(OBJ_DIR)/mainTest.o: $(SRC_DIR)/mainTest.cpp $(SRC_DIR)/Image.h
	g++ -c -g $(SRC_DIR)/mainTest.cpp -o $(OBJ_DIR)/mainTest.o

$(BIN_DIR)/test: $(OBJ_DIR)/mainTest.o $(OBJ_DIR)/Image.o
	g++ $(OBJ_DIR)/mainTest.o $(OBJ_DIR)/Image.o -o $(BIN_DIR)/test


clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/test