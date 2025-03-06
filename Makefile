PROJECT = labwork

CXX = g++
A = ar
AFLAGS = rsv
CCXFLAGS = -Iinclude -std=c++17 -Werror -Wpedantic -Wall -g -fPIC
LDXXFLAGS = $(CCXFLAGS) -L. 
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

SRC_DIR = src/
INC_DIR = include/
TEST_DIR = tests/

SOURCES = $(shell find $(SRC_DIR) -name '*.cpp') 

OBJ = $(SOURCES:.cpp=.o)

TEST_SOURCES = $(TEST_DIR)tests.cpp
TEST_OBJ = $(TEST_SOURCES:.cpp=.o)

.PHONY: default all clean

default: all

%.o: %.cpp
	$(CXX) $(CCXFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDXXFLAGS)

$(TESTPROJECT): $(TEST_OBJ)
	$(CXX) -o $(TESTPROJECT) $(TEST_OBJ) $(LDGTESTFLAGS)

runtests: $(TESTPROJECT)
	./$(TESTPROJECT)

test: $(LIBPROJECT) $(TEST_OBJ)
	$(CXX) -o test-all $(TEST_OBJ) $(LDGTESTFLAGS)

all: $(PROJECT) test

clean:
	find $(SRC_DIR) -name "*.o" -delete
	rm -f $(TEST_DIR)*.o
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f test-all
