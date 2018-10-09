CC =g++ -O3 -m64 -fopenmp -std=c++11  -w


SOURCE =$(patsubst ./%.cpp, ./%.o, $(wildcard ./*.cpp))


RFLAGS = 
LOPENMP=
LFLAGS = -lm -lLHAPDF
LIB_FLAGS = -L/usr/local/lib
INC_FLAGS = -I/usr/local/include 



all: 	$(SOURCE)


%.o : %.cpp
	$(CC) $(INC_FLAGS) $(LFLAGS) -c $< -o $@

clean:
	rm	-rf *.out *.o 
