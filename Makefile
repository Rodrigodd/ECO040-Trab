
CC = g++
SOURCES = Bubble1.cpp Bubble2.cpp Insertion.cpp Merge.cpp Quick.cpp Selection.cpp dicionario.cpp heapsort.cpp main.cpp
CFLAGS = -O3

OBJECTS=$(addprefix obj/,$(patsubst %.cpp, %.o, $(SOURCES)))

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o ordenacao.exe

$(OBJECTS): obj/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

