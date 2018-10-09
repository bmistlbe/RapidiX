CC =g++ -O3 -m64 -std=c++11  -w


SOURCE =$(patsubst ./%.cpp, ./%.o, $(wildcard ./*.cpp))



all: 	$(SOURCE)


%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	rm	-rf *.out *.o 
