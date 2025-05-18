CXX=g++
SRCS=./src/main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
all: text-editor

text-editor: $(OBJS)
	$(CXX)	-o ./bin/text-editor $(OBJS)

main.o : ./src/main.cpp
