# Makefile for building 2048 game using ncurses and g++

CXX = g++
CXXFLAGS = -std=c++17 -O2 -lncurses

TARGET = 2048
SOURCES = main.cpp GameModel.cpp GameWidget.cpp GameController.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean