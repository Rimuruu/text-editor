CXX=g++
SRCS=./src/main.cpp ./src/files.cpp ./src/screen.cpp ./src/editor.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
LIB=-lncurses
all: text-editor

text-editor: $(OBJS)
	$(CXX)	-o ./bin/text-editor $(OBJS) $(LIB)

main.o : ./src/main.cpp ./src/editor.h
files.o : ./src/files.cpp ./src/files.h
screen.o : ./src/screen.cpp ./src/files.h ./src/screen.h
editor.o :  ./src/files.h ./src/screen.h

clean :
	rm -f ./src/*.o && rm -f ./bin/text-editor
