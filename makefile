CXX=g++
SRCS=./src/main.cpp ./src/files.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
all: text-editor

text-editor: $(OBJS)
	$(CXX)	-o ./bin/text-editor $(OBJS)

main.o : ./src/main.cpp ./src/files.h
files.o : ./src/files.cpp ./src/files.h
