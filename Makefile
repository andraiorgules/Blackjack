CXX=g++

CFLAGS= -std=c++11 -O2 -Wall -Werror -Wextra

DEPS = util.h
OBJ = battleship.o util.o

%.o: %.cpp $(DEPS) 
	$(CXX) -c -o $@ $< $(CFLAGS)

blackjack: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm *.o && rm blackjack 

