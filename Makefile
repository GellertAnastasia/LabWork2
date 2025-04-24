PROJECT = labwork 
 
LIBPROJECT = $(SOURCES:.cpp=.a) 
 
CXX = g++ 
A = ar 
AFLAGS = rsv 
CCXFLAGS = -I. -std=c++17 -Werror -Wpedantic -Wall -g -fPIC 
LDXXFLAGS = $(CCXFLAGS) -L. -l:$(LIBPROJECT) 
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread 
 
DEPS = $(wildcard *.h) 
SOURCES = main.cpp
OBJ = $(SOURCES:.cpp=.o) 
 
TEST_SOURCES = test.cpp
TEST_OBJ = $(TEST_SOURCES:.cpp=.o) 
 
.PHONY: default all clean 
 
default: all 
 
%.o: %.cpp $(DEPS) 
	$(CXX) $(CCXFLAGS) -c -o $@ $< 
 
$(LIBPROJECT): $(OBJ) 
	$(A) $(AFLAGS) $@ $^ 
 
$(PROJECT): main.o $(LIBPROJECT) 
	$(CXX) -o $@ main.o $(LDXXFLAGS) 
 
$(TESTPROJECT): $(TEST_OBJ)
	$(CXX) -o $(TESTPROJECT) $(TEST_OBJ) $(LDGTESTFLAGS)
	
runtests: $(TESTPROJECT)
	./(TESTPROJECT)

test: $(LIBPROJECT) $(TEST_OBJ) 
	$(CXX) -o test-all $(TEST_OBJ) $(LDGTESTFLAGS) 
 
all: $(PROJECT) test 
 
clean: 
	rm -f *.o 
	rm -f $(PROJECT) 
	rm -f $(LIBPROJECT) 
	rm -f test-all
