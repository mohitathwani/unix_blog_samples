CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS =

all: sample1 sample2 sample3 sample4

sample1: sample1.cpp
	$(CXX) $(CXXFLAGS) sample1.cpp -o sample1

sample2: sample2.cpp
	$(CXX) $(CXXFLAGS) sample2.cpp -o sample2

sample3: sample3.cpp
	$(CXX) $(CXXFLAGS) sample3.cpp -o sample3

sample4: sample4.cpp
	$(CXX) $(CXXFLAGS) sample4.cpp -o sample4

clean:
	rm -f sample1 sample2 sample3 sample4
