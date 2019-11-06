# BOSS MODE #
CC = g++
CFLAGS = -std=c++11 -Wall -Wno-deprecated -O2
TARGET = a.out
OBJECTS = Diccionario.o Producto.o Interprete.o TablaHash.o Par.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS)

Par.o: Par.cpp Par.h
	$(CC) $(CFLAGS) -c Par.cpp

TablaHash.o: TablaHash.cpp TablaHash.h
	$(CC) $(CFLAGS) -c TablaHash.cpp

Diccionario.o: Diccionario.cpp Diccionario.h
	$(CC) $(CFLAGS) -c Diccionario.cpp

Producto.o: Producto.cpp Producto.h
	$(CC) $(CFLAGS) -c Producto.cpp

Interprete.o: Interprete.cpp Interprete.h
	$(CC) $(CFLAGS) -c Interprete.cpp