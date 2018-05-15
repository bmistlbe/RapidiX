CC =g++ -g -m64 -fopenmp -O3 -std=c++11 -w


XS_FILES =$(patsubst ./XS/%.cpp, ./XS/%.o, $(wildcard ./XS/*.cpp))


SOURCE= ./src/CrossSection.o ./src/GlobalDefs.o ./src/Higgs.o ./src/Luminosity.o ./src/PDF.o ./src/Vegas.o ./src/Wilson.o


XSFILES= $(XS_FILES) 



RFLAGS = 
LOPENMP= -fopenmp 
LFLAGS = -lm -lLHAPDF 
LIB_FLAGS = -L/usr/local/lib
INC_FLAGS = -I/usr/local/include


%.out : %.o
	$(MAKE) -C ./src/
	$(MAKE) -C ./XS/
	$(CC) $(SOURCE) $(XSFILES) $<  -o $@ $(INC_FLAGS) $(LIB_FLAGS) $(LFLAGS) $(LOPENMP)


%.o : %.cpp
	$(CC) $(INC_FLAGS) $(LOPENMP) -c $< -o $@

%.s : src/%.cpp
	$(CC) $(INC_FLAGS) $(LOPENMP) -c $< -o $@.o
    

clean:
	rm	-rf *.out *.o *.dSYM ./src/*.o ./XS/*.o

cleansrc:
	rm 	-rf *.out *.o ./src/*.o  *.dSYM
