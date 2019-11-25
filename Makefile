# BOSS MODE #
CC = g++
CFLAGS = -std=c++11 -Wall -Wno-deprecated -O2
INCLUDE = -I./headers
TARGET = a.out
OBJECTS = Diccionario.o Producto.o Interprete.o Utilidades.o TablaHash.o Arbol.o Nodo.o main.o

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
	
Utilidades.o: src/Utilidades.cpp headers/Utilidades.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Utilidades.cpp -o Utilidades.o

Interprete.o: src/Interprete.cpp headers/Interprete.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Interprete.cpp -o Interprete.o

Arbol.o: src/Arbol.cpp headers/Arbol.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Arbol.cpp -o Arbol.o

Nodo.o: src/Nodo.cpp headers/Nodo.h
	$(CC) $(INCLUDE) $(CFLAGS) -c src/Nodo.cpp -o Nodo.o
