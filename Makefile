
CC = g++
SOURCES = Bubble1.cpp Bubble2.cpp Insertion.cpp Merge.cpp Quick.cpp Selection.cpp dicionario.cpp heapsort.cpp main.cpp
FLAGS = -O3

all: $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) -o ordenacao.exe
