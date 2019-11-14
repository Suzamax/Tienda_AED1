# BOSS MODE #
CC = g++
CFLAGS = -std=c++11 -Wall -Wno-deprecated -O2
INCLUDE = -I./headers
TARGET = a.out
OBJECTS = Diccionario.o Producto.o Interprete.o TablaHash.o Par.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $(OBJECTS)

main.o: src/main.cpp
	$(CC) $(INCLUDE) $(CFLAGS) -c src/main.cpp -o main.o

TablaHash.o: src/TablaHash.cpp headers/TablaHash.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/TablaHash.cpp -o TablaHash.o

Diccionario.o: src/Diccionario.cpp headers/Diccionario.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Diccionario.cpp -o Diccionario.o

Producto.o: src/Producto.cpp headers/Producto.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Producto.cpp -o Producto.o

Interprete.o: src/Interprete.cpp headers/Interprete.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Interprete.cpp -o Interprete.o