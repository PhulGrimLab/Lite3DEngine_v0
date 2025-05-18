CXX = g++
CXXFLAGS = -g -Wall
TARGET = hello.out
SRC = Hello.cpp HelloUtils.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
