CXX = g++
CXXFLAGS = -ggdb -std=c++20 -Wall -Werror -Wfatal-errors -fsanitize=address -pedantic

GTESTFLAGS = -lgtest -lpthread -lgtest_main -pthread

all: gtests

gtests: gtest/student_gtests.cpp ladder.o
	$(CXX) $(CXXFLAGS) gtest/student_gtests.cpp ladder.o -o gtests $(GTESTFLAGS)

# main: src/main.cpp sorter.o
# 	$(CXX) $(CXXFLAGS) src/main.cpp sorter.o -o main

ladder.o: src/ladder.cpp src/ladder.h
	$(CXX) $(CXXFLAGS) -c src/ladder.cpp -o ladder.o

clean:
	/bin/rm -f /*.o gtests

# clean:
# 	rm -f gtests

# .PHONY: clean