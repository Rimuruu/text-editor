CXX = g++
LIB = -lncurses

# Source files
SSRCS = ./src/main.cpp ./src/files.cpp ./src/editor.cpp
LSRCS = ./src/linux_editor.cpp ./src/linux/screen_ncurses.cpp
SRCS  = $(SSRCS) $(LSRCS)

# Object files
OBJS  = $(SRCS:.cpp=.o)

# Headers
HEADERS = $(shell find ./src -name '*.h')
$(info $(HEADERS))
# Default target
all: linux

# Build target for Linux
linux: text-editor

# Linking
text-editor: $(OBJS)
	$(CXX) -o ./bin/text-editor $(OBJS) $(LIB)

# Compilation rule
%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) ./bin/text-editor