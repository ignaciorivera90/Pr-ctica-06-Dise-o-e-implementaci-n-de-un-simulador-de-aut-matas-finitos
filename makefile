CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRCS = 
OUTPUT = p06_automata_simulator

all: $(OUTPUT)

$(OUTPUT): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OUTPUT)