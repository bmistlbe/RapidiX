CC =g++ -m64 -fopenmp -O3 -std=c++11 -w


XS_FILES =$(patsubst ./XS/%.cpp, ./XS/%.o, $(wildcard ./XS/*.cpp))


SOURCE= $(patsubst ./src/%.cpp, ./src/%.o, $(wildcard ./src/*.cpp))
SSSOURCE2= $(patsubst ./FalkoRegularNNLO/%.cpp, ./FalkoRegularNNLO/%.o, $(wildcard ./FalkoRegularNNLO/*.cpp))
GS=$(patsubst ./Gs/%.cpp, ./Gs/%.o, $(wildcard ./Gs/*.cpp))

XSFILES= $(XS_FILES) 



RFLAGS = 
LOPENMP= -fopenmp -lchaplin
LFLAGS = -lm -lLHAPDF -lcuba
LIB_FLAGS = -L/usr/local/lib
INC_FLAGS = -I/usr/local/include


%.out : %.o
	$(MAKE) -C ./src/
	$(MAKE) -C ./FalkoRegularNNLO/
	$(MAKE) -C ./XS/
	$(MAKE) -C ./Gs/
#	$(CC) $(SOURCE) $(XSFILES) $<  -o $@ $(INC_FLAGS) $(LIB_FLAGS) $(LFLAGS) $(LOPENMP)
	$(CC) $(SOURCE) $(SSSOURCE2) $(GS) $(XSFILES) $<  -o $@ $(INC_FLAGS) $(LIB_FLAGS) $(LFLAGS) $(LOPENMP)

%.o : %.cpp
	$(CC) $(INC_FLAGS) $(LOPENMP) -c $< -o $@

%.s : src/%.cpp
	$(CC) $(INC_FLAGS) $(LOPENMP) -c $< -o $@.o
    

clean:
	rm	-rf *.out *.o *.dSYM ./src/*.o ./XS/*.o

cleansrc:
	rm 	-rf *.out *.o ./src/*.o  *.dSYM ./Gs/*.o
