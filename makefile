CC = g++
CFLAGS = -std=c++17 -Wall
LFLAGS = -I.

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Lista plików źródłowych
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Lista plików obiektowych
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
# Nazwa finalnej aplikacji
TARGET = $(BIN_DIR)/main

# Dodaj pliki źródłowe i pliki obiektowe związane z klasami ListaPracownikow i Pracownik
SRCS += $(wildcard $(SRC_DIR)/pracownik/*.cpp)
OBJS += $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/pracownik/*.cpp))

# Dodaj pliki źródłowe i pliki obiektowe związane z katalogiem data
SRCS += $(wildcard $(SRC_DIR)/data/*.cpp)
OBJS += $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/data/*.cpp))

# Dodaj pliki źródłowe i pliki obiektowe związane z katalogiem napis
SRCS += $(wildcard $(SRC_DIR)/napis/*.cpp)
OBJS += $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/napis/*.cpp))

# Dodaj pliki źródłowe i pliki obiektowe związane z katalogiem tester
SRCS += $(wildcard $(SRC_DIR)/tester/*.cpp)
OBJS += $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(SRC_DIR)/tester/*.cpp))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR) $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< $(LFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
