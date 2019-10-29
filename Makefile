# BOSS MODE #
CC = g++
CFLAGS = -std=c++11 -Wall -Wno-deprecated -O2
TARGET = a.out
OBJECTS = Diccionario.o Producto.o Interprete.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS)

Diccionario.o: Diccionario.cpp Diccionario.h
	$(CC) $(CFLAGS) -c Diccionario.cpp

Producto.o: Producto.cpp Producto.h
	$(CC) $(CFLAGS) -c Producto.cpp

Interprete.o: Interprete.cpp Interprete.h
	$(CC) $(CFLAGS) -c Interprete.cpp