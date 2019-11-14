# BOSS MODE #
CC = g++
CFLAGS = -std=c++11 -Wall -Wno-deprecated -O2
INCLUDE = -I./headers
TARGET = a.out
OBJECTS = out/Diccionario.o out/Producto.o out/Interprete.o out/TablaHash.o out/Par.o out/main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $(OBJECTS)

out/Par.o: src/Par.cpp headers/Par.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Par.cpp -o out/Par.o

out/TablaHash.o: src/TablaHash.cpp headers/TablaHash.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/TablaHash.cpp -o out/TablaHash.o

out/Diccionario.o: src/Diccionario.cpp headers/Diccionario.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Diccionario.cpp -o out/Diccionario.o

out/Producto.o: src/Producto.cpp headers/Producto.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Producto.cpp -o Producto.o

out/Interprete.o: src/Interprete.cpp headers/Interprete.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Interprete.cpp -o out/Interprete.o